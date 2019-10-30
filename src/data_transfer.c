/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_transfer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 08:08:24 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/02 19:06:12 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "protocol_interpreter.h"
#include "../libft/include/libft.h"

#include "data_transfer.h"

static int run_data_server(void)
{
	struct sockaddr_in addr;
	int lsoc;

	do {
		lsoc = socket(AF_INET, SOCK_STREAM, 0);
		if (lsoc < 0)
			break;
		addr.sin_family = AF_INET;
		addr.sin_port = 0;
		addr.sin_addr.s_addr = INADDR_ANY;
		if (bind(lsoc, (struct sockaddr *)&addr, sizeof(addr)))
			break;
		if (listen(lsoc, 1) < 0)
			break;
		return lsoc;
	} while (0);
	close(lsoc);
	return -1;
}

static int manage_transfer(int lsoc, transfer_function func, const char *arg)
{
	struct sockaddr_in peer_addr;
	socklen_t addr_len;
	pid_t child;
	int csoc, status;

	child = fork();
	if (child == -1)
		return -1;
	else if (child == 0) {
		addr_len = sizeof(struct sockaddr_in);
		csoc = accept(lsoc, (struct sockaddr *)&peer_addr, &addr_len);
		if (csoc < 0 || func(csoc, arg) != 0)
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	} else {
		close(lsoc);
		wait4(child, &status, 0, NULL);
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
			return -1;
	}
	return 0;
}

static void close_data_server(int *lsoc) { close(*lsoc); } //check for 'run_data_server'

int data_transfer(int soc, const char *cmd, char *args, transfer_function func)
{
	int s, lsoc __attribute__((cleanup(close_data_server)));

	lsoc = run_data_server();
	if (lsoc == -1 || dtp_port(soc, lsoc) == -1)
		return -1;
	s = ftp_command(soc, cmd, args, "1");
	if (s != 0)
		return s;
	if (manage_transfer(lsoc, func, args) == -1)
		return -1;
	return recv_reply(soc, "2");
}

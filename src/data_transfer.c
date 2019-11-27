/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_transfer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 08:08:24 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 16:30:40 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <sys/types.h>
//#include <sys/socket.h>
#include <sys/wait.h>
//#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "protocol_interpreter.h"
#include "data_transfer.h"
#include "../libft/include/libft.h"

static void close_data_server(int *lsoc)
{
	close(*lsoc);
}

static int send_port(int csoc, int lsoc, int inet)
{
	int ret;

	if (inet == AF_INET6) {
		ret = dtp_eprt(csoc, lsoc);
		if (ret <= 0)
			return -1;
		if (ret == 2)
			return 0;
		printf("EPRT failed, try PORT\n");
	}
	ret = dtp_port(csoc, lsoc);
	if (ret <= 0)
		return -1;
	if (ret != 2)
		return 1;
	return 0;
}

static int manage_transfer(int lsoc, transfer_function func, const char *arg)
{
	struct sockaddr_in peer;
	socklen_t len;
	pid_t child;
	int csoc, status;

	child = fork();
	if (child == -1)
		return -1;
	else if (child == 0) {
		len = sizeof(struct sockaddr_in);
		csoc = accept(lsoc, (struct sockaddr *)&peer, &len);
		if (csoc < 0)
			exit(EXIT_FAILURE);
		if (func(csoc, arg) != 0)
			puts("Error while transfering data.");
		exit(EXIT_SUCCESS);
	} else {
		wait4(child, &status, 0, NULL);
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
			return -1;
	}
	return 0;
}

int data_transfer(int soc, const char *cmd, char *args, transfer_function func)
{
	int lsoc __attribute__((cleanup(close_data_server)));
	int s, ret, inet;

	lsoc = run_data_server();
	if (lsoc == -1)
		return -1;
	inet = (lsoc & INET6_BIT) ? AF_INET6 : AF_INET;
	lsoc &= ~INET6_BIT;
	ret = send_port(soc, lsoc, inet);
	if (ret != 0)
		return ret;
	s = ftp_command(soc, cmd, args, "1");
	if (s != 1)
		return s;
	if (manage_transfer(lsoc, func, args) == -1)
		return -1;
	return recv_reply(soc, "2");
}

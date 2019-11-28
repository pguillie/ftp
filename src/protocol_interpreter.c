/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol_interpreter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:28:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 16:00:20 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "protocol_interpreter.h"
#include "../libft/include/libft.h"

static int server_greetings(int soc)
{
	char *reply;

	if (read_line(soc, &reply) != 1)
		return 0;
	if (ft_strncmp(reply, "120", 3) == 0) {
		puts(reply);
		free(reply);
		if (read_line(soc, &reply) != 1)
			return 0;
	}
	if (ft_strncmp(reply, "220", 3) == 0) {
		puts(reply);
		free(reply);
		return 1;
	}
	free(reply);
	return 0;
}

static int pi_error(char *line)
{
	fprintf(stderr, "Critical error encountered. Exiting...\n");
	free(line);
	return 1;
}

int protocol_interpreter(int soc)
{
	ftp_cmd command;
	char *line, *arguments;
	int ret;

	if (!server_greetings(soc)) {
		puts("Service not recognized. Closing connection.");
		return 1;
	}
	ftp_user(soc, NULL);
	while ((ret = user_input(FTP_PROMPT, &line)) > 0) {
		if (set_command(line, &command, &arguments) != 0)
			puts("Invalid command.");
		else if (command(soc, arguments) < 0)
			return pi_error(line);
		free(line);
	}
	return (ret < 0) ? 1 : 0;
}

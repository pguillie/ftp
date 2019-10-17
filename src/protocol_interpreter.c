/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol_interpreter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:28:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/07 16:25:55 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "protocol_interpreter.h"

#include "../libft/include/libft.h"

//////
#include <stdio.h>

static int server_greetings(int soc)
{
	char *reply;

	if (read_line(soc, &reply) != 1)
		return 0;
	if (ft_strncmp(reply, "120", 3) == 0) {
		printf("%s\n", reply);
		free(reply);
		if (read_line(soc, &reply) != 1)
			return 0;
	}
	if (ft_strncmp(reply, "220", 3) == 0) {
		printf("%s\n", reply);
		free(reply);
		return 1;
	}
	free(reply);
	return 0;
}

int protocol_interpreter(int soc)
{
	char *line, *command, *arguments;
	int ret;

	if (!server_greetings(soc)) {
		puts("Service not recognized. Closing connection.");
		return 1;
	}
	ftp_user(soc, NULL);
	while ((ret = user_input(FTP_PROMPT, &line)) > 0) {
		command = ft_strtok(line, " ");
		arguments = ft_strtok(NULL, "");
//		printf("%s/ /%s\n", command, arguments);
		if (command && execute(soc, command, arguments) < 0)
			fprintf(stderr, "PI error\n");//die();
		free(line);
	}
	return (ret < 0) ? 1 : 0;
}

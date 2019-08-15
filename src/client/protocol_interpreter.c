/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol_interpreter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:28:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/15 12:09:19 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/protocol_interpreter.h"
#include "client/user_interface.h"

//////
#include <stdio.h>

static int server_greetings(int control)
{
	char *reply;

	ui_output("Awaiting server greetings...");
	recv_reply(control, &reply);
	if (!strncmp(reply, "120", 3)) {
		ui_reply(reply, "1");
		free(reply);
		recv_reply(control, &reply);
	}
	if (!strncmp(reply, "220", 3)) {
		ui_reply(reply, "2");
		free(reply);
		return (1);
	}
	free(reply);
	ui_output("Service not recognized, closing connection.");
	return (0);
}

int protocol_interpreter(int control)
{
	char *line, *command, *arguments;
	int ret;

	if (!server_greetings(control))
		return (1);
	ctrl_command(control, "SYST", NULL);
	while ((ret = ui_input(&line)) > 0) {
		command = ft_strtok(line, " ");
		arguments = ft_strtok(NULL, "\0");
//		printf("%s/ /%s\n", command, arguments);
		if (command && execute(control, command, arguments) < 0)
			fprintf(stderr, "PI\n");//die();
		free(line);
	}
	return (ret < 0 ? 1 : 0);
}

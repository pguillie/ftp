/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:35:56 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/15 12:05:07 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/protocol_interpreter.h"
#include "client/user_interface.h"

struct {
	const char *name;
	int (*f)(int, const char *, char *);
	const char *cmd;
} ftp_command[] = {
	{"user", &ctrl_command, "USER"},
	{"cd", &ctrl_command, "CWD"},
	{"quit", &ctrl_command, "QUIT"},
	{"type", &ctrl_command, "TYPE"},
	/* {"get", &data_command, "RETR"}, */
	/* {"put", &data_command, "STOR"}, */
	{"pwd", &ctrl_command, "PWD"},
	/* {"ls", &data_command, "LIST"}, */
	{"syst", &ctrl_command, "SYST"}
};

int execute(int control, const char *cmd, char *args)
{
	size_t i;

	i = sizeof(ftp_command) / sizeof(ftp_command[0]);
	while (strcmp(ftp_command[--i].name, cmd)) {
		if (i == 0) {
			ui_output("Invalid command.");
			return 1;
		}
	}
	return (ftp_command[i].f(control, ftp_command[i].cmd, args));
}

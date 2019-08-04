/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:35:56 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/04 10:45:24 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/protocol_interpreter.h"
#include "client/user_interface.h"

struct {
	const char *name;
	int (*f)(int, char *);
} ftp_command[] = {
	{"user", &user_name},
	/* {"cd", &change_working_directory}, */
	{"quit", &logout},
	/* {"type", &representation_type}, */
	/* {"get", &retrieve}, */
	/* {"put", &store}, */
	{"pwd", &print_working_directory},
	/* {"ls", &list} */
};

int execute(int control_sock, const char *cmd, char *args)
{
	size_t i;

	i = sizeof(ftp_command) / sizeof(ftp_command[0]);
	while (i--) {
		if (strcmp(ftp_command[i].name, cmd) == 0)
			return (ftp_command[i].f(control_sock, args));
	}
	ui_output("Invalid command.");
	return (1);
}

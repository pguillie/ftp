/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:35:56 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 17:14:38 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "protocol_interpreter.h"
#include "../libft/include/libft.h"

struct {
	const char *name;
	ftp_cmd fptr;
} command[] = {
	{"user", ftp_user},
	{"cd", ftp_cwd},
	{"quit", ftp_quit},
	{"type", ftp_type},
	{"get", ftp_retr},
	{"put", ftp_stor},
	{"pwd", ftp_pwd},
	{"ls", ftp_list},
	{"syst", ftp_syst}
};

int set_command(char *cmd_line, ftp_cmd *cmd, char **args)
{
	char *c;
	size_t i;

	c = ft_strtok(cmd_line, " ");
	if (c == NULL)
		return 1;
	i = sizeof(command) / sizeof(command[0]);
	while (i--) {
		if (ft_strcmp(command[i].name, c) == 0) {
			*cmd = command[i].fptr;
			*args = ft_strtok(NULL, "\0");
			return 0;
		}
	}
	return 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:35:56 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/02 18:47:07 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "protocol_interpreter.h"
#include "../libft/include/libft.h"

struct {
	const char *name;
	int (*func)(int soc, char *arg);
} ftp_cmd[] = {
	//{"user", &ftp_user},
	{"cd", ftp_cwd},
	{"quit", ftp_quit},
	{"type", ftp_type},
	{"get", ftp_retr},
	{"put", ftp_stor},
	{"pwd", ftp_pwd},
	{"ls", ftp_list},
	{"syst", ftp_syst}
};

int execute(int soc, const char *cmd, char *args)
{
	size_t i;

	i = sizeof(ftp_cmd) / sizeof(ftp_cmd[0]);
	while (i--)
		if (ft_strcmp(ftp_cmd[i].name, cmd) == 0)
			return ftp_cmd[i].func(soc, args);
	puts("Invalid command.");
	return 1;
}

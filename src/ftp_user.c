/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:02:05 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/08 07:37:05 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "protocol_interpreter.h"
#include "../libft/include/libft.h"

static int ftp_pass(int soc, char *pass, char *rep)
{
	char *input;
	int ret;

	if (!pass) {
		puts(rep);
		if (user_input("Password: ", &input) != 1) {
			free(rep);
			return -1;
		}
		pass = input;
	} else {
		input = NULL;
	}
	free(rep);
	ret = ftp_command(soc, "PASS", pass, "2");
	if (input)
		free(input);
	return ret;
}

int ftp_user(int soc, char *args)
{
	char *user, *rep;
	int ret;

	if (args != NULL)
		user = ft_strtok(args, " ");
	else if (user_input("Name: ", &user) != 1)
		return -1;
	if (send_command(soc, "USER", user) != 0
		|| read_line(soc, &rep) != 1)
		ret = -1;
	else
		ret = 0;
	if (args == NULL)
		free(user);
	if (ret == -1)
		return -1;
	rep[ft_strlen(rep) - 1] = '\0';
	if (ft_strncmp(rep, "331", 3) == 0)
		return ftp_pass(soc, args ? ft_strtok(NULL, "\0") : NULL, rep);
	ret = (ft_strncmp(rep, "230", 3) == 0) ? 0 : 1;
	puts(rep);
	free(rep);
	return ret;
}

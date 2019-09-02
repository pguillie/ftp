/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 11:50:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/15 12:06:28 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "protocol_interpreter.h"

int ui_input(char **line)
{
	write(1, "ftp> ", 5);
	return read_line(0, line);
}

int ui_output(const char *str)
{
	puts(str);
	return 0;
}

int ui_reply(const char *reply, const char *success)
{
	printf("%s (%s)\n", reply,
		ft_strchr(success, *reply) ? "SUCCESS" : "ERROR");
	return 0;
}

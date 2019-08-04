/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 11:50:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/07/31 12:09:48 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/protocol_interpreter.h"

int ui_input(char **line)
{
	write(1, "ftp> ", 5);
	return (read_line(0, line));
}

int ui_output(const char *str)
{
	char buf[128];
	size_t len;

	len = ft_strlen(str);
	while (len > sizeof(buf) - 1) {
		if (write(1, str, sizeof(buf)) < 0)
			return (-1);
		str += sizeof(buf);
		len -= sizeof(buf);
	}
	strcpy(buf, str);
	buf[len] = '\n';
	if (write(1, buf, len + 1))
		return (-1);
	return (0);
}

int ui_reply(const char *reply)
{
	char code;

	code = *reply;
	reply += 3;
	if (code == '1' || code == '2' || code == '3')
		write(1, "\e[32mSUCCESS\e[0m", 17);
	else
		write(1, "\e[31m*ERROR*\e[0m", 17);
	return (ui_output(reply));
}

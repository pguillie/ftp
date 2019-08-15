/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:22:52 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/15 08:32:03 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/protocol_interpreter.h"

struct sbuf {
	char buf[512];
	size_t i;
	int fd;
};

static int sbuf_out(struct sbuf *sb)
{
	if (send(sb->fd, sb->buf, sb->i, 0) < 0)
		return 1;
	sb->i = 0;
	return 0;
}

static int sbuf_in(struct sbuf *sb, const char *str)
{
	size_t i;

	i = 0;
	while (str[i]) {
		if (sb->i == sizeof(sb->buf) && sbuf_out(sb) != 0)
			return 1;
		sb->buf[sb->i++] = str[i++];
	}
	return 0;
}

int send_command(int control_sock, const char *cmd, const char *args)
{
	struct sbuf sb;

	sb.i = 0;
	sb.fd = control_sock;
	if (sbuf_in(&sb, cmd) != 0)
		return 1;
	if (args != NULL)
		if (sbuf_in(&sb, " ") != 0 || sbuf_in(&sb, args) != 0)
			return 1;
	if (sbuf_in(&sb, "\r\n") != 0)
		return 1;
	sbuf_out(&sb);
	return 0;
}

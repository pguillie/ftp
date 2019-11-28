/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:22:52 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 13:42:04 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stddef.h>

#include "protocol_interpreter.h"

struct sbuf {
	char buf[512];
	size_t index;
	int fd;
};

static int sbuf_out(struct sbuf *sb)
{
	if (send(sb->fd, sb->buf, sb->index, 0) < 0)
		return 1;
	sb->index = 0;
	return 0;
}

static int sbuf_in(struct sbuf *sb, const char *str)
{
	size_t i;

	i = 0;
	while (str[i]) {
		if (sb->index == sizeof(sb->buf) && sbuf_out(sb) != 0)
			return 1;
		sb->buf[sb->index++] = str[i++];
	}
	return 0;
}

int send_command(int soc, const char *cmd, const char *args)
{
	struct sbuf sb;

	sb.index = 0;
	sb.fd = soc;
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

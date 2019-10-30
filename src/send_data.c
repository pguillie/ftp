/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:49:01 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/01 12:06:08 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <unistd.h>

#include "data_transfer.h"

enum ftp_data_type data_type;

static int send_data_asc(int soc, int fd)
{
	char buf[1024], data[1024];
	ssize_t n;
	size_t i, j;
	int cr;

	cr = 0;
	i = 0;
	while ((n = read(fd, buf, sizeof(buf))) > 0) {
		j = 0;
		while (j < (size_t)n) {
			if (buf[j] == '\n' && !cr) {
				data[i++] = '\r';
				cr = 1;
			} else {
				data[i++] = buf[j++];
				cr = 0;
			}
			if (i == sizeof(data)) {
				if (send(soc, data, i, MSG_NOSIGNAL) < 0)
					return -1;
				i = 0;
			}
		}
	}
	if (n < 0 || ((i && send(soc, data, i, MSG_NOSIGNAL) < 0)))
		return -1;
	return 0;
}

static int send_data_bin(int soc, int fd)
{
	char buf[1024];
	ssize_t n;

	while ((n = read(fd, buf, sizeof(buf))) > 0) {
		if (send(soc, buf, n, MSG_NOSIGNAL) < 0)
			return -1;
	}
	if (n < 0)
		return -1;
	return 0;
}

int send_data(int soc, int fd)
{
	if (data_type == TYPE_ASCII)
		return send_data_asc(soc, fd);
	else
		return send_data_bin(soc, fd);
}

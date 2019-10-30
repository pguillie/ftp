/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 09:19:42 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/01 12:06:12 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <unistd.h>

#include "data_transfer.h"

enum ftp_data_type data_type;

static int recv_data_asc(int soc, int fd)
{
	char buf[1024], data[1024];
	ssize_t n;
	size_t i, j;
	int cr;

	cr = 0;
	i = 0;
	while ((n = recv(soc, data, sizeof(data), MSG_NOSIGNAL)) > 0) {
		j = 0;
		while (j < (size_t)n) {
			buf[(cr && data[j] != '\n' ? ++i : i)] = data[j];
			if (data[j++] == '\r') {
				cr = 1;
			} else {
				i++;
				cr = 0;
			}
			if (i == sizeof(buf)) {
				if (write(fd, buf, i) < 0)
					return -1;
				i = 0;
			}
		}
	}
	if (n < 0 || (i && write(fd, buf, i) < 0))
		return -1;
	return 0;
}

static int recv_data_bin(int soc, int fd)
{
	char buf[1024];
	ssize_t n;

	while ((n = recv(soc, buf, sizeof(buf), MSG_NOSIGNAL)) > 0) {
		if (write(fd, buf, n) < 0)
			return -1;
	}
	if (n < 0)
		return -1;
	return 0;
}

int recv_data(int soc, int fd)
{
	if (data_type == TYPE_ASCII)
		return recv_data_asc(soc, fd);
	else
		return recv_data_bin(soc, fd);
}

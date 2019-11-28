/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtp_port.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:42:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 14:00:20 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <stdlib.h>

#include "protocol_interpreter.h"
#include "../libft/include/libft.h"

static int get_addr(int csoc, int lsoc, struct sockaddr_in *addr)
{
	struct sockaddr_in addr_part[2];
	socklen_t addr_len;
	int i, soc[2];

	soc[0] = csoc;
	soc[1] = lsoc;
	i = 0;
	while (i < 2) {
		addr_len = sizeof(struct sockaddr_in);
		if (getsockname(soc[i], (struct sockaddr *)(addr_part + i),
				&addr_len) == -1)
			return -1;
		i++;
	}
	addr->sin_addr = addr_part[0].sin_addr;
	addr->sin_port = addr_part[1].sin_port;
	return 0;
}

static void set_host(char *buf, const char *host)
{
	char c;

	size_t i = 0;
	do {
		c = *host;
		*buf++ = (c == '.') ? ',' : c;
		i++;
	} while (*host++);
}

static void set_port(char *buf, int port)
{
	int i, d, p[2];

	while (*buf != '\0')
		buf++;
	p[0] = port / 256;
	p[1] = port % 256;
	i = 0;
	while (i < 2) {
		*buf++ = ',';
		d = 1;
		while (p[i] / (d * 10) > 0)
			d *= 10;
		while (d) {
			*buf++ = p[i] / d + '0';
			p[i] %= d;
			d /= 10;
		}
		i++;
	}
	*buf = '\0';
}

int dtp_port(int csoc, int lsoc)
{
	char buf[24];
	struct sockaddr_in addr;

	if (get_addr(csoc, lsoc, &addr) != 0)
		return -1;
	set_host(buf, inet_ntoa(addr.sin_addr));
	set_port(buf, ntohs(addr.sin_port));
	return ftp_command(csoc, "PORT", buf);
}

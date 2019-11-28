/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtp_eprt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:16:42 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 14:00:31 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>

#include "protocol_interpreter.h"
#include "../libft/include/libft.h"

static int get_addr(int csoc, int lsoc, struct sockaddr_in6 *addr)
{
	struct sockaddr_in6 addr_part[2];
	socklen_t addr_len;
	int i, soc[2];

	soc[0] = csoc;
	soc[1] = lsoc;
	i = 0;
	while (i < 2) {
		addr_len = sizeof(struct sockaddr_in6);
		if (getsockname(soc[i], (struct sockaddr *)(addr_part + i),
				&addr_len) == -1)
			return -1;
		i++;
	}
	addr->sin6_addr = addr_part[0].sin6_addr;
	addr->sin6_port = addr_part[1].sin6_port;
	return 0;
}

static void set_port(char *buf, int port)
{
	int d;

	d = 1;
	while (port / (d * 10) > 0)
		d *= 10;
	while (d) {
		*buf++ = port / d + '0';
		port %= d;
		d /= 10;
	}
	*buf = '\0';
}

int dtp_eprt(int csoc, int lsoc)
{
	char buf[128];
	struct sockaddr_in6 addr;
	size_t i;

	if (get_addr(csoc, lsoc, &addr) != 0)
		return -1;
	ft_memcpy(buf, "|2|", 3);
	inet_ntop(AF_INET6, (void *)&addr.sin6_addr, buf + 3, sizeof(buf) - 3);
	i = ft_strlen(buf);
	buf[i++] = '|';
	set_port(buf + i, ntohs(addr.sin6_port));
	i += ft_strlen(buf + i);
	buf[i++] = '|';
	buf[i] = '\0';
	return ftp_command(csoc, "EPRT", buf);
}

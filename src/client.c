/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:15:04 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 14:47:34 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <signal.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>

#include "client.h"
#include "protocol_interpreter.h"
#include "../libft/include/libft.h"

static int use_addr(struct addrinfo addr)
{
	int s;

	s = socket(addr.ai_family, addr.ai_socktype, addr.ai_protocol);
	if (s == -1)
		return -1;
	if (connect(s, addr.ai_addr, addr.ai_addrlen) == -1) {
		close(s);
		return -1;
	}
	return s;
}

static int connect_socket(struct addrinfo *rp)
{
	int sfd;

	if (rp == NULL)
		return -1;
	if (rp->ai_family == AF_INET6) {
		sfd = use_addr(*rp);
		if (sfd == -1)
			return connect_socket(rp->ai_next);
	} else {
		sfd = connect_socket(rp->ai_next);
		if (sfd == -1)
			return use_addr(*rp);
	}
	return sfd;
}

static int connect_service(const char *node, const char *service)
{
	struct addrinfo hints, *result;
	int sfd;

	ft_memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;
	hints.ai_flags = AI_NUMERICSERV;
	if (!service)
		service = "21";
	printf(ft_strchr(node, ':')
		? "Connecting to [%s]:%s...\n"
		: "Connecting to %s:%s...\n",
		node, service);
	if (getaddrinfo(node, service, &hints, &result) != 0)
		return -1;
	sfd = connect_socket(result);
	freeaddrinfo(result);
	return sfd;
}

int client(const char *host, const char *port)
{
	int soc;
	int ret;

	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
		printf("Error: failed to manage signals\n");
		return -1;
	}
	soc = connect_service(host, port);
	if (soc < 0) {
		printf("Unable to connect.\n");
		return (-1);
	}
	ret = protocol_interpreter(soc);
	close(soc);
	return (ret);
}

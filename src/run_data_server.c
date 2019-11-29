/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_data_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:37:26 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/29 18:32:23 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#include "data_transfer.h"
#include "../libft/include/libft.h"

static int use_addr(struct addrinfo addr)
{
	int s;

	do {
		s = socket(addr.ai_family, addr.ai_socktype, addr.ai_protocol);
		if (s == -1)
			break;
		if (bind(s, addr.ai_addr, addr.ai_addrlen))
			break;
		if (listen(s, 1) < 0)
			break;
		return s;
	} while (0);
	close(s);
	return -1;
}

static int find_interface(struct addrinfo *rp)
{
	int sfd = -1;

	if (rp == NULL)
		return -1;
	if (rp->ai_family == AF_INET6) {
		sfd = use_addr(*rp);
		if (sfd == -1)
			return find_interface(rp->ai_next);
	} else {
		sfd = find_interface(rp->ai_next);
		if (sfd == -1)
			return use_addr(*rp);
	}
	return sfd;
}

int run_data_server(void)
{
	struct addrinfo hints, *result;
	int sfd;

	ft_memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;
	hints.ai_flags = AI_PASSIVE | AI_NUMERICSERV;
	if (getaddrinfo(NULL, "0", &hints, &result) != 0)
		return -1;
	sfd = find_interface(result);
	freeaddrinfo(result);
	return sfd;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:15:04 by pguillie          #+#    #+#             */
/*   Updated: 2019/07/31 12:26:40 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/client.h"
#include "client/protocol_interpreter.h"

static int connect_server(const char *server, const char *port)
{
	int sock;
	struct sockaddr_in addr;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		fprintf(stderr, "Error: socket\n");
		return (-1);
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(ft_atoi(port));
	addr.sin_addr.s_addr = inet_addr(server);
	if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		fprintf(stderr, "Error: connect\n");
		return (-1);
	}
	return (sock);
}

int client(const char *server, const char *port)
{
	int sock;
	int ret;

	printf("Connecting to %s:%s...\n", server, port);
	sock = connect_server(server, port);
	if (sock < 0) {
		printf("Unable to connect.\n");
		return (-1);
	}
	printf("Connected!\n");
	ret = protocol_interpreter(sock);
	close(sock);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 07:57:28 by pguillie          #+#    #+#             */
/*   Updated: 2019/07/29 04:51:29 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int get_ftp_arg(int ac, char **av, char **ip, char **port)
{
	*ip = av[1];
	if (ac == 2 && (*port = ft_strchr(av[1], ':'))) {
		(*port)[0] = '\0';
		*port += 1;
		return (0);
	} else if (ac == 3) {
		*port = av[2];
		return (0);
	}
	fprintf(stderr,
		"Usage: %1$s server port\n"
		"       %1$s server:port\n",
		av[0]);
	return (1);
}

int main(int argc, char *argv[])
{
	char *ip, *port;

	if (get_ftp_arg(argc, argv, &ip, &port) != 0)
		return (1);
	return (client(ip, port));
}

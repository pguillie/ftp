/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 07:57:28 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 09:05:27 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "client.h"

int main(int argc, char *argv[])
{
	if (argc < 2 || argc > 3) {
		fprintf(stderr, "Usage: %s <hostname> [port]\n", argv[0]);
		return 1;
	}
	return client(argv[1], argv[2]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:37:11 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 13:59:06 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "protocol_interpreter.h"

int ftp_quit(int soc, char *args __attribute__((unused)))
{
	ftp_command(soc, "QUIT", NULL);
	close(soc);
	exit(EXIT_SUCCESS);
}

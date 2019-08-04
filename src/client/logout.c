/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:37:11 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/04 10:42:16 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/protocol_interpreter.h"

int logout(int control, char *args __attribute__((unused)))
{
	char *reply;

	send_command(control, "QUIT", NULL);
	recv_reply(control, &reply);
	ui_reply(reply);
	free(reply);
	close(control);
	exit(EXIT_SUCCESS);
}

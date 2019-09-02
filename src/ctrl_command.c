/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 08:29:39 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/15 12:08:47 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protocol_interpreter.h"

#include <stdio.h>//
int ctrl_command(int control, const char *cmd, char *args)
{
	char *reply;

	if (send_command(control, cmd, args) != 0)
		fprintf(stderr, "ERR ctrl_command 1\n");
	if (recv_reply(control, &reply) < 0)
		fprintf(stderr, "ERR ctrl_command 2\n");
	ui_reply(reply, "2");
	free(reply);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_working_directory.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:31:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/04 12:29:08 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/protocol_interpreter.h"

int print_working_directory(int control, char *args __attribute__((unused)))
{
	char *reply;

	send_command(control, "PWD", NULL);
	recv_reply(control, &reply); //secu
	ui_reply(reply);
	free(reply);
	return (0);
}

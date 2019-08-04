/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:45:40 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/04 10:47:03 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/protocol_interpreter.h"

int user_name(int control, char *args)
{
	char *reply;

	send_command(control, "USER", args);
	recv_reply(control, &reply);
	ui_reply(reply);
	free(reply);
	return (0);
}

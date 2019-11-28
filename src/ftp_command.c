/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:09:18 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 13:56:53 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protocol_interpreter.h"

int ftp_command(int soc, const char *cmd, const char *arg)
{
	if (send_command(soc, cmd, arg) != 0)
		return -1;
	return recv_reply(soc);
}

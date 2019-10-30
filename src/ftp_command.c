/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:09:18 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/02 18:53:06 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protocol_interpreter.h"

int ftp_command(int soc, const char *cmd, const char *arg, const char *success)
{
	if (send_command(soc, cmd, arg) != 0)
		return -1;
	return recv_reply(soc, success);
}

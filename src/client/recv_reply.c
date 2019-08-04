/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_reply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 05:39:05 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/04 10:29:13 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/protocol_interpreter.h"

int recv_reply(int control_sock, char **reply)
{
	int ret;

	/* multilines reply
	 * ...
	 */
	ret = read_line(control_sock, reply);
	(*reply)[ft_strlen(*reply) - 1] = '\0'; //tmp
	return (ret);
}

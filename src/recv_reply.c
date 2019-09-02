/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_reply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 05:39:05 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/15 08:33:03 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protocol_interpreter.h"

int recv_reply(int control, char **reply)
{
	int ret;

	/* multilines reply
	 * ...
	 */
	ret = read_line(control, reply);
	(*reply)[ft_strlen(*reply) - 1] = '\0'; //tmp
	return (ret);
}

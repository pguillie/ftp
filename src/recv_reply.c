/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_reply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 05:39:05 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/07 09:31:58 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "protocol_interpreter.h"
#include "../libft/include/libft.h"

/*
** RETURN VALUE
** [1-5] reply code
**    0  socket EOF
**   -1  error
*/

int recv_reply(int soc, const char *successes)
{
	char *rep;
	int ret;

	/* multilines reply
	 * ...
	 */
	ret = read_line(soc, &rep);
	if (ret != 1) // (ret == 0) => `rep' was not allocated?
		return ret;
	ret = *rep - '0';
	rep[ft_strlen(rep) - 1] = '\0';
	printf("%s (%s)\n", rep + 4,
		(ft_strchr(successes, *rep)) ? "SUCCESS" : "ERROR");
	free(rep);
	return ret;
}

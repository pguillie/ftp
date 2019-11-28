/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_syst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:49:06 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 13:59:20 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "protocol_interpreter.h"

int ftp_syst(int soc, char *arg __attribute__((unused)))
{
	return ftp_command(soc, "SYST", NULL);
}

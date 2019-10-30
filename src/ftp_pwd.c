/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:44:01 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/02 18:51:55 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "protocol_interpreter.h"

int ftp_pwd(int soc, char *arg __attribute__((unused)))
{
	return ftp_command(soc, "PWD", NULL, "2");
}

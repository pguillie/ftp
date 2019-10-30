/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_retr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:01:42 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/02 18:50:57 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_transfer.h"

int ftp_retr(int soc, char *args)
{
	return data_transfer(soc, "RETR", args, &dtp_retr);
}

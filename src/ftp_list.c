/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:04:48 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/02 18:52:09 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_transfer.h"

int ftp_list(int soc, char *args)
{
	return data_transfer(soc, "LIST", args, &dtp_list);
}

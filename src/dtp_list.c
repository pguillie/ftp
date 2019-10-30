/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtp_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 08:51:36 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/02 18:20:20 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_transfer.h"

int dtp_list(int soc, const char *arg __attribute__((unused)))
{
	return recv_data(soc, 1);
}

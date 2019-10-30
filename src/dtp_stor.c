/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtp_stor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:10:26 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/02 18:57:55 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "data_transfer.h"

int dtp_stor(int soc, const char *arg)
{
	int fd, ret;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return 1;
	ret = send_data(soc, fd);
	close(fd);
	return ret;
}

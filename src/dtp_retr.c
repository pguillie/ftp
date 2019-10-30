/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtp_retr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 09:32:17 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/02 18:20:53 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "data_transfer.h"

int dtp_retr(int soc, const char *arg)
{
	int fd, ret;

	fd = open(arg, O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		return 1;
	ret = recv_data(soc, fd);
	close(fd);
	return ret;
}

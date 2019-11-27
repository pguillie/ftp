/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_retr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:01:42 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 16:23:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "data_transfer.h"

static int valid_file(const char *file)
{
	int fd;

	fd = open(file, O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		return 0;
	close(fd);
	return 1;
}

int ftp_retr(int soc, char *args)
{
	if (!valid_file(args)) {
		puts("Unable to retrieve file locally.");
		return 1;
	}
	return data_transfer(soc, "RETR", args, &dtp_retr);
}

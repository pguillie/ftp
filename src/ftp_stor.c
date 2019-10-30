/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_stor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:05:49 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/06 15:10:00 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "data_transfer.h"

static int err(int fd, const char *msg)
{
	close(fd);
	puts(msg);
	return 1;
}

int ftp_stor(int soc, char *args)
{
	int fd;
	struct stat buf;

	fd = open(args, O_RDONLY);
	if (fd == -1)
		return err(fd, "Failed to open file");
	if (fstat(fd, &buf) == -1)
		return err(fd, "Failed to stat file");
	if (!S_ISREG(buf.st_mode))
		return err(fd, "Unable to send file: not a regular file.");
	close(fd);
	return data_transfer(soc, "STOR", args, &dtp_stor);
}

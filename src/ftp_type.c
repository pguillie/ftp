/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:34:47 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 14:53:50 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "protocol_interpreter.h"
#include "data_transfer.h"
#include "../libft/include/libft.h"

enum ftp_data_type data_type = TYPE_ASCII;

int ftp_type(int soc, char *args)
{
	char *code;
	int ret;

	if (args == NULL) {
		if (data_type == TYPE_ASCII)
			puts("Current type is ASCII.");
		else
			puts("Current type is IMAGE.");
		return 0;
	}
	if (ft_strcmp(args, "image") == 0 || ft_strcmp(args, "binary") == 0) {
		code = "I";
	} else if (ft_strcmp(args, "ascii") == 0) {
		code = "A";
	} else {
		puts("type [ ascii | image ]");
		return 1;
	}
	ret = ftp_command(soc, "TYPE", code, "2");
	if (ret == 2)
		data_type = (*code == 'A') ? TYPE_ASCII : TYPE_IMAGE;
	return ret;
}

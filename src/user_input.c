/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 11:50:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/06 16:26:23 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "../libft/include/libft.h"

int user_input(char **line)
{
	write(1, "ftp> ", 5);
	return read_line(0, line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 11:50:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/07 07:11:07 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "../libft/include/libft.h"

int user_input(const char *prompt, char **line)
{
	write(1, prompt, ft_strlen(prompt));
	return read_line(0, line);
}

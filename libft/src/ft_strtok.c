/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 07:27:39 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/04 12:45:08 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtok(char *str, const char *delim)
{
	static char *start;
	char *token;

	if (str != NULL)
		start = str;
	while (*start && ft_strchr(delim, *start))
		start++;
	if (*start == '\0')
		return (NULL);
	token = start;
	while (*start && !ft_strchr(delim, *start))
		start++;
	if (*start != '\0')
		*start++ = '\0';
	return (token);
}

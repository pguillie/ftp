/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 05:34:46 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/15 09:18:29 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INTERFACE_H
# define USER_INTERFACE_H

# include <unistd.h>

# include "../libft/include/libft.h"

int ui_input(char **line);
int ui_output(const char *msg);
int ui_reply(const char *reply, const char *success);

#endif /* USER_INTERFACE_H */

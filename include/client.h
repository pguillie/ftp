/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:24:48 by pguillie          #+#    #+#             */
/*   Updated: 2019/07/29 04:51:09 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/socket.h>
# include <sys/wait.h>
# include <arpa/inet.h>
# include <stdio.h>

# include "../libft/include/libft.h"

int client(const char *server, const char *port);

#endif /* CLIENT_H */

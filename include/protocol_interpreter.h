/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol_interpreter.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:26:20 by pguillie          #+#    #+#             */
/*   Updated: 2019/08/15 12:05:52 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOCOL_INTERPRETER_H
# define PROTOCOL_INTERPRETER_H

# include <sys/socket.h>

# include "../libft/include/libft.h"
# include "user_interface.h"

int protocol_interpreter(int control_sock);

int recv_reply(int control_sock, char **reply);
int send_command(int control_sock, const char *cmd, const char *args);

int execute(int control_sock, const char *command, char *arguments);
int ctrl_command(int control, const char *command, char *arguments);

#endif /* PROTOCOL_INTERPRETER_H */

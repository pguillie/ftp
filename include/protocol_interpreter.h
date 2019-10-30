/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol_interpreter.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:26:20 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/02 18:54:07 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOCOL_INTERPRETER_H
# define PROTOCOL_INTERPRETER_H

//# include "data_transfer.h"

int protocol_interpreter(int soc);

int send_command(int soc, const char *cmd, const char *args);
int recv_reply(int soc, const char *successes);

int execute(int soc, const char *cmd, char *args);
int user_input(char **line);

int ftp_command(int soc, const char *cmd, const char *args, const char *success);

int ftp_cwd(int soc, char *arg);
int ftp_quit(int soc, char *arg);
int ftp_type(int soc, char *arg);
int ftp_retr(int soc, char *arg);
int ftp_stor(int soc, char *arg);
int ftp_pwd(int soc, char *arg);
int ftp_list(int soc, char *arg);
int ftp_syst(int soc, char *arg);

#endif /* PROTOCOL_INTERPRETER_H */

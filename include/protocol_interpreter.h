/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol_interpreter.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:26:20 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/28 13:56:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOCOL_INTERPRETER_H
# define PROTOCOL_INTERPRETER_H

# define FTP_PROMPT "ftp> "

typedef int (*ftp_cmd)(int soc, char *arg);

int protocol_interpreter(int soc);

int user_input(const char *prompt, char **line);
int set_command(char *cmd_line, ftp_cmd *cmd, char **args);

int send_command(int soc, const char *cmd, const char *args);
int recv_reply(int soc);

int login(int soc, char *args);

int ftp_command(int soc, const char *cmd, const char *args);

int ftp_user(int soc, char *arg);
int ftp_cwd(int soc, char *arg);
int ftp_quit(int soc, char *arg);
int ftp_type(int soc, char *arg);
int ftp_retr(int soc, char *arg);
int ftp_stor(int soc, char *arg);
int ftp_pwd(int soc, char *arg);
int ftp_list(int soc, char *arg);
int ftp_syst(int soc, char *arg);

#endif /* PROTOCOL_INTERPRETER_H */

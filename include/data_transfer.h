/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_transfer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 09:06:16 by pguillie          #+#    #+#             */
/*   Updated: 2019/11/29 18:32:40 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TRANSFER_H
# define DATA_TRANSFER_H

typedef int (*transfer_function)(int soc, const char *arg);

enum ftp_data_type {
	TYPE_ASCII,
	TYPE_IMAGE
};

int data_transfer(int soc, const char *cmd, char *args, transfer_function func);
int run_data_server(void);

int send_data(int soc, int fd);
int recv_data(int soc, int fd);

int dtp_port(int soc, int lsoc);
int dtp_eprt(int soc, int lsoc);
int dtp_retr(int soc, const char *arg);
int dtp_stor(int soc, const char *arg);
int dtp_list(int soc, const char *arg);

extern enum ftp_data_type data_type;

#endif /* DATA_TRANSFER_H */

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 18:46:54 by pguillie          #+#    #+#              #
#    Updated: 2019/08/15 11:27:47 by pguillie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SERVER	= ftpd
CLIENT	= ftp
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -I$(incdir)

LIBFT	= libft/libft.a

incdir = ./include/
srcdir = ./src/

# server

server_hdr = $(addprefix server/,		\
	protocol_interpreter.h			\
	ftp_command.h				\
	ftp_reply.h				\
)

server_src = $(addprefix server/,			\
	main.c						\
	server.c					\
	$(addprefix protocol_interpreter/,		\
		protocol_interpreter.c			\
		execute.c				\
		recv_command.c				\
		send_reply.c				\
		die.c					\
		$(addprefix ftp_command/,		\
			user_name.c			\
			change_working_directory.c	\
			logout.c			\
			data_port.c			\
			representation_type.c		\
			retrieve.c			\
			store.c				\
			print_working_directory.c	\
			list.c				\
			system_type.c			\
			noop.c				\
		)					\
	)						\
	$(addprefix data_transfer_process/,		\
		data_transfer_process.c			\
		dtp_retr.c				\
		dtp_stor.c				\
		dtp_list.c				\
		recv_data.c				\
		send_data.c				\
	)						\
)

server_obj = $(addprefix $(srcdir), $(server_src:%.c=%.o))

# client

client_hdr = $(addprefix client/,		\
	protocol_interpreter.h			\
	user_interface.h			\
)

client_src = $(addprefix client/,		\
	main.c					\
	client.c				\
	protocol_interpreter.c			\
	user_interface.c			\
	execute.c				\
	ctrl_command.c				\
	send_command.c				\
	recv_reply.c				\
)

client_obj = $(addprefix $(srcdir), $(client_src:%.c=%.o))

# rules

.PHONY: all server clean fclean re

all: server client

server: $(SERVER)

$(SERVER): $(LIBFT) $(server_obj)
	$(CC) -o $@ $^ -L$(dir $(LIBFT)) -lft

$(server_obj): $(addprefix $(incdir), $(server_hdr))

client: $(CLIENT)

$(CLIENT): $(LIBFT) $(client_obj)
	$(CC) -o $@ $^ -L$(dir $(LIBFT)) -lft

$(client_obj): $(addprefix $(incdir), $(client_hdr))

$(LIBFT):
	make -C $(dir $(LIBFT))

clean:
	make -C $(dir $(LIBFT)) fclean
	$(RM) $(server_obj) $(client_obj)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

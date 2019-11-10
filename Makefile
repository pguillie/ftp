#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 18:46:54 by pguillie          #+#    #+#              #
#    Updated: 2019/11/26 19:56:43 by pguillie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= ftp
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -I$(incdir) $(DEBUG)

LIBFT	= libft/libft.a

incdir = ./include/
srcdir = ./src/

# client

headers =					\
	client.h				\
	protocol_interpreter.h			\
	data_transfer.h				\

sources =					\
	main.c					\
	client.c				\
	protocol_interpreter.c			\
	user_input.c				\
	execute.c				\
	ftp_user.c				\
	ftp_cwd.c				\
	ftp_quit.c				\
	ftp_type.c				\
	ftp_retr.c				\
	ftp_stor.c				\
	ftp_pwd.c				\
	ftp_list.c				\
	ftp_syst.c				\
	data_transfer.c				\
	run_data_server.c			\
	dtp_port.c				\
	dtp_eprt.c				\
	dtp_retr.c				\
	dtp_stor.c				\
	dtp_list.c				\
	ftp_command.c				\
	send_command.c				\
	recv_reply.c				\
	send_data.c				\
	recv_data.c				\

objects = $(addprefix $(srcdir), $(sources:%.c=%.o))

# rules

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(objects)
	$(CC) -o $@ $^ -L$(dir $(LIBFT)) -lft $(DEBUG)

$(objects): $(addprefix $(incdir), $(headers))

$(LIBFT):
	make -C $(dir $(LIBFT))

debug:
	make re DEBUG='-fsanitize=address'

clean:
	make -C $(dir $(LIBFT)) fclean
	$(RM) $(objects)

fclean: clean
	$(RM) $(NAME)

re: fclean all

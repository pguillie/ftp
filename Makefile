#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 18:46:54 by pguillie          #+#    #+#              #
#    Updated: 2019/09/03 09:35:04 by pguillie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= ftp
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -I$(incdir)

LIBFT	= libft/libft.a

incdir = ./include/
srcdir = ./src/

# client

headers =					\
	protocol_interpreter.h			\
	user_interface.h			\

sources =					\
	main.c					\
	client.c				\
	protocol_interpreter.c			\
	user_interface.c			\
	execute.c				\
	ctrl_command.c				\
	send_command.c				\
	recv_reply.c				\

objects = $(addprefix $(srcdir), $(sources:%.c=%.o))

# rules

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(objects)
	$(CC) -o $@ $^ -L$(dir $(LIBFT)) -lft

$(objects): $(addprefix $(incdir), $(headers))

$(LIBFT):
	make -C $(dir $(LIBFT))

clean:
	make -C $(dir $(LIBFT)) fclean
	$(RM) $(objects)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 18:46:54 by pguillie          #+#    #+#              #
#    Updated: 2019/05/10 17:09:34 by pguillie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SERVER	= ftpd
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -I$(incdir)

incdir = ./include/
srcdir = ./src/

# server #

server_hdr = $(addprefix server/, \
	server.h \
	replies.h \
)

server_src = $(addprefix server/, \
	main.c \
	server.c \
	protocol_interpreter.c \
	reply.c \
	read_line.c \
)

server_obj = $(addprefix $(srcdir), $(server_src:%.c=%.o))

# rules #

.PHONY: all server clean fclean re

all: server

server: $(SERVER)

$(SERVER): $(server_obj)
	$(CC) -o $@ $^

$(server_obj): $(addprefix $(incdir), $(server_hdr))

clean:
	$(RM) $(server_obj)

fclean: clean
	$(RM) $(SERVER)

re: fclean all

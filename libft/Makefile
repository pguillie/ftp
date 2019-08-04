#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 04:54:10 by pguillie          #+#    #+#              #
#    Updated: 2019/08/02 05:14:23 by pguillie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	:= libft.a
CC	:= gcc
AS	:= nasm
AR	:= ar

CFLAGS	= -Wall -Werror -Wextra -I$(incdir)
ASFLAGS	= -f$(arch)
ARFLAGS	= cr

os != uname
ifeq ($(os), Linux)
	arch := elf64
	ARFLAGS += -U
else
	arch := macho64
	ASFLAGS += --prefix _
endif

incdir := ./include/
srcdir := ./src/

hdr = libft.h libfts.h ft_ctype.h

obj = $(addprefix $(srcdir),			\
	$(addprefix ctype/,			\
		ft_ctype.o			\
		ft_isalnum.o			\
		ft_isalpha.o			\
		ft_isascii.o			\
		ft_isblank.o			\
		ft_iscntrl.o			\
		ft_isdigit.o			\
		ft_isgraph.o			\
		ft_islower.o			\
		ft_isprint.o			\
		ft_ispunct.o			\
		ft_isspace.o			\
		ft_isupper.o			\
		ft_isxdigit.o			\
	)					\
	ft_atoi.o				\
	ft_bzero.o				\
	ft_cat.o				\
	ft_memchr.o				\
	ft_memcmp.o				\
	ft_memcpy.o				\
	ft_memmem.o				\
	ft_memmove.o				\
	ft_memset.o				\
	ft_putchar.o				\
	ft_puts.o				\
	ft_strcat.o				\
	ft_strchr.o				\
	ft_strcmp.o				\
	ft_strdup.o				\
	ft_strlen.o				\
	ft_strndup.o				\
	ft_strtok.o				\
	ft_tolower.o				\
	ft_toupper.o				\
	read_line.o				\
)

# rules

.PHONY: all clean fclean re
.SECONDARY: $(obj)

all: $(NAME)

$(NAME): $(NAME)($(obj))
	ranlib $@

$(obj): $(addprefix $(incdir), $(hdr))

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(NAME)

re: fclean all

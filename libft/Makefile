# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmbatha <mmbatha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 12:31:42 by mmbatha           #+#    #+#              #
#    Updated: 2018/08/24 17:15:20 by mmbatha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH =	srcs
SRC_NAME =	ft_memset.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strcat.c \
			ft_strchr.c	ft_isspace.c ft_atoi.c ft_memalloc.c ft_memcpy.c \
			ft_memdel.c	ft_strdel.c	ft_strnew.c	ft_strjoin.c ft_putchar.c \
			ft_putstr.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c	\
			ft_linelen.c ft_putendl_fd.c ft_countlines.c get_next_line.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)
HEADER = includes/libft.h
HEADERFLAGS = $(addprefix -I , $(HEADER))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: obj $(NAME)

obj:
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(HEADERFLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf $(OBJ_PATH)
	
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

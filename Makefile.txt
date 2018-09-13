# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmbatha <mmbatha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 13:21:40 by mmbatha           #+#    #+#              #
#    Updated: 2018/08/25 11:45:45 by mmbatha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

PATH_SRC = ./srcs
PATH_INC = ./includes
PATH_OBJ = ./objs

SRCS = cast_ray.c error.c keyhook.c textures.c main.c parse_map.c draw.c\
		headsup.c

OBJS = $(patsubst %.c,%.o,$(addprefix $(PATH_OBJ)/, $(SRCS)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

PATH_LFT = ./libft
LIB_LFT = $(addprefix $(PATH_LFT)/,libft.a)
INC_LFT = -I $(PATH_LFT)
LNK_LFT = -L $(PATH_LFT) -l ft

all: obj $(LIB_LFT) $(NAME)

obj:
	mkdir -p $(PATH_OBJ)

$(PATH_OBJ)/%.o:$(PATH_SRC)/%.c
	$(CC) $(CFLAGS) $(INC_LFT) -I $(PATH_INC) -o $@ -c $<

$(LIB_LFT):
	make -C $(PATH_LFT)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LNK_LFT) -lmlx -framework OpenGL -framework AppKit

clean:
	make -C $(PATH_LFT) clean
	/bin/rm -rf $(PATH_OBJ)

fclean: clean
	make -C $(PATH_LFT) fclean
	/bin/rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 07:24:22 by mboukhal          #+#    #+#              #
#    Updated: 2022/08/24 09:29:05 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL		= run

NAME				= cub3d

OPTION				= -Wall -Wextra -Werror
INCLUDES			= -I /usr/local/include -I includes/ -lmlx \
					  -L /usr/local/lib/ -framework OpenGL -framework AppKit
UTILS				= src/utils/
CFILES				= src/main.c $(UTILS)ft_putstr_fd.c $(UTILS)ft_strlen.c \
					  src/checks.c $(UTILS)ft_strncmp.c $(UTILS)alloc.c 	\
					  src/game_entry.c src/key_manip.c src/init.c

OBJ					= $(CFILES:.c=.o)

.c.o:
	@ $(CC) $(OPTION) -c $< -o $@

$(NAME): $(OBJ)
	@ $(CC) $(OBJ) $(INCLUDES) -o $(NAME)

all: $(NAME)

clean:
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

run: all clean
	@ ./$(NAME) maps/map1.cub

.PHONY: re fclean all clean
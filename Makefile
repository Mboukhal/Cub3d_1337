# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 07:24:22 by mboukhal          #+#    #+#              #
#    Updated: 2022/09/02 22:19:20 by ahmaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.DEFAULT_GOAL		= run

NAME				= cub3d

OPTION				= -Wall -Wextra -Werror

S					= src/

INCLUDES			= -I /usr/local/include -I includes/ -lmlx -I $(s)libft/ 	\
					  -L /usr/local/lib/ -framework OpenGL					\
					  -framework AppKit


CFILES				= $(S)main.c $(S)checks.c $(S)alloc.c $(S)key_manip.c 	\
					  $(S)init.c $(S)game_entry.c $(S)get_next_line/get_next_line_utils.c \
					  $(S)get_next_line/get_next_line.c $(S)get_texture_color.c $(S)free_it.c $(S)affiche_cub.c

OBJ					= $(CFILES:.c=.o)

LIB_EXT_MAKE 		= make $@ -C $(S)libft

.c.o:
	@ $(CC) $(OPTION) -c $< -o $@

$(NAME): $(OBJ)
	@ make -C $(S)libft
	@ $(CC) $(OBJ) $(INCLUDES) $(S)libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	@ $(LIB_EXT_MAKE)
	@ $(RM) $(OBJ)

fclean: clean
	@ $(LIB_EXT_MAKE)
	@ $(RM) $(NAME)

re: fclean all

#run: all clean
	#@ reset
	#@ ./$(NAME) maps/map1.cub.cub
	#@ rm -rf .vscode

.PHONY: re fclean all clean
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 07:24:22 by mboukhal          #+#    #+#              #
#    Updated: 2022/09/08 18:46:27 by ahmaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL		= all

NAME				= cub3d

OPTION				= -Wall -Wextra -Werror #-fsanitize=address 

S					= src/

INCLUDES			= -I /usr/local/include -I includes/ -lmlx -I $(s)libft/ 	\
					  -L /usr/local/lib/ -framework OpenGL					\
					  -framework AppKit


CFILES				= $(S)main.c $(S)parsing/checks.c $(S)parsing/alloc.c $(S)key_manip.c 	\
					  $(S)parsing/init.c $(S)game_entry.c $(S)get_next_line/get_next_line_utils.c \
					  $(S)get_next_line/get_next_line.c $(S)parsing/get_texture_color.c $(S)parsing/free_it.c $(S)parsing/affiche_cub.c \
					  $(S)parsing/parsing_utils_2.c $(S)parsing/parsing_utils_1.c $(S)parsing/transform_map.c $(S)parsing/valid_map.c $(S)parsing/check_str.c

OBJ					= $(CFILES:.c=.o)

LIB_EXT_MAKE 		= make $@ -C $(S)libft

.c.o:
	@ $(CC) -c $< -o $@

$(NAME): $(OBJ)
	@ make -C $(S)libft
	@ $(CC) $(OPTION) $(OBJ) $(INCLUDES) $(S)libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	@ $(LIB_EXT_MAKE)
	@ $(RM) $(OBJ)

fclean: clean
	@ $(LIB_EXT_MAKE)
	@ $(RM) $(NAME)

re: fclean all

run: all clean
	@ reset
	@ ./$(NAME) maps/map1.cub
	@ rm -rf .vscode
	@# echo 'for leaks >> while :; do leaks $(NAME); sleep 2; done [and add while(1) in last of main];'

.PHONY: re fclean all clean
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 07:24:22 by mboukhal          #+#    #+#              #
#    Updated: 2022/10/09 15:50:10 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL		= all

NAME				= cub3d

OPTION				= -Wall -Wextra -Werror -g -fsanitize=address 

S					= src/
P					= $(S)parsing/
T					= test/drow_mini.c


INCLUDES			= -I /usr/local/include -I includes/ -lmlx -I $(s)libft/ 	\
					  -L /usr/local/lib/ -framework OpenGL					\
					  -framework AppKit


CFILES				= $(S)main.c $(P)checks.c $(P)alloc.c $(S)key_manip.c $(S)drow_minimap.c $(T) \
					  $(P)init.c $(S)game_entry.c $(S)get_next_line/get_next_line_utils.c $(S)drow.c\
					  $(S)get_next_line/get_next_line.c $(P)get_texture_color.c $(P)free_it.c $(P)affiche_cub.c \
					  $(P)parsing_utils_2.c $(P)parsing_utils_1.c $(P)transform_map.c $(P)valid_map.c $(P)check_str.c \
					  $(S)key_func.c $(S)drow_rays.c $(S)rays_calc.c $(S)rays_rander.c %(S)3d_pjection.c

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:28:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/08 16:33:54 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include "utils.h"

# define UP_KEY			13
# define DOWN_KEY		1
# define RIGHT_KEY		2
# define LEFT_KEY		0
# define EXIT_BOTTON	17
# define ELEMENT_SIZE	32

typedef enum s_type
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CIEL
}	t_type;

typedef struct s_txt_c
{
	t_type	type;
	char	**splt;
}	t_txt_c;

typedef struct s_cub
{
	int		i;
	void	*mlx;
	void	*mlx_win;
	t_txt_c	*tab_txt_c;
	int		size_tab;
	char	**map;
	int		size_map;
	int		in_map;
}	t_cub;

t_cub	*cub_init(void);
int		deal_key(int key, t_cub *cub);
int		exit_game(t_cub *cub);
void	check_exteniton(char *file);
t_cub	*map_init(char *file);
void	start_game(t_cub *cub);
int		parser_file(int fd, t_cub **cub);
int		find_texture_or_colors(char *str, t_cub **cub);
int		get_texture(char *str, t_cub **cub, int i);
int		get_color(char *str, t_cub **cub, int i);
void	free_it_split(char **s);
void	free_cub(t_cub *cub);
void	affiche_cub(t_cub *cub);
void	allocate(t_cub **cub, char **str, int type);
void	remove_last_nl(t_cub **cub);
int		check_up_down_walls(char *s1, char *s2);
int		check_walls(char **map, int size);
int		find_texture_or_colors(char *str, t_cub **cub);
void	ft_error(void);
int		check_charactre(char *str);
void	remove_last_spaces(char **str);
void	filling_map(t_cub **cub, char *str);
void	add_plus(t_cub **cub, int j);
void	add_front_plus(t_cub **cub);
void	add_back_plus(t_cub **cub);
void	add_back(t_cub **cub, int len);
int		check(char c);
int		check_around_zero(t_cub **cub);
void	check_map(t_cub **cub);
void	check_str_valid(char *str);
void	check_nbr_vrg(char *str);
// void	key_right(cub);
// void	key_left(cub);
// void	key_down(cub);
// void	key_up(cub);

#endif /* __CUB_H__ */
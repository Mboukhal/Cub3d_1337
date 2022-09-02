/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:28:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/02 22:17:18 by ahmaidi          ###   ########.fr       */
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

typedef enum s_type
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CIEL,
	MAP
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
}	t_cub;

int		deal_key(int key, t_cub *cub);
int		exit_game(t_cub *cub);
void	init(t_cub *cub);
void	check_exteniton(char *file);
void	map_init(char *file, t_cub *cub);
void	start_game(t_cub *cub);
int		parser_file(int fd, t_cub **cub);
int		find_texture_or_colors(char *str, t_cub **cub);
int		get_texture(char *str, t_cub **cub, int i);
int		get_color(char *str, t_cub **cub, int i);
void	free_it_split(char **s);
void	free_cub(t_cub *cub);
void	affiche_cub(t_cub *cub);
// void	key_right(cub);
// void	key_left(cub);
// void	key_down(cub);
// void	key_up(cub);

#endif /* __CUB_H__ */
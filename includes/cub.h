/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:28:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/08 16:57:57 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "utils.h"

#define FALSE			0
#define TRUE			1

# define PI 			3.14159265
# define TWO_PI 		6.28318530
# define NUM_RAYS		150
# define FOV_ANGLE		(60 * (PI / 180))	
# define TILE_SIZE		20

// # define DX				115
// # define DY				106

# define LOG(x, s)		printf("%s:\t\t[%d]\n", s, x);
# define LOGF(x, s)		printf("%s:\t\t[%f]\n", s, x);
# define LOGC(c, msg)	printf("%s:\t\t[%c]\n", msg, c);

typedef enum s_type
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CIEL
}	t_type;

typedef struct s_ray
{
	float 	ray_angle;
	// float 	wall_hit_x;
	// float 	wall_hit_y;
	float 	distance;
	int		was_hit_vertical;
	int		is_ray_facing_no;
	int		is_ray_facing_so;
	int		is_ray_facing_we;
	int		is_ray_facing_ea;
	// int		wall_hit_content;

}	t_ray;

typedef struct s_image
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	void	*empty;
	void	*wall;
	void	*tmplet;
	void	*bg;
	char	**f;
	char	**c;

}	t_image;

typedef struct s_player{
	float	player_x;
	float	player_y;
	int		turndirection;
	int		walkdirection;
	float	turnleft;
	float	rotationangle;
	float	walkspeed;
	float	turnspeed;
}	t_player;

typedef struct s_txt_c
{
	t_type	type;
	char	**splt;
	int		cc[4];
	int		cf[4];
}	t_txt_c;

typedef struct s_cub
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		*bf;
	t_txt_c		*tab_txt_c;
	t_image		*image;
	t_player	*player;
	t_ray		ray[NUM_RAYS];
	float		px;
	float		py;
	int			i;
	int			size_tab;
	char		side_of_player;
	char		playerside;
	int			bf_in;
	int			key_minimap;
	int			flor_trgb[4];
	int			ceill_trgb[4];
	int			size_map;
	int			s_map[2];
	int			in_map;
	int			is_player;
	void		*layer1;
	char		*layer1_buffer;
	int			size_line;
}	t_cub;

t_cub	*cub_init(void);
int		deal_key(int key, t_cub *cub);
int		exit_game(t_cub *cub);
void	init(t_cub *cub);
void	check_exteniton(char *file, char *str);
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
int		check_charactre(char *str, t_cub **cub);
void	remove_last_spaces(char **str);
void	filling_map(t_cub **cub, char *str);
void	add_plus(t_cub **cub, int j);
void	add_front_plus(t_cub **cub);
void	add_back_plus(t_cub *cub);
void	add_back(t_cub **cub, int len);
int		check(char c);
int		check_around_zero(t_cub **cub);
void	check_map(t_cub **cub);
void	check_str_valid(char *str);
void	check_nbr_vrg(char *str);
int		wrong_color(void);
void	create_trgb(int *rgb, int *color);
void	side_of_player(t_cub *cub);

#endif /* __CUB_H__ */
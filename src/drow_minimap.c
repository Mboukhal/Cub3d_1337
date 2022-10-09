/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/09 17:50:56 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

// int	draw_l(t_cub *cub, int begin_x, int begin_y, int color)
int	draw_line(t_cub *cub, int begin_x, int begin_y, int end_x, int end_y, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = end_x - begin_x;
	delta_y = end_y - begin_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = begin_x;
	pixel_y = begin_y;
	while (pixels)
	{
		mlx_pixel_put(cub->mlx, cub->mlx_win, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
	return (0);
}

int	is_it_hitt_wall(t_cub *cub, float x, float y)
{
	int	index_x;
	int	index_y;

	index_y = floor(y / TILE_SIZE);
	index_x = floor(x / TILE_SIZE);
	if (index_y < 0 || index_y < 0)
		return (0);
	if (cub->map[index_y][index_x] != '0' && cub->map[index_y][index_x] != 'N'
		&& cub->map[index_y][index_x] != 'S' && cub->map[index_y][index_x] != 'W'
		&& cub->map[index_y][index_x] != 'E')
		return (1);
	return (0);
}

static void	set_player(t_cub *cub)
{
	int	player_size;
	int	player_color;
	int	i[2];
	int	r;

	player_size = 2;
	player_color = 11605993;
	i[0] = -1;
	while (++i[0] < player_size)
	{
		i[1] = -1;
		while (++i[1] < player_size)
		{
			r = i[0] + 3;
			mlx_pixel_put(cub->mlx, cub->mlx_win,
			cub->px + i[0] ,
			cub->py + i[1] , player_color);
		}
	}
	// cub->px = cub->px;
	// cub->py = cub->py;
}

static void	set_player_info(t_cub *cub, int *coord_i)
{
	cub->playerside = cub->map[coord_i[1]][coord_i[0]];
	if (!cub->px && !cub->py)
	{
		// cub->px = TILE_SIZE * coord_i[0];
		// cub->py = TILE_SIZE * coord_i[1];
		cub->px = TILE_SIZE * coord_i[0];
		cub->py = TILE_SIZE * coord_i[1];
	}
	if (cub->key_minimap)
		mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty,
			TILE_SIZE * coord_i[0], TILE_SIZE * coord_i[1]);
}

void	set_map(t_cub *cub, int mode)
{
	int		coord_i[2];

	coord_i[0] = -1;
	while (++coord_i[0] < cub->s_map[0])
	{
		coord_i[1] = -1;
		while (++coord_i[1] < cub->s_map[1])
		{
			if (mode)
			{
				if (cub->map[coord_i[1]][coord_i[0]] == '0' && cub->key_minimap )
					put_image(cub, coord_i, 1);
				else if (cub->map[coord_i[1]][coord_i[0]] == '1' && cub->key_minimap)
					put_image(cub, coord_i, 0);
			}
			else if (cub->map[coord_i[1]][coord_i[0]] != '+'
				&& cub->map[coord_i[1]][coord_i[0]] != ' ' && cub->map[coord_i[1]][coord_i[0]] != '1' 
				&& cub->map[coord_i[1]][coord_i[0]] != '0')
				set_player_info(cub, coord_i);
		}
	}
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->layer1, 0, 0);
}


void	moveplayer(t_cub *cub)
{
	float	movestep;

	cub->player->rotationangle = normalize_angle(cub->player->rotationangle);
	cub->player->rotationangle += cub->player->turndirection * \
	cub->player->turnspeed;
	movestep = cub->player->walkdirection * cub->player->walkspeed;
	if (!is_it_hitt_wall(cub, (cub->px + cos(cub->player->rotationangle \
		+ cub->player->turnleft) * movestep), \
		(cub->py + sin(cub->player->rotationangle \
		+ cub->player->turnleft) * movestep)))
	{
		cub->px += cos(cub->player->rotationangle
				+ cub->player->turnleft) * movestep;
		cub->py += sin(cub->player->rotationangle
				+ cub->player->turnleft) * movestep;
	}
}

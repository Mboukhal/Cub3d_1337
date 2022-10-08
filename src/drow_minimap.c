/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/08 16:33:07 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

// int	draw_line(t_cub *cub, int begin_x, int begin_y, int color)
// {
// 	double	delta_x;
// 	double	delta_y;
// 	int		pixels;
// 	double	pixel_x;
// 	double	pixel_y;

// 	delta_x = (begin_x + cos(cub->player->rotationangle) \
// 			* cub->size_line) - begin_x;
// 	delta_y = (begin_y + sin(cub->player->rotationangle) \
// 			* cub->size_line) - begin_y;
// 	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
// 	delta_x /= pixels;
// 	delta_y /= pixels;
// 	pixel_x = begin_x;
// 	pixel_y = begin_y;
// 	while (pixels)
// 	{
// 		mlx_pixel_put(cub->mlx, cub->mlx_win, pixel_x, pixel_y, color);
// 		pixel_x += delta_x;
// 		pixel_y += delta_y;
// 		--pixels;
// 	}
// 	return (0);
// }

int	is_it_hitt_wall(t_cub *cub, float x, float y)
{
	int	index_x;
	int	index_y;

	index_y = floor(y / TILE_SIZE);
	index_x = floor(x / TILE_SIZE);
	if (index_y < 0 || index_y < 0)
		return (0);
	LOG(index_x, "index_x")
	LOG(index_y, "index_y")
	LOGC(cub->map[index_y][index_x], "player")
	if (cub->map[index_y][index_x] != '0' && cub->map[index_y][index_x] != 'N'
		&& cub->map[index_y][index_x] != 'S' && cub->map[index_y][index_x] != 'W'
		&& cub->map[index_y][index_x] != 'E')
		return (1);
	return (0);
}

// static void	dorw_ray(t_cub *cub)
// {
// 	int	y;
// 	int	i;

// 	y = cub->player->player_y;
// 	cub->size_line = 0;
// 	printf("here %f || %f\n", cub->player->rotationangle, (float)-(PI / 2));
// 	if (cub->player->rotationangle == (float)-(PI / 2))
// 	{
// 		while (!is_it_hitt_wall(cub, cub->player->player_x, y))
// 		{
// 			printf("N %f || %f\n", cub->player->rotationangle, (float)-(PI / 2));
// 			cub->size_line++;
// 			y--;
// 		}
// 	}
// }


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
			cub->player->player_x + i[0] ,
			cub->player->player_y + i[1] , player_color);
		}
	}
	cub->px = cub->player->player_x;
	cub->py = cub->player->player_y;
	drow_rays(cub);
	// cub->size_line = 40;
	// draw_line(cub, cub->player->player_x + r, \
	// cub->player->player_y + r, 0x0000FF);
}

static void	set_player_info(t_cub *cub, int *coord, int *coord_i)
{
	cub->playerside = cub->map[coord_i[1]][coord_i[0]];
	if (!cub->player->player_x && !cub->player->player_y)
	{
		cub->player->player_x = coord[0] + (TILE_SIZE * coord_i[0]);
		cub->player->player_y = coord[1] + (TILE_SIZE * coord_i[1]);
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty,
		coord[0] + (TILE_SIZE * coord_i[0]), coord[1] + ((TILE_SIZE * coord_i[1])));
}

static void	set_map(t_cub *cub)
{
	int		coord_i[2];

	coord_i[0] = -1;
	while (++coord_i[0] < cub->s_map[0])
	{
		coord_i[1] = -1;
		while (++coord_i[1] < cub->s_map[1])
		{
			if (cub->map[coord_i[1]][coord_i[0]] == '0')
				put_image(cub, coord_i, 1);
			else if (cub->map[coord_i[1]][coord_i[0]] == '1')
				put_image(cub, coord_i, 0);
			else if (cub->map[coord_i[1]][coord_i[0]] != '+'
				&& cub->map[coord_i[1]][coord_i[0]] != ' ')
			{
				cub->playerside = cub->map[coord_i[1]][coord_i[0]];
				if (!cub->player->player_x && !cub->player->player_y)
				{
					cub->player->player_x = (TILE_SIZE) * coord_i[0];
					cub->player->player_y = (TILE_SIZE) * coord_i[1];
				}
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty,
					TILE_SIZE * coord_i[0],  TILE_SIZE * coord_i[1]);
			}
		}
	}
	set_player(cub);
}


void	moveplayer(t_cub *cub)
{
	float	movestep;

	cub->player->rotationangle = normalize_angle(cub->player->rotationangle);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->bg, 0, 0);
	cub->player->rotationangle += cub->player->turndirection * \
	cub->player->turnspeed;
	movestep = cub->player->walkdirection * cub->player->walkspeed;
	if (!is_it_hitt_wall(cub, (cub->player->player_x + cos(cub->player->rotationangle \
		+ cub->player->turnleft) * movestep), \
		(cub->player->player_y + sin(cub->player->rotationangle \
		+ cub->player->turnleft) * movestep)))
	{
		cub->player->player_x += cos(cub->player->rotationangle
				+ cub->player->turnleft) * movestep;
		cub->player->player_y += sin(cub->player->rotationangle
				+ cub->player->turnleft) * movestep;
	}
	set_map(cub);
}

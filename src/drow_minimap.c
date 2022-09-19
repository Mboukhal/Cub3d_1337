/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/19 15:55:43 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

int	draw_line(t_cub *cub, int begin_x, int begin_y, int color, int size)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = (begin_x + cos(cub->player->rotationangle) \
			* size) - begin_x;
	delta_y = (begin_y + sin(cub->player->rotationangle) \
			* size) - begin_y;
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

static void	set_player(t_cub *cub)
{
	int	player_size;
	int	player_color;
	int	i[2];
	int	r;

	player_size = 8;
	player_color = 11605993;
	i[0] = -1;
	while (++i[0] < player_size)
	{
		i[1] = -1;
		while (++i[1] < player_size)
		{
			r = i[0] + 3;
			mlx_pixel_put(cub->mlx, cub->mlx_win, \
			cub->player->player_x + i[0] + 6, cub->player->player_y + \
			i[1] + 6, player_color);
		}
	}
	draw_line(cub, cub->player->player_x + r , \
	cub->player->player_y + r, 0xFF0000, 40);
}

static void set_player_info(t_cub *cub, int x, int y, int xi, int yi)
{
	cub->playerside = cub->map[yi][xi];
	if (!cub->player->player_x && !cub->player->player_y)
	{
		cub->player->player_x = x + (cub->player->width * xi);
		cub->player->player_y = y + (cub->player->height * yi);
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty, x + (22 * xi), y + ((22 * yi)));
}

static void	set_map(t_cub *cub)
{
	int		x;
	int		y;
	int		xi;
	int		yi;

	x = ((MINI_BG - (cub->s_map[0] * 22)) / 2);
	y = ((MINI_BG - (cub->s_map[1] * 22)) / 2);
	xi = -1;
	while (++xi < cub->s_map[0])
	{
		yi = -1;
		while (++yi < cub->s_map[1])
		{
			if (cub->map[yi][xi] == '0')
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty,
						x + (cub->player->width * xi), y + (cub->player->height * yi));
			else if (cub->map[yi][xi] == '1')
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->wall,
						x + (cub->player->width * xi), y + (cub->player->height * yi));
			else if (cub->map[yi][xi] != '+' && cub->map[yi][xi] != ' ')
				set_player_info(cub, x, y, xi, yi);
		}
	}
	set_player(cub);
}

void	moveplayer(t_cub *cub)
{
	float	movestep;

	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->bg, 20, 20);
	cub->player->rotationangle += cub->player->turndirection * \
	cub->player->turnspeed;
	// printf("%f\n", cub->player->rotationangle);
	movestep = cub->player->walkdirection * cub->player->walkspeed;
	cub->player->player_x += cos(cub->player->rotationangle) * movestep;
	cub->player->player_y += sin(cub->player->rotationangle) * movestep;
	set_map(cub);
}
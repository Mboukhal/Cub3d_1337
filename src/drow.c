/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:36:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/12 13:06:53 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

/* base shift (bitwise operations)
	x << y <=> x = x * 2^(y);

	01010100
  |
	10100101
  = 11110101 
*/

void	create_trgb(int *rgb, int *color)
{
	*color = (rgb[1] << 16 | rgb[2] << 8 | rgb[3]);
}

void	set_buffer(t_cub *c, int pixel, int color)
{
	c->layer1_buffer[pixel + 0] = (color) & 0xFF;
	c->layer1_buffer[pixel + 1] = (color >> 8) & 0xFF;
	c->layer1_buffer[pixel + 2] = (color >> 16) & 0xFF;
	c->layer1_buffer[pixel + 3] = (color >> 24);
}

void	drow_floor_and_ceilling(t_cub *c)
{
	int		color[2];
	int		index[2];
	int		pixel;

	create_trgb(c->tab_txt_c->cc, &color[0]);
	create_trgb(c->tab_txt_c->cf, &color[1]);
	index[0] = -1;
	while (++index[0] < WIN_H)
	{
		index[1] = -1;
		while (++index[1] < WIN_W)
		{
			pixel = (index[0] * (WIN_W * 4)) + (index[1] * 4);
			if (index[0] < (WIN_H / 2))
				set_buffer(c, pixel, color[0]);
			else
				set_buffer(c, pixel, color[1]);
		}
	}
}

void	put_image(t_cub *cub, int *coord_i, int empty)
{
	if (empty == 1)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->image->empty,
			(TILE_SIZE * coord_i[0]) / SCAL, (TILE_SIZE * coord_i[1]) / SCAL);
	else
		mlx_put_image_to_window(cub->mlx, cub->win, cub->image->wall,
			(TILE_SIZE * coord_i[0]) / SCAL, (TILE_SIZE * coord_i[1]) / SCAL);
}

void	side_of_player(t_cub *cub)
{
	if (cub->side_of_player == 'N')
		cub->player->rotationangle = (3 * PI) / 2;
	else if (cub->side_of_player == 'E')
		cub->player->rotationangle = 0;
	else if (cub->side_of_player == 'W')
		cub->player->rotationangle = PI;
	else if (cub->side_of_player == 'S')
		cub->player->rotationangle = PI / 2;
}

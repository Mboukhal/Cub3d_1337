/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:36:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/16 07:55:15 by ahmaidi          ###   ########.fr       */
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

void	drow_floor_and_ceilling(t_cub *c)
{
	int     bpp;
	int     size_line;
	int     endian;
	int 	color[2];
	int		y;
	int		x;

	create_trgb(c->tab_txt_c->cc, &color[0]);
	create_trgb(c->tab_txt_c->cf, &color[1]);
	c->img_ptr = mlx_new_image(c->mlx, WIN_W, WIN_H);
 	c->buffer = mlx_get_data_addr(c->img_ptr, &bpp, &size_line, &endian);
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			int pixel = (y * size_line) + (x * 4);
			if (y < (WIN_H / 2))
			{
				c->buffer[pixel + 0] = (color[0]);
				c->buffer[pixel + 1] = (color[0] >> 8) & 0xFF;
				c->buffer[pixel + 2] = (color[0] >> 16) & 0xFF;
				c->buffer[pixel + 3] = (color[0] >> 24);
			}
			if (y > (WIN_H / 2))
			{
				c->buffer[pixel + 0] = (color[1]) & 0xFF;
				c->buffer[pixel + 1] = (color[1] >> 8) & 0xFF;
				c->buffer[pixel + 2] = (color[1] >> 16) & 0xFF;
				c->buffer[pixel + 3] = (color[1] >> 24);
			}
			x++;
		}
		y++;
	}
}
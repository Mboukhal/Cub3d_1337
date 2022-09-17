/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:36:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/16 08:15:31 by mboukhal         ###   ########.fr       */
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

static void	set_buffer(t_cub *c, int pixel, int color)
{
	c->layer1_buffer[pixel + 0] = (color) & 0xFF;
	c->layer1_buffer[pixel + 1] = (color >> 8) & 0xFF;
	c->layer1_buffer[pixel + 2] = (color >> 16) & 0xFF;
	c->layer1_buffer[pixel + 3] = (color >> 24);
}

void	drow_floor_and_ceilling(t_cub *c)
{
	int     i[3];
	int 	color[2];
	int		index[2];
	int		pixel;

	create_trgb(c->tab_txt_c->cc, &color[0]);
	create_trgb(c->tab_txt_c->cf, &color[1]);
	c->layer1 = mlx_new_image(c->mlx, WIN_W, WIN_H);
 	c->layer1_buffer = mlx_get_data_addr(c->layer1, &i[1], &i[0], &i[2]);
	index[0] = -1;
	while (++index[0] < WIN_H)
	{
		index[1] = -1;
		while (++index[1] < WIN_W)
		{
			pixel = (index[0] * (*i)) + (index[1] * 4);
			if (index[0] < (WIN_H / 2))
				set_buffer(c, pixel, color[0]);
			else
				set_buffer(c, pixel, color[1]);
		}
	}
}
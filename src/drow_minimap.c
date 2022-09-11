/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/11 21:12:44 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	rect(char *buffer, int winh, int winw, int h, int w)
{
	int index[2];
	int color;
	int pixel;
	int cc1[3] = { 0, 0, 0 } ;

	(void) h, (void) w;
	create_trgb(cc1, &color);
	index[0] = -1;
	while (++index[0] < winh)
	{
		index[1] = -1;
		while (++index[1] < winw)
		{
			pixel = (index[0] * (winw * 4)) + (index[1] * 4);

			if (index[0] >= 50 && index[0] <= 200
				&& index[1] >= 50 && index[1] <= 200)
				set_buffer(&buffer[pixel], color);
		}
	}
}

void	drow_minimap(t_cub *cub)
{

	// cub->image->tmplet = mlx_new_image(cub->mlx, WIN_W, WIN_H);
	rect(cub->bf, WIN_H, WIN_W, 50, 200);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->tmplet, 0, 0);
	// mlx_put_image_to_window(c->mlx, c->mlx_win, c->image->no, FIX_FIT, FIX_FIT);
	// mlx_put_image_to_window(c->mlx, c->mlx_win, c->image->so, ELEMENT_SIZE FIX_FIT, FIX_FIT);
	// mlx_put_image_to_window(c->mlx, c->mlx_win, c->image->ea, (ELEMENT_SIZE * 2) FIX_FIT, FIX_FIT);
	// mlx_put_image_to_window(c->mlx, c->mlx_win, c->image->we, (ELEMENT_SIZE * 3) FIX_FIT, FIX_FIT);
}
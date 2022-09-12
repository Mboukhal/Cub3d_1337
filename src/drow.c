/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:36:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/12 19:16:07 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	create_trgb(int *rgb, int *color)
{
	*color = (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | rgb[3]);
}

void	drow_floor_and_ceilling(t_cub *c)
{
	int index[2];
	int color[2];

	create_trgb(c->tab_txt_c->cc, &color[0]);
	create_trgb(c->tab_txt_c->cf, &color[1]);
	index[0] = -1;
	while (++index[0] < WIN_H)
	{
		index[1] = -1;
		while (++index[1] < WIN_W)
		{
			if (index[0] < WIN_H / 2)
				mlx_pixel_put(c->mlx, c->mlx_win, index[1], index[0], color[0]);
			else
				mlx_pixel_put(c->mlx, c->mlx_win, index[1], index[0], color[1]);
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:36:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/12 12:55:10 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	create_trgb(int *rgb, int *color)
{
	*color = (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | rgb[3]);
}   

void	set_buffer(char *buffer, int color)
{
	buffer[0] = ((unsigned char *)&color)[0];
	buffer[1] = ((unsigned char *)&color)[1];
	buffer[2] = ((unsigned char *)&color)[2];
	buffer[3] = ((unsigned char *)&color)[3]; 
}

void	drow_floor_and_ceilling(t_cub *c)
{
	int index[2];
	int color[2];
	int pixel;
	char *buffer;

	buffer = c->bf;
	create_trgb(c->tab_txt_c->color_ceilling, &color[0]);
	create_trgb(c->tab_txt_c->color_floor, &color[1]);
	index[0] = -1;
	while (++index[0] < WIN_H)
	{
		index[1] = -1;
		while (++index[1] < WIN_W)
		{
			pixel = (index[0] * c->bf_in) + (index[1] * 4);
			if (index[0] < WIN_H / 2)
				set_buffer(&buffer[pixel], color[0]);
			else
				set_buffer(&buffer[pixel], color[1]);
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:36:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/09 19:30:37 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static int	create_trgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

static unsigned char	get_trgb(int trgb, int index)
{
	return (((unsigned char *)&trgb)[index]);
}

static void	set_buffer(char *buffer, int color)
{
	*buffer = 0;
	buffer[1] = get_trgb(color, 1);
	buffer[2] = get_trgb(color, 2);
	buffer[3] = get_trgb(color, 3);
}

char	*drow_floor_and_ceilling(t_cub *c)
{
	int index[2];
	int i[3];
	int color[2];
	int pixel;
	char *buffer;

	buffer = mlx_get_data_addr(c->image->tmplet, i, &i[1], &i[2]);
	c->bf = buffer;
	c->bf_in = i[1];
	index[0] = -1;
	color[0] = create_trgb(ft_atoi(c->image->c[0]),
			ft_atoi(c->image->c[1]), ft_atoi(c->image->c[2]));
	color[1] = create_trgb(ft_atoi(c->image->f[0]),
			ft_atoi(c->image->f[1]), ft_atoi(c->image->f[2]));
	while (++index[0] < WIN_H)
	{
		index[1] = -1;
		while (++index[1] < WIN_W)
		{
			// TODO: need more info
			pixel = (index[0] * i[1]) + (index[1] * 4);
			if (index[0] < WIN_H / 2)
				set_buffer(&buffer[pixel], color[0]);
			else
				set_buffer(&buffer[pixel], color[1]);
		}
	}
	return (buffer);
}
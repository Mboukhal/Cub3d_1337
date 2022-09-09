/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/09 19:33:50 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

int	create_trgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

unsigned char	get_trgb(int trgb, int index)
{
	return (((unsigned char *)&trgb)[index]);
}

void	set_buffer(char *buffer, int color)
{
	*buffer = 0;
	buffer[1] = get_trgb(color, 1);
	buffer[2] = get_trgb(color, 2);
	buffer[3] = get_trgb(color, 3);
}

char	*ss(t_cub *c)
{
	int index[2];
	int color[2];
	int pixel;
	char *buffer;

	buffer = c->bf;
	// buffer = mlx_get_data_addr(c->image->tmplet, i, &i[1], &i[2]);
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
			pixel = (index[0] * c->bf_in) + (index[1] * 4);
			if (index[0] > (WIN_H / 2) - 1 )
				set_buffer(&buffer[pixel], color[0]);
			// else
			// 	set_buffer(&buffer[pixel], color[1]);
		}
	}
	return (buffer);
}

void	drow_minimap(t_cub *cub)
{

	char	*buff;

	// cub->image->tmplet = mlx_new_image(cub->mlx, WIN_W, WIN_H);
	buff = ss(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->tmplet, 0, 0);
	// mlx_put_image_to_window(c->mlx, c->mlx_win, c->image->no, FIX_FIT, FIX_FIT);
	// mlx_put_image_to_window(c->mlx, c->mlx_win, c->image->so, ELEMENT_SIZE FIX_FIT, FIX_FIT);
	// mlx_put_image_to_window(c->mlx, c->mlx_win, c->image->ea, (ELEMENT_SIZE * 2) FIX_FIT, FIX_FIT);
	// mlx_put_image_to_window(c->mlx, c->mlx_win, c->image->we, (ELEMENT_SIZE * 3) FIX_FIT, FIX_FIT);
}
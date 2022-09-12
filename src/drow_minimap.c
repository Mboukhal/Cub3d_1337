/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/12 22:47:59 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	rect(t_cub *cub, int winh, int winw, int position, int color)
{
	int index[2];
	int pixel;

	index[0] = -1;
	while (++index[0] < winh)
	{
		index[1] = -1;
		while (++index[1] < winw)
		{
			if (index[0] >= position && index[0] <= winh
				&& index[1] >= position && index[1] <= winh - position)
				mlx_pixel_put(cub->mlx, cub->mlx_win, index[0], index[1], color);
			else if (index[0] > position && index[0] > winh
				&& index[1] > position && index[1] > winh - position)
				return ;
		}
	}
}

/*

	x max = 823p or 36el
	y max = 823p or 36el

*/

void	drow_minimap(t_cub *cub)
{
	int rect_size;

	// rect_size = (int)(cub->s_map[0] / 100);
	rect_size = 835 - 22 ;
	printf("rect_size = %d\n", rect_size);							
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->no, 0, 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->so, ELEMENT_SIZE , 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->ea, (ELEMENT_SIZE * 2) , 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->we, (ELEMENT_SIZE * 3) , 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->we, (ELEMENT_SIZE * 4) , 0);

	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->bg, 20, 20);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty, 22+ rect_size , 22);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->wall, 44+ rect_size , 22);

	
}
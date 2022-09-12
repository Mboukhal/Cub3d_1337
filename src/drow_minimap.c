/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/12 18:41:21 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	rect(t_cub *cub, int winh, int winw, int h, int w, int color)
{
	int index[2];
	int pixel;

	index[0] = -1;
	while (++index[0] < winh)
	{
		index[1] = -1;
		while (++index[1] < winw)
		{
			if (index[0] >= h && index[0] <= w
				&& index[1] >= h && index[1] <= w)
				mlx_pixel_put(cub->mlx, cub->mlx_win, index[0], index[1], color);
			else if (index[0] > h && index[0] > w
				&& index[1] > h && index[1] > w)
				return ;
		}
	}
}

void	drow_minimap(t_cub *cub)
{
									
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->no, 0, 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->so, ELEMENT_SIZE , 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->ea, (ELEMENT_SIZE * 2) , 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->we, (ELEMENT_SIZE * 3) , 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->we, (ELEMENT_SIZE * 4) , 0);

	rect(cub, WIN_H, WIN_W, 100, WIN_H - 100, 255);
	
}
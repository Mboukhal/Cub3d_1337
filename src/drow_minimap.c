/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/13 15:24:34 by mboukhal         ###   ########.fr       */
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

static void set_player(t_cub *cub, int x , int y)
{
	int	player_size;
	int	player_x;
	int	player_y;
	int i;
	int j;
	
	player_x = (6 + x);
	player_y = (6 + y);
	player_size = 8;
	i = -1;
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty, x , y);
	while (++i < player_size)
	{
		j = -1;
		while (++j < player_size)
			mlx_pixel_put(cub->mlx, cub->mlx_win, player_x + i, player_y + j, 11605993);
	}
}

void	set_map(t_cub *cub)
{
	int x = (MINI_BG - (cub->s_map[0] * 22)) / 2;
	int y = (MINI_BG - (cub->s_map[1] * 22)) / 2;
	char	p;
	int xi = -1;
	int yi;

	printf("set_map: x %d y %d\n", x, y);
	printf("map_size: x %d y %d\n", cub->s_map[0], cub->s_map[1]);
	// printf("set_map: xi %d yi %d\n", xi, yi);
	while (++xi < cub->s_map[0])
	{
		yi = -1;
		while (++yi < cub->s_map[1])
		{
			p = cub->map[yi][xi];
			// printf("map: first %c yi [%s]\n", cub->map[yi][xi], cub->map[yi]);
			if (p == '0')
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty, x + (22 * xi) , y + (22 * yi));
			else if (p == '1')
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->wall, x + (22 * xi) , y + (22 * yi));
			else if (p != '+' && p != ' ')
				set_player(cub, x + (22 * xi), y + (22 * yi));
		}
	}
	printf("xi = [%d]", xi);
	printf("yi = [%d]", yi);
}

/*

	x max = 823p or 36el
	y max = 823p or 36el

*/

void	drow_minimap(t_cub *cub)
{
	// int rect_size;
	
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->bg, 20, 20);

	set_map(cub);
	// rect_size = (int)(cub->s_map[0] / 100);
	// rect_size = 835 - 22 ;
	// printf("rect_size = %d\n", rect_size);							
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->no, 0, 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->so, ELEMENT_SIZE , 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->ea, (ELEMENT_SIZE * 2) , 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->we, (ELEMENT_SIZE * 3) , 0);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->we, (ELEMENT_SIZE * 4) , 0);

	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty, 22+ rect_size , 22);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->wall, 44+ rect_size , 22);

	
}
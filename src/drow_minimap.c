/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/14 17:01:29 by mboukhal         ###   ########.fr       */
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

static void set_player(t_cub *cub)
{
	int	player_size;
	int	player_color;
	int i[2];
	
	player_size = 8;
	player_color = 11605993;
	i[0] = -1;
	while (++i[0] < player_size)
	{
		i[1] = -1;
		while (++i[1] < player_size)
		{
			mlx_pixel_put(cub->mlx, cub->mlx_win,
					cub->player_x + i[0] + 6, cub->player_y + i[1] + 6, player_color);
		}
	}
}

/*
	map and background need to be saved in buffer
	for fixing randreing performance issues
*/

void	set_map(t_cub *cub)
{
	int x = ((MINI_BG - (cub->s_map[0] * 22)) / 2);
	int y = ((MINI_BG - (cub->s_map[1] * 22)) / 2);
	char	p;
	int xi = -1;
	int yi;

	while (++xi < cub->s_map[0])
	{
		yi = -1;
		while (++yi < cub->s_map[1])
		{
			p = cub->map[yi][xi];
			if (p == '0')
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty, x + (22 * xi) , y + (22 * yi));
			else if (p == '1')
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->wall, x + (22 * xi) , y + (22 * yi));
			else if (p != '+' && p != ' ')
			{
				if (!cub->player_x && !cub->player_y)
				{
					cub->player_x = x + (22 * xi);
					cub->player_y = y + (22 * yi);
				}
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty, x + (22 * xi) , y + ((22 * yi)));
			}
		}
	}
	set_player(cub);//, , );
	// printf("xi = [%d]\n", xi);
	// printf("yi = [%d]\n", yi);
}

// void	set_map(t_cub *cub, char *buffer)
// {
// 	int		x;
// 	int		y;
// 	char	p;
// 	int		xi;
// 	int		yi;

// 	x = ((MINI_BG - (cub->s_map[0] * 22)) / 2);
// 	y = ((MINI_BG - (cub->s_map[1] * 22)) / 2);
// 	xi = -1;
// 	while (++xi < cub->s_map[0])
// 	{
// 		yi = -1;
// 		while (++yi < cub->s_map[1])
// 		{
// 			p = cub->map[yi][xi];
// 			if (p == '0')
// 				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty, x + (22 * xi) , y + (22 * yi));
// 			else if (p == '1')
// 				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->wall, x + (22 * xi) , y + (22 * yi));
// 			else if (p != '+' && p != ' ')
// 			{
// 				if (!cub->player_x && !cub->player_y)
// 				{
// 					cub->player_x = x + (22 * xi);
// 					cub->player_y = y + (22 * yi);
// 				}
// 				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty, x + (22 * xi) , y + ((22 * yi)));
// 			}
// 		}

// 	}
// 	set_player(cub);//, , );
// 	printf("xi = [%d]\n", xi);
// 	printf("yi = [%d]\n", yi);
// }


void	set_image(int x, int y, t_cub *cub)
{
	int i[3];
	char *map;
	char *bg;

	cub->image->tmplet = mlx_new_image(cub->mlx, y, x);
	map = mlx_get_data_addr(cub->image->tmplet, i, &i[1], &i[2]);
	bg  = mlx_get_data_addr(cub->image->bg, i, &i[1], &i[2]);
	int r =-1;
	printf("%s\n",bg);
	while (bg[++r])
	{
		map[r] = bg[r];
	}
	// set_map(cub, buffer);
	// cub->bf_in = i[1];
	// drow_row_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->tmplet, 20, 20);
}

/*

	x max = 823p or 36el
	y max = 823p or 36el

*/

void	drow_minimap(t_cub *cub)
{
	// int rect_size;
	
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->bg, 20, 20);
	// set_image(860, 860, cub);
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
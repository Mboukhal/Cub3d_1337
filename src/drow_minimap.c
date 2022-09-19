/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/18 23:45:19 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	rect(t_cub *cub, int winh, int winw, int position, int color)
{
	int	index[2];
	int	pixel;

	index[0] = -1;
	while (++index[0] < winh)
	{
		index[1] = -1;
		while (++index[1] < winw)
		{
			if (index[0] >= position && index[0] <= winh
				&& index[1] >= position && index[1] <= winh - position)
				mlx_pixel_put(cub->mlx, cub->mlx_win, \
				index[0], index[1], color);
			else if (index[0] > position && index[0] > winh
				&& index[1] > position && index[1] > winh - position)
				return ;
		}
	}
}

int draw_line(void *mlx, void *win, int begin_x, int begin_y, int end_x, int end_y, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = end_x - begin_x;
	delta_y = end_y - begin_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = begin_x;
	pixel_y = begin_y;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
	return (0);
}

void	moveplayer(t_cub *cub)
{
	float	movestep;

	cub->player->rotationangle += cub->player->turndirection * \
	cub->player->turnspeed;
	movestep = cub->player->walkdirection * cub->player->walkspeed;
	cub->player->player_x += cos(cub->player->rotationangle) * movestep;
	cub->player->player_y += sin(cub->player->rotationangle) * movestep;
}

static void	set_player(t_cub *cub)
{
	int	player_size;
	int	player_color;
	int	i[2];

	player_size = 8;
	player_color = 11605993;
	i[0] = -1;
	while (++i[0] < player_size)
	{
		i[1] = -1;
		while (++i[1] < player_size)
		{
			mlx_pixel_put(cub->mlx, cub->mlx_win, \
			cub->player->player_x + i[0] + 6, cub->player->player_y + \
			i[1] + 6, player_color);
		}
	}
	draw_line(cub->mlx, cub->mlx_win, cub->player->player_x + 9, \
	cub->player->player_y + 9, \
	cub->player->player_x + 10 + cos(cub->player->rotationangle) \
	* 40, cub->player->player_y + sin(cub->player->rotationangle) \
	* 40, 0xFF0000);
}

/*
	map and background need to be saved in buffer
	for fixing randreing performance issues
*/

void	set_map(t_cub *cub)
{
	int x = ((MINI_BG - (cub->s_map[0] * 22)) / 2);
	int y = ((MINI_BG - (cub->s_map[1] * 22)) / 2);
	int xi = -1;
	int yi;

	while (++xi < cub->s_map[0])
	{
		yi = -1;
		while (++yi < cub->s_map[1])
		{
			if (cub->map[yi][xi] == '0')
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty, \
				x + (cub->player->width * xi), y + (cub->player->height * yi));
			else if (cub->map[yi][xi] == '1')
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->wall, x + (cub->player->width * xi), y + (cub->player->height * yi));
			else if (cub->map[yi][xi] != '+' && cub->map[yi][xi] != ' ')
			{
				if (!cub->player->player_x && !cub->player->player_y)
				{
					cub->player->player_x = x + (cub->player->width * xi);
					cub->player->player_y = y + (cub->player->height * yi);
				}
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->empty, x + (22 * xi), y + ((22 * yi)));
			}
		}
	}
	set_player(cub);
	// printf("xi = [%d]\n", xi);
	// printf("yi = [%d]\n", yi);
}

void	set_image(int x, int y, t_cub *cub)
{
	int i[3];
	char *map;
	char *bg;

	cub->image->tmplet = mlx_new_image(cub->mlx, y, x);
	map = mlx_get_data_addr(cub->image->tmplet, i, &i[1], &i[2]);
	bg  = mlx_get_data_addr(cub->image->bg, i, &i[1], &i[2]);
	int r =-1;
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
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->bg, 20, 20);
	moveplayer(cub);
	set_map(cub);
}


	// int rect_size;
	// set_image(860, 860, cub);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:01:42 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/12 18:33:03 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static void	set_color(t_cub *c, int index)
{
	if (c->tab_txt_c[index].type == FLOOR)
	{
		c->tab_txt_c->color_floor[0] = 0;
		c->tab_txt_c->color_floor[1] = ft_atoi(c->tab_txt_c[index].splt[0]);
		c->tab_txt_c->color_floor[2] = ft_atoi(c->tab_txt_c[index].splt[1]);
		c->tab_txt_c->color_floor[3] = ft_atoi(c->tab_txt_c[index].splt[2]);
		for (int i = 0; i < 4; i++)
		{
			printf("ff[%d]\n", c->tab_txt_c->color_floor[i]);
		}

	}
	else if (c->tab_txt_c[index].type == CIEL)
	{
		c->tab_txt_c->color_ceilling[0] = 0;
		c->tab_txt_c->color_ceilling[1] = ft_atoi(c->tab_txt_c[index].splt[0]);
		c->tab_txt_c->color_ceilling[2] = ft_atoi(c->tab_txt_c[index].splt[1]);
		c->tab_txt_c->color_ceilling[3] = ft_atoi(c->tab_txt_c[index].splt[2]);
		for (int i = 0; i < 4; i++)
		{
			printf("cc[%d]\n", c->tab_txt_c->color_ceilling[i]);
		}
	}
		printf("\n");
}

static void load_imges(t_cub *c)
{
	int	i;
	int	size[2];

	i = -1;
	while ( ++i < c->size_tab)
	{
		if (c->tab_txt_c[i].type == EAST)
			c->image->ea = mlx_xpm_file_to_image(
				c->mlx, c->tab_txt_c[i].splt[0], &size[0], &size[1]);
		else if (c->tab_txt_c[i].type == NORTH)
			c->image->no = mlx_xpm_file_to_image(
				c->mlx, c->tab_txt_c[i].splt[0], &size[0], &size[1]);
		else if (c->tab_txt_c[i].type == SOUTH)
			c->image->so = mlx_xpm_file_to_image(
				c->mlx, c->tab_txt_c[i].splt[0], &size[0], &size[1]);
		else if (c->tab_txt_c[i].type == WEST)
			c->image->we = mlx_xpm_file_to_image(
				c->mlx, c->tab_txt_c[i].splt[0], &size[0], &size[1]);
		else if (c->tab_txt_c[i].type == FLOOR || c->tab_txt_c[i].type == CIEL)
			set_color(c, i);
		if (size[0] > 250 || size[1] > 250)
			exit(1);
	}
}

void	update_image(t_cub *cub)
{
	int		i[3];

	cub->image->tmplet = mlx_new_image(cub->mlx, WIN_W, WIN_H);
	cub->bf = mlx_get_data_addr(cub->image->tmplet, i, &i[1], &i[2]);
	cub->bf_in = i[1];
	drow_floor_and_ceilling(cub);
	// drow_row_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->tmplet, 0, 0);
	// if (cub->key_minimap)
	// 	drow_minimap(cub);
	
}

void	start_game(t_cub *cub)
{
	cub->mlx = mlx_init();
	load_imges(cub);
	cub->mlx_win = mlx_new_window(cub->mlx, WIN_W, WIN_H, "CuB3D");
	// printf("x[%d] y[%d]\n" , cub->s_map[0], cub->s_map[1]);
	update_image(cub);

	// mlx_do_key_autorepeaton(cub->mlx);
	mlx_hook(cub->mlx_win, EXIT_BOTTON, 0L, exit_game, cub);
	mlx_key_hook(cub->mlx_win, deal_key, cub);
	mlx_loop(cub->mlx);
}
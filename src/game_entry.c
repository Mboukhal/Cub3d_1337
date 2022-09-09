/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:01:42 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/09 19:40:38 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

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
		else if (c->tab_txt_c[i].type == FLOOR)
			c->image->f = c->tab_txt_c[i].splt;
		else if (c->tab_txt_c[i].type == CIEL)
			c->image->c = c->tab_txt_c[i].splt;
		if (size[0] > 250 || size[1] > 250)
			exit(1);
	}
}

void	update(t_cub *cub)
{
	char	*buff;

	cub->image->tmplet = mlx_new_image(cub->mlx, WIN_W, WIN_H);
	buff = drow_floor_and_ceilling(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image->tmplet, 0, 0);
	// drow_minimap(cub);
}

void	start_game(t_cub *cub)
{

	cub->mlx = mlx_init();
	load_imges(cub);
	cub->mlx_win = mlx_new_window(cub->mlx, WIN_W, WIN_H, "CuB3D");

	//--------------------------------------------------------
	update(cub);
	//--------------------------------------------------------


	// mlx_do_key_autorepeaton(cub->mlx);
	mlx_hook(cub->mlx_win, EXIT_BOTTON, 0L, exit_game, cub);
	mlx_key_hook(cub->mlx_win, deal_key, cub);
	mlx_loop(cub->mlx);
}
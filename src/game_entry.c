/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:01:42 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/09 18:03:41 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static void	set_color(t_cub *c, int index, int *size)
{
	if (c->tab_txt_c[index].type == FLOOR)
	{
		c->tab_txt_c->cf[0] = 0;
		c->tab_txt_c->cf[1] = ft_atoi(c->tab_txt_c[index].splt[0]);
		c->tab_txt_c->cf[2] = ft_atoi(c->tab_txt_c[index].splt[1]);
		c->tab_txt_c->cf[3] = ft_atoi(c->tab_txt_c[index].splt[2]);
	}
	else if (c->tab_txt_c[index].type == CIEL)
	{
		c->tab_txt_c->cc[0] = 0;
		c->tab_txt_c->cc[1] = ft_atoi(c->tab_txt_c[index].splt[0]);
		c->tab_txt_c->cc[2] = ft_atoi(c->tab_txt_c[index].splt[1]);
		c->tab_txt_c->cc[3] = ft_atoi(c->tab_txt_c[index].splt[2]);
	}
	else if (size[0] > 250 || size[1] > 250)
	{
		ft_putstr_fd("ERROR:\n\tSize textures must \
		be less or equal than 250x250", 2);
		exit(1);
	}
}

static void	load_imges_const(t_cub *c, int *size)
{
	c->image->bg = mlx_xpm_file_to_image(c->mlx,
			"images/minimap_xmp/BgMinimap.xpm", &size[0], &size[1]);
	c->image->empty = mlx_xpm_file_to_image(c->mlx,
			"images/minimap_xmp/empty.xpm", &size[0], &size[1]);
	c->image->wall = mlx_xpm_file_to_image(c->mlx,
			"images/minimap_xmp/wall.xpm", &size[0], &size[1]);
}

static void	load_imges(t_cub *c)
{
	int	i;
	int	size[2];

	i = -1;
	while (++i < c->size_tab)
	{
		if (c->tab_txt_c[i].type == EAST)
			c->image->ea = mlx_xpm_file_to_image(c->mlx, \
				c->tab_txt_c[i].splt[0], &size[0], &size[1]);
		else if (c->tab_txt_c[i].type == NORTH)
			c->image->no = mlx_xpm_file_to_image(c->mlx, \
				c->tab_txt_c[i].splt[0], &size[0], &size[1]);
		else if (c->tab_txt_c[i].type == SOUTH)
			c->image->so = mlx_xpm_file_to_image(c->mlx, \
				c->tab_txt_c[i].splt[0], &size[0], &size[1]);
		else if (c->tab_txt_c[i].type == WEST)
			c->image->we = mlx_xpm_file_to_image(c->mlx, \
				c->tab_txt_c[i].splt[0], &size[0], &size[1]);
		else if (c->tab_txt_c[i].type == FLOOR || c->tab_txt_c[i].type == CIEL)
			set_color(c, i, size);
	}
	load_imges_const(c, size);
}

void	update_image(t_cub *cub)
{

	moveplayer(cub);
	generate_3d_projection(cub);
	if (cub->key_minimap)
		rander_reys(cub);

}

void	start_game(t_cub *cub)
{

	int		i[3];

	cub->mlx = mlx_init();
	cub->layer1 = mlx_new_image(cub->mlx, WIN_W, WIN_H);
	cub->layer1_buffer = mlx_get_data_addr(cub->layer1, &i[1], &i[0], &i[2]);
	load_imges(cub);
	cub->mlx_win = mlx_new_window(cub->mlx, WIN_W, WIN_H, "CuB3D");
	update_image(cub);

	mlx_hook(cub->mlx_win, 2, 1, deal_key, cub);
	mlx_hook(cub->mlx_win, EXIT_BOTTON, 0L, exit_game, cub);
	mlx_loop(cub->mlx);
}

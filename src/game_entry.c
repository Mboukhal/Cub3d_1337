/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:01:42 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/13 10:28:20 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static void	set_color(t_cub *c, int index, int *size)
{
	int	tmp [4];

	tmp[0] = 0;
	tmp[1] = ft_atoi(c->tab_txt_c[index].splt[0]);
	tmp[2] = ft_atoi(c->tab_txt_c[index].splt[1]);
	tmp[3] = ft_atoi(c->tab_txt_c[index].splt[2]);
	if (c->tab_txt_c[index].type == FLOOR)
		c->flo = create_trgb(tmp);
	else if (c->tab_txt_c[index].type == CIEL)
		c->cei = create_trgb(tmp);
	if (size[0] > TILE_SIZE || size[1] > TILE_SIZE)
	{
		ft_putstr_fd("ERROR:\n\tSize textures must \
		be less or equal than 64x64", 2);
		exit(1);
	}
}

static void	load_imges_const(t_cub *cub, int *size)
{
	int		i[3];

	cub->layer1 = mlx_new_image(cub->mlx, WIN_W, WIN_H);
	cub->layer1_buffer = mlx_get_data_addr(cub->layer1, &i[1], &i[0], &i[2]);
	cub->no_buf = mlx_get_data_addr(cub->image->no, &i[1], &i[0], &i[2]);
	cub->so_buf = mlx_get_data_addr(cub->image->so, &i[1], &i[0], &i[2]);
	cub->ea_buf = mlx_get_data_addr(cub->image->ea, &i[1], &i[0], &i[2]);
	cub->we_buf = mlx_get_data_addr(cub->image->we, &i[1], &i[0], &i[2]);
	cub->image->bg = mlx_xpm_file_to_image(cub->mlx,
			"images/minimap_xmp/BgMinimap.xpm", &size[0], &size[1]);
	cub->image->empty = mlx_xpm_file_to_image(cub->mlx,
			"images/minimap_xmp/empty.xpm", &size[0], &size[1]);
	cub->image->wall = mlx_xpm_file_to_image(cub->mlx,
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

static int	mouse_mouve(int x, int y, t_cub *cub)
{
	cub->player->turnspeed = (PI / 180);
	if ((x >= 0 && x <= WIN_W) && (y >= 0 && y <= WIN_H))
	{
		if (x > cub->mouse_old)
			key_rotate(cub, 1);
		else if (x < cub->mouse_old)
			key_rotate(cub, -1);
	}
	cub->mouse_old = x;
	cub->player->turnspeed = 10 * (PI / 180);
	return (0);
}

void	start_game(t_cub *cub)
{
	cub->mlx = mlx_init();
	load_imges(cub);
	cub->win = mlx_new_window(cub->mlx, WIN_W, WIN_H, "CuB3D");
	update_image(cub);
	mlx_hook(cub->win, 2, (1L << 0), deal_key, cub);
	mlx_hook(cub->win, 6, (1L << 0), mouse_mouve, cub);
	mlx_hook(cub->win, EXIT_BOTTON, 0L, exit_game, cub);
	mlx_loop(cub->mlx);
}

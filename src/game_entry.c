/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:01:42 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/08 16:57:26 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void load_imges(t_cub *c)
{
	c-> = mlx_xpm_file_to_image(); 
}

void	start_game(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, 2880, 1620, "Cub3d");
	load_imges(cub);
	// mlx_do_key_autorepeaton(cub->mlx);
	mlx_hook(cub->mlx_win, EXIT_BOTTON, 0L, exit_game, cub);
	mlx_key_hook(cub->mlx_win, deal_key, cub);
	mlx_loop(cub->mlx);
}
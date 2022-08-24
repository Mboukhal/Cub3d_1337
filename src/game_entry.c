/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:01:42 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/24 10:30:43 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	start_game(t_cub *cub)
{
	cub->i = 0;

	// mlx_do_key_autorepeaton(cub->mlx);
	mlx_hook(cub->mlx_win, EXIT_BOTTON, 0L, exit_game, cub);
	mlx_key_hook(cub->mlx_win, deal_key, cub);
	mlx_loop(cub->mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:11:22 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/11 18:38:40 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

int	exit_game(t_cub *cub)
{
	int i;
	// mlx_destroy_image(cub->mlx, cub->image->empty);
	// mlx_destroy_image(cub->mlx, cub->image->wall);
	mlx_destroy_image(cub->mlx, cub->image->ea);
	mlx_destroy_image(cub->mlx, cub->image->so);
	mlx_destroy_image(cub->mlx, cub->image->we);
	mlx_destroy_image(cub->mlx, cub->image->no);
	mlx_destroy_window(cub->mlx, cub->mlx_win);
	i = -1;
	while (cub->map[++i])
		free_it(cub->map[i]);
	free(cub->image);
	// system ("leaks cub3d");
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

						/* key controle {01} */
int	deal_key(int key, t_cub *cub)
{
	if (key == 53)
		exit_game(cub);
	if (key == UP_KEY)
		key_up(cub);
	// if (key == DOWN_KEY)
	// 	key_down(cub);
	// if (key == LEFT_KEY)
	// 	key_left(cub);
	// if (key == RIGHT_KEY)
	// 	key_right(cub);
	return (EXIT_SUCCESS);
}

// void	key_right(cub);
// void	key_left(cub);
// void	key_down(cub);
void	key_up(t_cub *cub)
{
	// update(cub);
	drow_minimap(cub);
}
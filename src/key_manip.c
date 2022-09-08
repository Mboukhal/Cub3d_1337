/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:11:22 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/08 16:32:29 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	exit_game(t_cub *cub)
{
	// int	iter;

	// mlx_destroy_image(cub->mlx, cub->empty);
	// mlx_destroy_image(cub->mlx, cub->exit);
	// mlx_destroy_image(cub->mlx, cub->fish);
	// mlx_destroy_image(cub->mlx, cub->wall);
	// mlx_destroy_image(cub->mlx, cub->player_a);
	// mlx_destroy_image(cub->mlx, cub->player_s);
	// mlx_destroy_image(cub->mlx, cub->player_w);
	// mlx_destroy_image(cub->mlx, cub->player_d);
	// iter = 0;
	// while (cub->map[iter])
	// 	free_it(cub->map[iter++]);
	mlx_destroy_window(cub->mlx, cub->mlx_win);
	// free_it(cub->map);
	// system ("leaks cub3d");
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

						/* key controle {01} */
int	deal_key(int key, t_cub *cub)
{
	if (key == 53)
		exit_game(cub);
	// if (key == UP_KEY)
	// 	key_up(cub);
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
// void	key_up(cub);
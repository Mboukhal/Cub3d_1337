/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:11:22 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/12 19:02:45 by mboukhal         ###   ########.fr       */
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
void	minimap_manip(t_cub *cub)
{
	if (cub->key_minimap)
	{
		cub->key_minimap = 0;
		update_image(cub);
		return ;
	}
	cub->key_minimap = 1;
	update_image(cub);
}
						/* key controle {01} */
int	deal_key(int key, t_cub *cub)
{
	printf("deal_key: [%d] [%d]\n", key, cub->key_minimap);
	if (key == 53)
		exit_game(cub);
	if (key == 48)
		minimap_manip(cub);
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
	// drow_minimap(cub);
}
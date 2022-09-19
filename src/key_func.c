/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:13:43 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/19 16:25:14 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/game_action.h"

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

void	key_W(t_cub *cub)
{
	cub->player->walkdirection = 1;
	update_image(cub);
}

void	key_A(t_cub *cub)
{
	// cub->player->rotationangle += PI / 2;
	cub->player->player_x -= 4;
	update_image(cub);
}

void	key_D(t_cub *cub)
{
	printf("angel == %f\n", cub->player->rotationangle);
	// cub->player->rotationangle -= PI / 2;
	cub->player->player_x += 4;
	update_image(cub);
}

void	key_S(t_cub *cub)
{
	cub->player->walkdirection = -1;
	update_image(cub);
}

void	key_rotate_right(t_cub *cub)
{
	cub->player->turndirection = 1;
	update_image(cub);
}

void	key_rotate_left(t_cub *cub)
{
	cub->player->turndirection = -1;
	update_image(cub);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:13:43 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/19 16:57:52 by mboukhal         ###   ########.fr       */
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

void	key_W_S(t_cub *cub, int i)
{
	cub->player->walkdirection = i;
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

void	key_rotate(t_cub *cub, int i)
{
	cub->player->turndirection = i;
	update_image(cub);
}
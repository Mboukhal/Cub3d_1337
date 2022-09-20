/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:13:43 by mboukhal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/20 09:09:26 by ahmaidi          ###   ########.fr       */
=======
/*   Updated: 2022/09/19 16:57:52 by mboukhal         ###   ########.fr       */
>>>>>>> 0d1b9d3c1192a65e0c9a69dfe350928578146ca0
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

<<<<<<< HEAD
void	key_w(t_cub *cub)
=======
void	key_W_S(t_cub *cub, int i)
>>>>>>> 0d1b9d3c1192a65e0c9a69dfe350928578146ca0
{
	cub->player->walkdirection = i;
	update_image(cub);
}

void	key_a(t_cub *cub)
{
	cub->player->walkdirection = 1;
	cub->player->turnleft = PI / 2;
	update_image(cub);
}

<<<<<<< HEAD
void	key_d(t_cub *cub)
{
	cub->player->walkdirection = -1;
	cub->player->turnleft = PI / 2;
	update_image(cub);
}

void	key_s(t_cub *cub)
{
	cub->player->walkdirection = -1;
	update_image(cub);
}
=======

void	key_rotate(t_cub *cub, int i)
{
	cub->player->turndirection = i;
	update_image(cub);
}
>>>>>>> 0d1b9d3c1192a65e0c9a69dfe350928578146ca0

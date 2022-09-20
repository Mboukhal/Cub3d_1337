/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:26:45 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/20 20:37:42 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub.h"

t_cub	*cub_init(void)
{
	t_cub		*c;

	c = var_init(sizeof(t_cub));
	c->player = var_init(sizeof(t_player));
	c->image = var_init(sizeof(t_image));
	c->tab_txt_c = NULL;
	c->map = NULL;
	c->i = 0;
	c->size_tab = 0;
	c->size_map = 0;
	c->in_map = 0;
	c->is_player = 0;
	c->player->player_x = 0;
	c->player->player_y = 0;
	c->player->height = 22;
	c->player->width = 22;
	c->player->turndirection = 0;
	c->player->walkdirection = 0;
	c->player->rotationangle = PI / 2;
	c->player->turnleft = 0;
	c->player->walkspeed = 4;
	c->player->turnspeed = 45 * (PI / 180);
	c->size_line = 0;
	c->key_minimap = 0;
	return (c);
}

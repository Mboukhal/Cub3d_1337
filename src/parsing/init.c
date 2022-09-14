/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:26:45 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/13 15:41:52 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_cub	*cub_init(void)
{
	t_cub	*c;

	c = var_init(sizeof(t_cub));
	c->image = var_init(sizeof(t_image));
	c->tab_txt_c = NULL;
	c->map = NULL;
	c->i = 0;
	c->player_x = 0;
	c->player_y = 0;
	c->size_tab = 0;
	c->size_map = 0;
	c->in_map = 0;
	c->is_player = 0;
	c->key_minimap = 0;
	return (c);
}

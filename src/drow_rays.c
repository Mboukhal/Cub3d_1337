/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:56:33 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/13 11:26:07 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	rander_reys(t_cub *cub)
{
	int		i;
	int		color;

	set_map(cub, 1);
	i = 0;
	while (i < NUM_RAYS)
	{
		if (cub->ray[i].was_hit_vertical)
			color = 0x00FF00;
		else
			color = 0x00CCFF;
		draw_line_from_player(cub, cub->ray[i].wall_hit_x / SCAL,
			cub->ray[i].wall_hit_y / SCAL, color);
		i++;
	}
}

void	drow_rays(t_cub *cub)
{
	float	ra;
	int		stripl;

	ra = cub->player->rotationangle - ((60 * (PI / 180)) / 2);
	stripl = 0;
	while (stripl < NUM_RAYS)
	{
		cast_ray(cub, ra, stripl);
		ra += (60 * (PI / 180)) / NUM_RAYS;
		stripl++;
	}
}

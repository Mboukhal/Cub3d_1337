/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:56:33 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/21 17:43:51 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	drow_rays(t_cub *cub)
{
	int 	r,mx,my,mp,dof;
	float 	rx,ry,ra,xo,yo;
	float 	aTan;
	int		py = (int)cub->player->player_y;
	int		px = (int)cub->player->player_x;

	rx = 0;
	ry = 0;
	ra = cub->player->rotationangle;
	r = 0;
	while (r <  1)
	{
		dof = 0;
		aTan = -1/tan(ra);
		if (ra > PI)
		{
			ry = ((py >> 6) << 6) - 0.0001;
			rx = (py - ry) * aTan + px;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI)
		{
			ry = ((py >> 6) << 6) + 64;
			rx = (py - ry) * aTan + px;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = px;
			ry = py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) (rx) >> 6;
			mp = my * cub->s_map[1] + mx;
			if (mp < cub->s_map[1] && cub->map[0][mp] == '1')
				dof = 8;
			else 
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		// printf("%d [%d] [%d]\n", dof, rx, ry);
		draw_line(cub, (int)rx, (int)	 * -1, 0x000000);
		r++;
	}
}
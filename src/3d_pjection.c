/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_pjection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:37:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/09 17:13:55 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	generate_3d_projection(t_cub *cub)
{
	int 	i;
	int 	y;
	float 	perp_distance;
	float 	distance_proj_plane;
	float 	projected_wall_height;
	int 	wall_strip_height;
	int 	wall_top_pixel;
	int 	wall_bottom_pixel;
	int		c[3] = {255, 0, 0};
	int		color;
	create_trgb(c, &color);

	drow_floor_and_ceilling(cub);
	i = 0;
	while (i < NUM_RAYS)
	{
		perp_distance = cub->ray[i].distance * cos(cub->ray[i].ray_angle - cub->player->rotationangle);
		distance_proj_plane = (WIN_W) / tan(FOV_ANGLE / 2);
		projected_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
		wall_strip_height = (int)projected_wall_height;
		wall_top_pixel = (WIN_H / 2) -(wall_strip_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;


		wall_bottom_pixel = (WIN_H / 2) + (wall_strip_height / 2);
		wall_bottom_pixel = wall_bottom_pixel > WIN_H ? WIN_H : wall_bottom_pixel;


		y = wall_top_pixel;
		while (y < wall_bottom_pixel)
		{
			// if (cub->ray[i].was_hit_vertical)
			// ft_memset(&(cub->layer1_buffer[(WIN_H * 2) + 1]), 0xFF, 4); 
			// cub->layer1_buffer[(WIN_H * 2) + 1] = (color) & 0xFF;
			// cub->layer1_buffer[(WIN_H * 2) + 2] = (color >> 8) & 0xFF;
			// cub->layer1_buffer[(WIN_H * 2) + 3] = (color >> 16) & 0xFF;
			// cub->layer1_buffer[(WIN_H * 2) + 4] = (color >> 24);
			cub->layer1_buffer[(((WIN_W * y) + i) * 4)] = (char)255;
			// cub->layer1_buffer[(((WIN_W * y) + i) * 4) + 1] = (char)255;
			// cub->layer1_buffer[(((WIN_W * y) + i) * 4) + 2] = (char)255;
			// cub->layer1_buffer[(((WIN_W * y) + i) * 4) + 3] = (char)255;

			y++;
		}
		i++;
	}

}
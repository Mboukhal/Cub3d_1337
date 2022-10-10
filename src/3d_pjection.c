/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_pjection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:37:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/10 15:46:26 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static void cub_set_buffer(t_cub *cub, int pixel, int ray)
{
	uint32_t *dst;
	uint32_t *src;
	dst = (uint32_t*)cub->layer1_buffer;
	src = (uint32_t*)cub->so_buf;

	dst[pixel] = cub->ray[ray].was_hit_vertical ? 0x0000FF00 : 0x00FFCC00;
	dst[pixel + 1] = cub->ray[ray].was_hit_vertical ? 0x0000FF00 : 0x00FFCC00;
	dst[pixel + 2] = cub->ray[ray].was_hit_vertical ? 0x0000FF00 : 0x00FFCC00;
	dst[pixel + 3] = cub->ray[ray].was_hit_vertical ? 0x0000FF00 : 0x00FFCC00;
	// dst[pixel] 		= 0x0000FF00;
	// dst[pixel + 1] 	=  0x0000FF00;
	// dst[pixel + 2] 	=  0x0000FF00;
	// dst[pixel + 3] 	=  0x0000FF00;
}

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
	int 	x;

	x = 0;
	drow_floor_and_ceilling(cub);
	// while(cub->layer1_buffer[x])
	// 	cub->layer1_buffer[x++] = 0;
	x = 0;
	i = 0;
	while (i < NUM_RAYS)
	{
		perp_distance = cub->ray[i].distance * cos(cub->ray[i].ray_angle - cub->player->rotationangle);
		distance_proj_plane = (WIN_W) / tan(FOV_ANGLE);
		projected_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
		wall_strip_height = (int)projected_wall_height;
		wall_top_pixel = (WIN_H / 2) -(wall_strip_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;


		wall_bottom_pixel = (WIN_H / 2) + (wall_strip_height / 2);
		wall_bottom_pixel = wall_bottom_pixel > WIN_H ? WIN_H : wall_bottom_pixel;
		y = wall_top_pixel;
		while (y < wall_bottom_pixel)
		{
			x = ((WIN_W * y) +  (i * 3.2));
			cub_set_buffer(cub, x, i);
			y++;
		}
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->layer1, 0, 0);
}



			// x = ((WIN_W * y) +  (i * 3.2)) * 4;  //3.2));
			// int pixel = ((WIN_W * y) + i) * 4;
			// cub->layer1_buffer[(WIN_H * 2) + 1] = (color) & 0xFF;
			// cub->layer1_buffer[(WIN_H * 2) + 2] = (color >> 8) & 0xFF;
			// cub->layer1_buffer[(WIN_H * 2) + 3] = (color >> 16) & 0xFF;
			// cub->layer1_buffer[(WIN_H * 2) + 4] = (color >> 24);
			// if (1)//cub->ray[i].was_hit_vertical)
			// {
			// 	cub->layer1_buffer[x + 1] = (char)0;			// bleu
			// 	cub->layer1_buffer[x + 2] = (char)255;		// red
			// 	cub->layer1_buffer[x + 3] = (char)255;		// transparant
			// 	cub->layer1_buffer[x + 4] = (char)255;		// green 
			// 	cub->layer1_buffer[x + 5] = (char)0;			// bleu
			// 	cub->layer1_buffer[x + 6] = (char)255;		// red
			// 	cub->layer1_buffer[x + 7] = (char)255;		// transparant
			// 	cub->layer1_buffer[x + 8] = (char)255;		// green 
			// 	cub->layer1_buffer[x + 9] = (char)0;			// bleu
			// 	cub->layer1_buffer[x + 10] = (char)255;		// red
			// 	cub->layer1_buffer[x + 11] = (char)255;		// transparant
			// 	cub->layer1_buffer[x + 12] = (char)255;		// green 
			// 	cub->layer1_buffer[x + 13] = (char)0;			// bleu
			// 	cub->layer1_buffer[x + 14] = (char)255;		// red
			// 	cub->layer1_buffer[x + 15] = (char)255;		// transparant
			// 	cub->layer1_buffer[x + 16] = (char)255;		// green
			// }
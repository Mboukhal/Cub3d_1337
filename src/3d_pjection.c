/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_pjection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:37:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/12 11:07:05 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"
#include <unistd.h>

#define RAY_SIZE	WIN_W / NUM_RAYS

static void cub_set_buffer(t_cub *cub,  int y, int i, int ty, int tx)
{
	uint32_t texelColor;
	// if (cub->ray[i].was_hit_vertical)
	// 	texelColor = ((uint32_t*)cub->we_buf)[(20 * ty) + tx ];
	// else
		texelColor = ((uint32_t*)cub->no_buf)[(( 20 * ty) + tx)];// ty = 3 tx =  20
		// LOG(( 20 * ty) + tx, "( 20 * ty) + tx")
	int pos = ((y * WIN_W) + i);
	uint32_t *ptr = (uint32_t*)cub->layer1_buffer;
	ptr[pos] = texelColor;
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
	// uint32_t offset;

	drow_floor_and_ceilling(cub);
	x = 0;
	i = 0;
	// offset = 0;
	while (i < NUM_RAYS)
	{
		perp_distance = cub->ray[i].distance * cos(cub->ray[i].ray_angle - cub->player->rotationangle);
		distance_proj_plane = (WIN_W / 2) / tan(FOV_ANGLE / 2);
		projected_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
		wall_strip_height = (int)projected_wall_height;
		wall_top_pixel = (WIN_H / 2) -(wall_strip_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;
		wall_bottom_pixel = (WIN_H / 2) + (wall_strip_height / 2);
		wall_bottom_pixel = wall_bottom_pixel > WIN_H ? WIN_H : wall_bottom_pixel;
		int textureOffsetX;
		if (cub->ray[i].was_hit_vertical)
            textureOffsetX = (int)cub->ray[i].wall_hit_y % 20;
        else
            textureOffsetX = (int)cub->ray[i].wall_hit_x % 20;
		y = wall_top_pixel;
		while (y < wall_bottom_pixel)
		{
			int distanceFromTop = (y + (wall_strip_height / 2)) - (WIN_H / 2);
            int textureOffsetY = distanceFromTop * ((float)20 / wall_strip_height);
            // set the color of the wall based on the color from the texture
			cub_set_buffer(cub, y, i, textureOffsetY, (i % 20));
			y++;
		}
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->layer1, 0, 0);
}



			// x = ((WIN_W * y) + i) ;
			// cub_set_buffer(cub, x, y, i);
			// // offset = i + (1000);
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
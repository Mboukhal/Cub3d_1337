/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_pjection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:37:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/13 09:02:25 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static uint32_t	get_buffer(char *texture, int offset_y, int offset_x)
{
	uint32_t	buffer;

	buffer = ((uint32_t *)texture)[(TILE_SIZE * offset_y) + offset_x];
	return (buffer);
}

static void	cub_set_buffer(t_cub *cub, int offset_x, int i, int y, int wsh)
{
	uint32_t	texel_color;
	int			distance_from_top;
	int			offset_y;

	distance_from_top = (y + (wsh / 2)) - (WIN_H / 2);
	offset_y = distance_from_top * ((float)TILE_SIZE / wsh);
	if (cub->ray[i].was_hit_vertical)
		texel_color = get_buffer(cub->so_buf, offset_y, offset_x);
	else
		texel_color = get_buffer(cub->no_buf, offset_y, offset_x);
	((uint32_t *)cub->layer1_buffer)[(WIN_W * y) + i] = texel_color;
}

static void loop_init(t_cub *cub, int *wsh, int *wtp, int *wbp, int x)
{
	float	perp_distance;
	float	distance_proj_plane;
	float	projected_wall_height;

	perp_distance = cub->ray[x].distance
		* cos(cub->ray[x].ray_angle - cub->player->rotationangle);
	distance_proj_plane = (WIN_W / 2) / tan((60 * (PI / 180)) / 2);
	projected_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
	*wsh = (int)projected_wall_height;
	*wtp = (WIN_H / 2) - ((*wsh) / 2);
	*wtp = *wtp < 0 ? 0 : *wtp;
	*wbp = (WIN_H / 2) + ((*wsh) / 2);
	*wbp = *wbp > WIN_H ? WIN_H : *wbp;
}

void	generate_3d_projection(t_cub *cub)
{
	int 	x;
	int 	y;
	int 	wall_strip_height;
	int 	wall_top_pixel;
	int 	wall_bottom_pixel;
	int		texture_offset_x;

	x = -1;
	while (++x < NUM_RAYS)
	{
		loop_init (cub, &wall_strip_height,
			&wall_top_pixel, &wall_bottom_pixel, x);
		if (cub->ray[x].was_hit_vertical)
			texture_offset_x = (int)cub->ray[x].wall_hit_y % TILE_SIZE;
		else
			texture_offset_x = (int)cub->ray[x].wall_hit_x % TILE_SIZE;
		y = 0;
		while (y < wall_top_pixel)
			set_buffer(cub, (((y++) * (WIN_W * 4)) + (x * 4)), cub->cei);
		while (y < wall_bottom_pixel)
			cub_set_buffer(cub, texture_offset_x, x, y++, wall_strip_height);
		while (y < WIN_H)
			set_buffer(cub, (((y++) * (WIN_W * 4)) + (x * 4)), cub->flo);
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->layer1, 0, 0);
}

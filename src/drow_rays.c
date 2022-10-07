/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:56:33 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/07 22:47:51 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static int	draw_l(t_cub *cub, int begin_x, int begin_y, int end_x, int end_y, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = end_x - begin_x;
	delta_y = end_y - begin_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = begin_x;
	pixel_y = begin_y;
	while (pixels)
	{
		mlx_pixel_put(cub->mlx, cub->mlx_win, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
	return (0);
}

float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

int	hitt_wall(t_cub *cub, float x, float y)
{
	int	index_x;
	int	index_y;

	index_y = floor((y - DY) / 20);
	index_x = floor((x - DX) / 20);
	// if (index_y < 0 || index_y < 0)
	// 	return (0);
	if (cub->map[index_y][index_x] == '1')
		return (1);
	return (0);
}

float distanceBetweenPoints(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void	cast_ray(t_cub *cub, float ray_angle, int stripl)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	int		is_ray_facing_left;

	int 	fod_hoz_wall_hit = 0;
	float	horz_wall_hit_x = 0;
	float	horz_wall_hit_y = 0;
	int		horz_wall_content = 0;

	ray_angle = normalize_angle(ray_angle);
	is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	is_ray_facing_up = !is_ray_facing_down;
	is_ray_facing_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
	is_ray_facing_left = !is_ray_facing_right;

	yintercept = floor(cub->py / TILE_SIZE ) * TILE_SIZE;
	yintercept += is_ray_facing_down ? TILE_SIZE : 0;


	xintercept = cub->px + (yintercept - cub->py) / tan(ray_angle);


	ystep = TILE_SIZE;
	ystep *= is_ray_facing_up ? -1 : 1;
	int found_horz_touch = FALSE;

	xstep = TILE_SIZE / tan(ray_angle);
	xstep *= (is_ray_facing_left && xstep > 0) ? -1 : 1;
	xstep *= (is_ray_facing_right && xstep < 0) ? -1 : 1;
	

	float next_horz_touch_x = xintercept;
	float next_horz_touch_y = yintercept;
	
	int map_x = cub->s_map[0] * 20;
	int map_y = cub->s_map[1] * 20;

	float x_to_check;
	float y_to_check;

	// printf("steps ==> x[%f] y [%f] \n", xstep, ystep);
	// printf("==> x[%f] y [%f] \n", cub->player->player_x, cub->player->player_y);
	// printf("==> next : x[%f] y [%f] \n", next_horz_touch_x, next_horz_touch_y);
	draw_l(cub, cub->px, cub->py, next_horz_touch_x, next_horz_touch_y, 0xFF0000);
	while (next_horz_touch_x >= DX && next_horz_touch_x <= map_x && next_horz_touch_y >= DY && next_horz_touch_y <= map_y)
	{
		x_to_check = next_horz_touch_x;
		y_to_check = next_horz_touch_y;// + (is_ray_facing_up ? -1 : 1);
		if (hitt_wall(cub, x_to_check, y_to_check))
		{
			horz_wall_hit_x = next_horz_touch_x;
            horz_wall_hit_y = next_horz_touch_y;
			break;
		}
		else
		{
			next_horz_touch_x += xstep;
			next_horz_touch_y += ystep;
			// LOGF(next_horz_touch_x, "next_horz_touch_x")
			// LOGF(next_horz_touch_y, "next_horz_touch_y")
			// LOGF(xstep, "xstep\t")
			// LOGF(ystep, "ystep\t")
			// printf("\n\n\n");
		}
	}
	// float horzHitDistance = found_horz_touch ? distanceBetweenPoints(
	// 		cub->player->player_x, cub->player->player_y, horz_wall_hit_x, horz_wall_hit_y)
	// : FLT_MAX;

	draw_l(cub, cub->px, cub->py, next_horz_touch_x , next_horz_touch_y, 0x0000FF);
	// draw_l(cub, cub->px, cub->py, horz_wall_hit_x , horz_wall_hit_y, 0x0000FF);
}

void	drow_rays(t_cub *cub)
{
	float ra;
	int	stripl;
	
	ra = cub->player->rotationangle - (FOV_ANGLE / 2);
	stripl = 0;
	while (stripl < NUM_RAYS)
	{
		cast_ray(cub, ra, stripl);
		ra -= FOV_ANGLE / NUM_RAYS;
		stripl++;
	}
}
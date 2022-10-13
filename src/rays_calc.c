/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:55:20 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/13 08:38:26 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	float	tmp;

	tmp = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (tmp);
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
	int 	fod_hoz_wall_hit = FALSE;
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
	xstep = TILE_SIZE / tan(ray_angle);
	xstep *= (is_ray_facing_left && xstep > 0) ? -1 : 1;
	xstep *= (is_ray_facing_right && xstep < 0) ? -1 : 1;
	float next_horz_touch_x = xintercept;
	float next_horz_touch_y = yintercept;
	
	int map_x = cub->s_map[0] * TILE_SIZE;
	int map_y = cub->s_map[1] * TILE_SIZE;

	float x_to_check;
	float y_to_check;
	while (next_horz_touch_x >= 0 && next_horz_touch_x <= map_x && next_horz_touch_y >= 0 && next_horz_touch_y <= map_y)
	{
		x_to_check = next_horz_touch_x;
		y_to_check = next_horz_touch_y + (is_ray_facing_up ? -1 : 1);
		if (is_it_hitt_wall(cub, x_to_check, y_to_check))
		{
			horz_wall_hit_x = next_horz_touch_x;
            horz_wall_hit_y = next_horz_touch_y;
			fod_hoz_wall_hit = TRUE;
			break;
		}
		else
		{
			next_horz_touch_x += xstep;
			next_horz_touch_y += ystep;
		}
	}
	int 	fod_vert_wall_hit = FALSE;
	float	vert_wall_hit_x = 0;
	float	vert_wall_hit_y = 0;
	int		vert_wall_content = 0;
	xintercept = floor(cub->px / TILE_SIZE ) * TILE_SIZE;
	xintercept += is_ray_facing_right ? TILE_SIZE : 0;
	yintercept = cub->py + (xintercept - cub->px) * tan(ray_angle);


	xstep = TILE_SIZE;
	xstep *= is_ray_facing_left ? -1 : 1;

	ystep = TILE_SIZE * tan(ray_angle);
	ystep *= (is_ray_facing_up && ystep > 0) ? -1 : 1;
	ystep *= (is_ray_facing_down && ystep < 0) ? -1 : 1;
	float next_vert_touch_x = xintercept;
	float next_vert_touch_y = yintercept;

	while (next_vert_touch_x >= 0 && next_vert_touch_x <= map_x && next_vert_touch_y >= 0 && next_vert_touch_y <= map_y)
	{
		x_to_check = next_vert_touch_x+ (is_ray_facing_left ? -1 : 1);
		y_to_check = next_vert_touch_y ;
		if (is_it_hitt_wall(cub, x_to_check, y_to_check))
		{
			vert_wall_hit_x = next_vert_touch_x;
            vert_wall_hit_y = next_vert_touch_y;
			fod_vert_wall_hit = TRUE;
			break;
		}
		else
		{
			next_vert_touch_x += xstep;
			next_vert_touch_y += ystep;
		}
	}
	float horz_hit_distance = fod_hoz_wall_hit ? distance_between_points(
		cub->px, cub->py, horz_wall_hit_x, horz_wall_hit_y)
	: FLT_MAX;
	float vert_hit_distance = fod_vert_wall_hit ? distance_between_points(
		cub->px, cub->py, vert_wall_hit_x, vert_wall_hit_y)
	: FLT_MAX;
	if (vert_hit_distance < horz_hit_distance)
	{
		cub->ray[stripl].distance = vert_hit_distance;
		cub->ray[stripl].wall_hit_x = vert_wall_hit_x;
		cub->ray[stripl].wall_hit_y = vert_wall_hit_y;
		cub->ray[stripl].was_hit_vertical = TRUE;
	}
	else
	{
		cub->ray[stripl].distance = horz_hit_distance;
		cub->ray[stripl].wall_hit_x = horz_wall_hit_x;
		cub->ray[stripl].wall_hit_y = horz_wall_hit_y;
		cub->ray[stripl].was_hit_vertical = FALSE;
	}
	cub->ray[stripl].ray_angle = ray_angle;
	cub->ray[stripl].is_ray_facing_no = is_ray_facing_down;
	cub->ray[stripl].is_ray_facing_so = is_ray_facing_up;
	cub->ray[stripl].is_ray_facing_we = is_ray_facing_left;
	cub->ray[stripl].is_ray_facing_ea = is_ray_facing_right;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:55:20 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/13 12:30:39 by mboukhal         ###   ########.fr       */
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
	cast_ray_init(cub);
	ray_angle = normalize_angle(ray_angle);
	cub->cs.is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	cub->cs.is_ray_facing_up = !cub->cs.is_ray_facing_down;
	cub->cs.is_ray_facing_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
	cub->cs.is_ray_facing_left = !cub->cs.is_ray_facing_right;
	cub->cs.yintercept = floor(cub->py / TILE_SIZE ) * TILE_SIZE;
	cub->cs.yintercept += cub->cs.is_ray_facing_down ? TILE_SIZE : 0;
	cub->cs.xintercept = cub->px + (cub->cs.yintercept - cub->py) / tan(ray_angle);
	cub->cs.ystep = TILE_SIZE;
	cub->cs.ystep *= cub->cs.is_ray_facing_up ? -1 : 1;
	cub->cs.xstep = TILE_SIZE / tan(ray_angle);
	cub->cs.xstep *= (cub->cs.is_ray_facing_left && cub->cs.xstep > 0) ? -1 : 1;
	cub->cs.xstep *= (cub->cs.is_ray_facing_right && cub->cs.xstep < 0) ? -1 : 1;
	float next_horz_touch_x = cub->cs.xintercept;
	float next_horz_touch_y = cub->cs.yintercept;
	
	int map_x = cub->s_map[0] * TILE_SIZE;
	int map_y = cub->s_map[1] * TILE_SIZE;

	float x_to_check;
	float y_to_check;
	while (next_horz_touch_x >= 0 && next_horz_touch_x <= map_x && next_horz_touch_y >= 0 && next_horz_touch_y <= map_y)
	{
		x_to_check = next_horz_touch_x;
		y_to_check = next_horz_touch_y + (cub->cs.is_ray_facing_up ? -1 : 1);
		if (is_it_hitt_wall(cub, x_to_check, y_to_check))
		{
			cub->cs.horz_wall_hit_x = next_horz_touch_x;
            cub->cs.horz_wall_hit_y = next_horz_touch_y;
			cub->cs.fod_hoz_wall_hit = TRUE;
			break;
		}
		else
		{
			next_horz_touch_x += cub->cs.xstep;
			next_horz_touch_y += cub->cs.ystep;
		}
	}
	int 	fod_vert_wall_hit = FALSE;
	float	vert_wall_hit_x = 0;
	float	vert_wall_hit_y = 0;
	int		vert_wall_content = 0;
	cub->cs.xintercept = floor(cub->px / TILE_SIZE ) * TILE_SIZE;
	cub->cs.xintercept += cub->cs.is_ray_facing_right ? TILE_SIZE : 0;
	cub->cs.yintercept = cub->py + (cub->cs.xintercept - cub->px) * tan(ray_angle);


	cub->cs.xstep = TILE_SIZE;
	cub->cs.xstep *= cub->cs.is_ray_facing_left ? -1 : 1;

	cub->cs.ystep = TILE_SIZE * tan(ray_angle);
	cub->cs.ystep *= (cub->cs.is_ray_facing_up && cub->cs.ystep > 0) ? -1 : 1;
	cub->cs.ystep *= (cub->cs.is_ray_facing_down && cub->cs.ystep < 0) ? -1 : 1;
	float next_vert_touch_x = cub->cs.xintercept;
	float next_vert_touch_y = cub->cs.yintercept;

	while (next_vert_touch_x >= 0 && next_vert_touch_x <= map_x && next_vert_touch_y >= 0 && next_vert_touch_y <= map_y)
	{
		x_to_check = next_vert_touch_x+ (cub->cs.is_ray_facing_left ? -1 : 1);
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
			next_vert_touch_x += cub->cs.xstep;
			next_vert_touch_y += cub->cs.ystep;
		}
	}
	float horz_hit_distance = cub->cs.fod_hoz_wall_hit ? distance_between_points(
		cub->px, cub->py, cub->cs.horz_wall_hit_x, cub->cs.horz_wall_hit_y)
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
		cub->ray[stripl].wall_hit_x = cub->cs.horz_wall_hit_x;
		cub->ray[stripl].wall_hit_y = cub->cs.horz_wall_hit_y;
		cub->ray[stripl].was_hit_vertical = FALSE;
	}
	cub->ray[stripl].ray_angle = ray_angle;
	cub->ray[stripl].is_ray_facing_no = cub->cs.is_ray_facing_down;
	cub->ray[stripl].is_ray_facing_so = cub->cs.is_ray_facing_up;
	cub->ray[stripl].is_ray_facing_we = cub->cs.is_ray_facing_left;
	cub->ray[stripl].is_ray_facing_ea = cub->cs.is_ray_facing_right;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:56:33 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/01 22:31:57 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static float	normalize_angle(float angle)
{
	angle = remainder(angle, TOW_PI);
	if (angle < 0)
		angle = TOW_PI + angle;
	return (angle);
}

void	cast_ray(t_cub *cub, float ra, int stripl)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	int		is_ray_facing_left;

	int 	fod_hoz_wall_hit = False;
	float	horz_wall_hit_x = 0;
	float	horz_wall_hit_y = 0;
	int		horz_wall_content = 0;

	ray_angle = normalize_angle(ray_angle);
	is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	is_ray_facing_up = !is_ray_facing_down;
	is_ray_facing_right = ray_angle < (0.5 * PI) || ray_angle > (0.5 * PI);
	is_ray_facing_left = !is_ray_facing_right;

	yintercept = floor(cub->player->player_y / TILE_SIZE) * TILE_SIZE;
	yintercept += is_ray_facing_down ? TILE_SIZE : 0;

	xintercept = cub->player->player_x + (yintercept - cub->player->player_y) / tan(ray_angle);

	ystep = TILE_SIZE;
	ystep *= is_ray_facing_up ? -1 : 1;

	xstep = TILE_SIZE / tan(ray_angle);
	xstep *= (is_ray_facing_left && xstep > 0) ? -1 : 1;
	xstep *= (is_ray_facing_right && xstep < 0) ? -1 : 1;
	
	float next_horz_touch_x = xintercept;
	float next_horz_touch_y = yintercept;

	while (next_horz_touch_x >= 0 && next_horz_touch_x <= WIN_H && next_horz_touch_y >= 0 && next_horz_touch_y <= WIN_W)
	{
		float x_to_check = next_horz_touch_x;
		float y_to_check = next_horz_touch_y + (is_ray_facing_up ? -1 : 1);
		if (map_has_wall_at(x_to_check, y_to_check))
		{
			horz_wall_hit_x = next_horz_touch_x;
			horz_wall_hit_y = next_horz_touch_y;
			horz_wall_content = cub->map[(int)floor(y_to_check / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)];
			found_horz_touch = true;
			break;
		}
		else
		{
			next_horz_touch_x += xstep;
			next_horz_touch_y += ystep;
		}
	}

}


void	drow_rays(t_cub *cub)
{
	float ra;
	int	stripl;
	
	ra = cub->player->rotationangle - (FOV_ANGLE / 2);
	stripl = -1;
	while (++stripl < NUM_RAYS)
	{
		cast_ray(cub, ra, stripl);
		ra += FOV_ANGLE / NUM_RAYS;
	}
}
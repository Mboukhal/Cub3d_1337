/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_action.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:37:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/09 16:20:47 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GAME_ACTION_H
# define GAME_ACTION_H

# include "cub.h"

# define UP_KEY				13
# define DOWN_KEY			1
# define RIGHT_KEY			2
# define LEFT_KEY			0
# define EXIT_BOTTON		17

# define L_ARROW_KEY		123
# define R_ARROW_KEY		124

# define ELEMENT_SIZE		250

# define WIN_W				1600
# define WIN_H				900

# define MINI_BG			860
# define FLT_MAX			3.402823466e+38F

void	drow_row_minimap(t_cub *c);
void	drow_minimap(t_cub *c);
void	drow_floor_and_ceilling(t_cub *c);
void	create_trgb(int *rgb, int *color);
void	update_image(t_cub *cub);
void	moveplayer(t_cub *cub);
void	minimap_manip(t_cub *cub);
void	put_image(t_cub *cub, int *coord_i, int empty);
void	key_w_s(t_cub *cub, int i);
void	key_a(t_cub *cub);
void	key_d(t_cub *cub);
void	key_rotate(t_cub *cub, int i);
int		draw_line(t_cub *cub, int begin_x, int begin_y, int end_x, int end_y, int color);
float	normalize_angle(float angle);
int		is_it_hitt_wall(t_cub *cub, float x, float y);
void	cast_ray(t_cub *cub, float ra, int stripl);
void	drow_rays(t_cub *cub);
void	rander_reys(t_cub *cub);
void	generate_3d_projection(t_cub *cub);

#endif
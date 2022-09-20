/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_action.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:37:31 by mboukhal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/20 09:53:14 by ahmaidi          ###   ########.fr       */
=======
/*   Updated: 2022/09/19 16:58:25 by mboukhal         ###   ########.fr       */
>>>>>>> 0d1b9d3c1192a65e0c9a69dfe350928578146ca0
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

void	drow_row_minimap(t_cub *c);
void	drow_minimap(t_cub *c);
void	drow_floor_and_ceilling(t_cub *c);
void	create_trgb(int *rgb, int *color);
void	update_image(t_cub *cub);
void	moveplayer(t_cub *cub);
void	minimap_manip(t_cub *cub);
<<<<<<< HEAD
void	key_w(t_cub *cub);
void	key_a(t_cub *cub);
void	key_d(t_cub *cub);
void	key_s(t_cub *cub);
void	key_rotate_right(t_cub *cub);
void	key_rotate_left(t_cub *cub);
void	put_image(t_cub *cub, int *coord, int *coord_i, int empty);
=======
void	key_W_S(t_cub *cub, int i);
void	key_A(t_cub *cub);
void	key_D(t_cub *cub);
void	key_rotate(t_cub *cub, int i);

>>>>>>> 0d1b9d3c1192a65e0c9a69dfe350928578146ca0

#endif
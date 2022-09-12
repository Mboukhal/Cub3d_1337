/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_action.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:37:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/12 19:10:03 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

# define UP_KEY			13
# define DOWN_KEY		1
# define RIGHT_KEY		2
# define LEFT_KEY		0
# define EXIT_BOTTON	17
# define L_ARROW_KEY		124
# define R_ARROW_KEY		123

# define ELEMENT_SIZE	250

# define WIN_W			1600
# define WIN_H			900

void	drow_row_minimap(t_cub *c);
void	drow_minimap(t_cub *c);
void	drow_floor_and_ceilling(t_cub *c);
void	create_trgb(int *rgb, int *color);
void	set_buffer(char *buffer, int color);
void	update_image(t_cub *cub);
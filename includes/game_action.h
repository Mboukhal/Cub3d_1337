/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_action.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:37:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/11 18:22:34 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

#define MINIH		WIN_H / 10
#define MINIW		WIN_W / 10
#define ONE_ROW		WIN_W * 4

void	drow_row_minimap(t_cub *c);
void	drow_minimap(t_cub *c);
void	drow_floor_and_ceilling(t_cub *c);
void	create_trgb(int *rgb, int *color);
void	set_buffer(char *buffer, int color);
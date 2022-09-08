/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:36:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/08 16:39:42 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static void	test_component(int *iter, int x, int y, t_cub *comp)
{
	if (comp->map[iter[0]][iter[1]] == '1')
		mlx_put_image_to_window(comp->mlx, comp->win, comp->wall, x, y);
	if (comp->map[iter[0]][iter[1]] == '0')
		mlx_put_image_to_window(comp->mlx, comp->win,
			comp->empty, x, y);
	if (comp->map[iter[0]][iter[1]] == 'C')
		mlx_put_image_to_window(comp->mlx, comp->win, comp->fish, x, y);
	if (comp->map[iter[0]][iter[1]] == 'E')
		mlx_put_image_to_window(comp->mlx, comp->win, comp->exit, x, y);
	if (comp->map[iter[0]][iter[1]] == 'P')
	{
		comp->pp_index[0] = y;
		comp->pp_index[1] = x;
		comp->pp_line[0] = iter[0];
		comp->pp_line[1] = iter[1];
		mlx_put_image_to_window(comp->mlx, comp->win,
			comp->player_d, x, y);
	}
}

 static void	set_map(t_cub *C)
{
	int	iter[2];
	int	x;
	int	y;

	iter[0] = 0;
	x = 0;
	y = 0;
	while (C->map[iter[0]])
	{
		iter[1] = 0;
		x = 0;
		while (C->map[iter[0]][iter[1]])
		{
			test_component(iter, x, y, C);
			iter[1]++;
			x += ELEMENT_SIZE;
		}
		y += ELEMENT_SIZE;
		iter[0]++;
	}
}
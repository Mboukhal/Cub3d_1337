/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:33:06 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/12 19:14:43 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"


// void set(t_cub *c)
// {
// 	int index[2];
// 	int color[2];
// 	int pixel;
// 	char *buffer;

// 	buffer = c->bf;
// 	// buffer = mlx_get_data_addr(c->image->tmplet, i, &i[1], &i[2]);
// 	index[0] = -1;
// 	// color[0] = create_trgb(0,0,0);
// 	// color[1] = create_trgb(200,200,0);
// 	while (++index[0] < WIN_H)
// 	{
// 		index[1] = -1;
// 		while (++index[1] < WIN_W)
// 		{
// 			// TODO: need more info
// 			pixel = (index[0] * c->bf_in) + (index[1] * 4);
// 			if (index[0] > (WIN_H / 2) - 1 )
// 				set_buffer(&buffer[pixel], color[0]);
// 			// else
// 			// 	set_buffer(&buffer[pixel], color[1]);
// 		}
// 	}

// 	// int i = -1;
// 	// int row_num = 1;
// 	// int drow_counter = 1;
// 	// int drow = 1;
// 	// while (bf[++i])
// 	// {

// 	// 	printf("%c", bf[i]);
// 	// 	bf[i] = 20;
// 	// 	// if (i == (ONE_ROW * (row_num++)))
// 	// 	// 	drow = 1;
// 	// 	// if (drow)
// 	// 	// {
// 	// 		// bf[i] = 0;
// 	// 	// 	drow_counter++;
// 	// 	// }
// 	// }
// }


// void	drow_row_minimap(t_cub *c)
// {

// 	set (c);
// 	// int i;

// 	// i = -1;
// 	// while (c->bf[--i])
// 	// {
// 	// 	rect();
// 	// }
// }
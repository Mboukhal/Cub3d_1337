/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:28:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/24 09:28:11 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB_H__
# define __CUB_H__

# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include "utils.h"

# define UP_KEY			13
# define DOWN_KEY		1
# define RIGHT_KEY		2
# define LEFT_KEY		0
# define EXIT_BOTTON	17

typedef	struct cub
{
	int 	i;
	void	*mlx;
	void	*mlx_win;
	char	**map;
}	t_cub;


int		deal_key(int key, t_cub *cub);
int		exit_game(t_cub *cub);
void	init(t_cub *cub);
void	check_exteniton(char *file);
void	map_init(char *file, t_cub *cub);
void	start_game(t_cub *cub);
// void	key_right(cub);
// void	key_left(cub);
// void	key_down(cub);
// void	key_up(cub);

#endif /* __CUB_H__ */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:26:45 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/01 23:04:59 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init(t_cub *cub)
{
	cub->map = NULL;
	cub->tab_txt_c = NULL;
	cub->size_tab = 0;
	// cub->mlx = mlx_init();
	// cub->mlx_win = mlx_new_window(cub->mlx, 2880, 1620, "Cub3d");
}

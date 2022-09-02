/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:11:45 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/09/02 22:22:05 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"


void	affiche_cub(t_cub *cub)
{
	int	i;

	printf("\n");
	while (cub->size_tab > 0)
	{
		i = 0;
		while (cub->tab_txt_c[cub->size_tab - 1].splt[i])
		{
			printf("type == %d || str == %s \n", cub->tab_txt_c[cub->size_tab - 1].type, cub->tab_txt_c[cub->size_tab - 1].splt[i]);
			i++;
		}
		cub->size_tab--;
	}
}

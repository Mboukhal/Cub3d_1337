/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:11:45 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/09/20 11:20:36 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	affiche_cub(t_cub *cub)
{
	int	i;
	int	j;
		// while (cub->size_tab > 0)
		// {
		// 	i = 0;
		// 	while (cub->tab_txt_c[cub->size_tab - 1].splt[i])
		// 	{
		// 		printf("type == %d || str == %s \n", \
		// 		cub->tab_txt_c[cub->size_tab - 1].type, \
		// 		cub->tab_txt_c[cub->size_tab - 1].splt[i]);
		// 		i++;
		// 	}
		// 	cub->size_tab--;
		// }
	i = 0;
	printf("======= MAP========\n");
	if (cub->size_map == 0)
		return ;
	while (cub->map[i])
	{
		j = 0;
		while(cub->map[i][j])
		{
			printf("%c ==> (%d, %d)\n", cub->map[i][j], i , j);
			j++;
		}
		i++;
	}
}

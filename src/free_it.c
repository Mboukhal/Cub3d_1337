/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:49:21 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/09/05 15:51:49 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_it_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

void	free_cub(t_cub *cub)
{
	printf("size_tab == %d || size_map == %d\n", cub->size_tab, cub->size_map);
	affiche_cub(cub);
	while (cub->size_tab > 0)
	{
		free_it_split(cub->tab_txt_c[cub->size_tab - 1].splt);
		cub->size_tab--;
	}
	free(cub->tab_txt_c);
	while (cub->size_map > 0)
	{
		if (cub->map[cub->size_map])
			free(cub->map[cub->size_map]);
		cub->size_map--;
	}
	free(cub->map);
	free(cub);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:49:21 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/09/02 22:08:53 by ahmaidi          ###   ########.fr       */
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
		i++;
	}
	free(s);
}

void	free_cub(t_cub *cub)
{
	printf("here %d\n", cub->size_tab);
	while (cub->size_tab > 0)
	{
		free_it_split(cub->tab_txt_c[cub->size_tab - 1].splt);
		cub->size_tab--;
	}
	free(cub->tab_txt_c);

}

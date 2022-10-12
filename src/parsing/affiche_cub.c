/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:11:45 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/10/12 18:46:33 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	affiche_cub(t_cub *cub)
{
	int	i;
	int	j;

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

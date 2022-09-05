/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:23:06 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/09/05 21:46:38 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	check(char c)
{
	if (c != '0' && c != 'N' && c != 'S' && c != 'W'
		&& c != 'E' && c != '1')
		return (1);
	return (0);
}

int	check_around_zero(t_cub **cub)
{
	int	i;
	int	j;

	i = 1;
	while ((*cub)->map[i + 1])
	{
		j = 0;
		while ((*cub)->map[i][j])
		{
			if ((*cub)->map[i][j] == '0' || (*cub)->map[i][j] == 'N'
			|| (*cub)->map[i][j] == 'S' || (*cub)->map[i][j] == 'W'
			|| (*cub)->map[i][j] == 'E')
			{
				if (check((*cub)->map[i - 1][j]) || check((*cub)->map[i + 1][j])
			|| check((*cub)->map[i][j - 1]) || check((*cub)->map[i][j + 1]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(t_cub **cub)
{
	if (check_walls((*cub)->map, (*cub)->size_map))
		ft_error();
	add_front_plus(cub);
	add_back_plus(cub);
	if (!check_around_zero(cub))
		ft_error();
	affiche_cub(*cub);
}

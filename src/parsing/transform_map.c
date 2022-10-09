/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:02:43 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/10/08 18:54:12 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_action.h"

void	add_plus(t_cub **cub, int j)
{
	size_t	i;
	char	*temp;

	i = 0;
	while ((*cub)->map[i])
	{
		temp = (*cub)->map[i];
		(*cub)->map[i] = ft_substr((*cub)->map[i], j, \
		ft_strlen((*cub)->map[i]) - j);
		free(temp);
		i++;
	}
}

void	add_front_plus(t_cub **cub)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*temp;

	i = 0;
	len = ft_strlen((*cub)->map[0]);
	while ((*cub)->map[i])
	{
		j = 0;
		while ((*cub)->map[i][j] == ' ' || (*cub)->map[i][j] == '\t')
			j++;
		if (j < len)
			len = j;
		i++;
	}
	add_plus(cub, len);
}

static void	check_map_size(t_cub *cub, int i, int len)
{
	// if (len > 36 || i > 36)
	if (len > (WIN_W / TILE_SIZE) || i > (WIN_H / TILE_SIZE))
	{
		ft_putstr_fd("ERROR:\n\t\e[31mInvalid map size!\e[00m\n", 2);
		exit(1);
	}
	cub->s_map[0] = len;
	cub->s_map[1] = (int) i;
}

void	add_back(t_cub **cub, int len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while ((*cub)->map[i])
	{
		j = len - ft_strlen((*cub)->map[i]);
		while (j > 0)
		{
			temp = (*cub)->map[i];
			(*cub)->map[i] = ft_strjoin((*cub)->map[i], "+");
			free(temp);
			j--;
		}
		i++;
	}
	check_map_size(*cub, (int)i, len);
}

void	add_back_plus(t_cub *cub)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(cub->map[0]);
	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j] == ' ' || cub->map[i][j] == '\t')
		{
			cub->map[i][j] = '+';
			j++;
		}
		i++;
	}
	i = 0;
	while (cub->map[i])
	{
		if (len < ft_strlen(cub->map[i]))
			len = ft_strlen(cub->map[i]);
		i++;
	}
	add_back(&cub, len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:46:11 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/09/02 22:34:51 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"


int	get_texture(char *str, t_cub **cub, int i)
{
	char	**texture;

	if (i == 0 && *str != 'O' && (*(str + 1) == ' ' || *(str + 1) == '\t'))
		return (0);
	else if (i == 1 && *str != 'O' && (*(str + 1) == ' ' || *(str + 1) == '\t'))
		return (0);
	else if (i == 2 && *str != 'E' && (*(str + 1) == ' ' || *(str + 1) == '\t'))
		return (0);
	else if (i == 3 && *str != 'A' && (*(str + 1) == ' ' || *(str + 1) == '\t'))
		return (0);
	str++;
	while (*str == ' ' || *str == '\t')
		str++;
	texture = ft_split(str, '\n');
	(*cub)->size_tab += 1;
	(*cub)->tab_txt_c = ft_realloc((*cub)->tab_txt_c, sizeof(t_txt_c) * \
	(*cub)->size_tab - 1, sizeof(t_txt_c) * (*cub)->size_tab);
	(*cub)->tab_txt_c[(*cub)->size_tab - 1].splt = texture;
	(*cub)->tab_txt_c[(*cub)->size_tab - 1].type = i;
	return (1);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	get_color(char *str, t_cub **cub, int i)
{
	char	**rgb;
	int		index;

	index = 0;
	if (*str != ' ' && *str != '\t')
		return (0);
	while (*str == ' ' || *str == '\t')
		str++;
	str[ft_strlen(str) - 1] = '\0';
	rgb = ft_split(str, ',');
	while (rgb[index] != NULL)
	{
		if (ft_isnumber(rgb[index]) && (ft_atoi(rgb[index]) >= 0 \
		|| ft_atoi(rgb[index]) <= 255))
			index++;
		else
			break ;
	}
	if (rgb[index] != NULL)
	{
		free_it_split(rgb);
		return (0);
	}
	(*cub)->size_tab += 1;
	(*cub)->tab_txt_c = ft_realloc((*cub)->tab_txt_c, sizeof(t_txt_c) * \
	(*cub)->size_tab - 1, sizeof(t_txt_c) * (*cub)->size_tab);
	(*cub)->tab_txt_c[(*cub)->size_tab - 1].splt = rgb;
	(*cub)->tab_txt_c[(*cub)->size_tab - 1].type = i;
	return (1);
}

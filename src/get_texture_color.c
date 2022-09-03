/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:46:11 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/09/03 19:40:57 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	allocate(t_cub **cub, char **str, int type)
{
	(*cub)->size_tab += 1;
	(*cub)->tab_txt_c = ft_realloc((*cub)->tab_txt_c, sizeof(t_txt_c) * \
	(*cub)->size_tab - 1, sizeof(t_txt_c) * (*cub)->size_tab);
	(*cub)->tab_txt_c[(*cub)->size_tab - 1].splt = str;
	(*cub)->tab_txt_c[(*cub)->size_tab - 1].type = type;
}

int	check_path(char *str, t_cub **cub, int i)
{
	int		fd;
	char	**texture;
	char	*pth;

	str++;
	while (*str == ' ' || *str == '\t')
		str++;
	texture = ft_split(str, '\n');
	pth = ft_strjoin(texture[0], ".xpm");
	fd = open(pth, O_RDONLY, 664);
	free (pth);
	if (ft_strncmp(pth, "./", 2) || fd < 0)
	{
		free_it_split(texture);
		write(2, "One of the textures doesn't exit OR Permission denied\n", 54);
		return (0);
	}
	close(fd);
	allocate(cub, texture, i);
	return (1);
}

int	get_texture(char *str, t_cub **cub, int i)
{
	if (i == 0 && *str == 'O' && (*(str + 1) == ' ' || *(str + 1) == '\t'))
		return (check_path(str, cub, i));
	if (i == 1 && *str == 'O' && (*(str + 1) == ' ' || *(str + 1) == '\t'))
		return (check_path(str, cub, i));
	if (i == 2 && *str == 'E' && (*(str + 1) == ' ' || *(str + 1) == '\t'))
		return (check_path(str, cub, i));
	if (i == 3 && *str == 'A' && (*(str + 1) == ' ' || *(str + 1) == '\t'))
		return (check_path(str, cub, i));
	return (0);
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
		&& ft_atoi(rgb[index]) <= 255))
			index++;
		else
			break ;
	}
	if (rgb[index] != NULL || index != 3)
	{
		free_it_split(rgb);
		return (0);
	}
	allocate(cub, rgb, i);
	return (1);
}

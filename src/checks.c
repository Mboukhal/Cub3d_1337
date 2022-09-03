/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:18:43 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/03 21:58:29 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_exteniton(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (ft_strncmp(&file[size - 4], ".cub", 4))
	{
		ft_putstr_fd("ERROR\n\t\e[0;31m", STDERR_FILENO);
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": is not a \".cub\" file :(\e[0m\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	find_texture_or_colors(char *str, t_cub **cub)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == 'N')
		return (get_texture(str + 1, cub, 0));
	else if (*str == 'S')
		return (get_texture(str + 1, cub, 1));
	else if (*str == 'W')
		return (get_texture(str + 1, cub, 2));
	else if (*str == 'E')
		return (get_texture(str + 1, cub, 3));
	else if (*str == 'F')
		return (get_color(str + 1, cub, 4));
	else if (*str == 'C')
		return (get_color(str + 1, cub, 5));
	else
		return (0);
}

void	free_error(char *str, char *s, t_cub *cub)
{
	free(str);
	free(s);
	free_cub(cub);
	write(2, "invalid map\n", 12);
	exit(1);
}

void	filling_map(t_cub **cub, char *str)
{
	str[ft_strlen(str) - 1] = '\0';
	++(*cub)->size_map;
		(*cub)->map = ft_realloc((*cub)->map, sizeof(char *) * \
	(*cub)->size_map - 1, sizeof(char *) * (*cub)->size_map + 1);
	(*cub)->map[(*cub)->size_map - 1] = ft_strdup(str);
	(*cub)->map[(*cub)->size_map] = NULL;
}

int	check_up_down_walls(char *s1, char *s2)
{
	int	i;

	i = 1;
	while (s1[i])
	{
		if (s1[i] != '1' && s1[i] != ' ')
			break ;
		i++;
	}
	if (s1[i] != '\0')
		return (1);
	i = 1;
	while (s2[i])
	{
		if (s2[i] != '1' && s2[i] != ' ')
			break ;
		i++;
	}
	if (s2[i] != '\0')
		return (1);
	return (0);
}

int	check_walls(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		while (*map[i] == ' ')
			map[i]++;
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		i++;
	}
	if (check_up_down_walls(map[0], map[size - 1]))
		return (1);
	return (0);
}

void	check_map(t_cub *cub)
{
	int	i;

	i = 1;
	if (check_walls(cub->map, cub->size_map))
	{
		free_cub(cub);
		write(2, "ERROR\n", 6);
		exit(1);
	}
}

int	parser_file(int fd, t_cub **cub)
{
	char	*str;
	int		in_map;
	int		prev;
	char	*str_depl;

	in_map = 0;
	str_depl = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		prev = in_map;
		if (*str == '\n')
		{
			free(str);
			str = get_next_line(fd);
			continue ;
		}
		else
		{
			if (in_map == 6)
				filling_map(cub, str);
			in_map += find_texture_or_colors(str, cub);
			if ((in_map == prev && in_map != 6) || \
			(!ft_strncmp(str_depl, str, 2) && in_map != 6))
				free_error(str, str_depl, *cub);
		}
		free(str_depl);
		str_depl = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
	}
	free(str_depl);
	check_map(*cub);
	//affiche_cub(*cub);
	return (1);
}

/*
	TODO:load file to cub structure
	check map skip space and check for '1' or '\n' without skipping
*/
void	map_init(char *file, t_cub *cub)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror (file);
		exit (EXIT_FAILURE);
	}
	init(cub);
	parser_file(fd, &cub);
	cub->i = 0;
	close(fd);
}

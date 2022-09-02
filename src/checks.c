/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:18:43 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/02 22:19:58 by ahmaidi          ###   ########.fr       */
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

int	parser_file(int fd, t_cub **cub)
{
	char	*str;
	int		in_map;
	int		prev;

	in_map = 0;
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
				printf("this the map : %s", str);
			in_map += find_texture_or_colors(str, cub);
			if (in_map == prev && in_map != 6)
			{
				free_cub(*cub);
				write(2, "invalid map\n", 12);
				exit(1);
			}
		}
		free(str);
		str = get_next_line(fd);
	}
	affiche_cub(*cub);
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

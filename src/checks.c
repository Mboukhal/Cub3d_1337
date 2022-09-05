/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:18:43 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/05 22:45:15 by ahmaidi          ###   ########.fr       */
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

void	compare(char *s1, char *s2)
{
	while (*s1 == ' ' || *s1 == '\t')
		s1++;
	while (*s2 == ' ' || *s2 == '\t')
		s2++;
	if (!ft_strncmp(s1, s2, 2))
		ft_error();
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
		remove_last_spaces(&str);
		if (*str == '\0' && !(*cub)->in_map)
		{
			free(str);
			str = get_next_line(fd);
			continue ;
		}
		else
		{
			if (in_map != 6)
				compare(str_depl, str);
			if (in_map == 6)
				filling_map(cub, str);
			in_map += find_texture_or_colors(str, cub);
			if ((in_map == prev && in_map != 6))
			{
				printf("here\n");
				ft_error();
			}
		}
		free(str_depl);
		str_depl = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
	}
	free(str_depl);
	remove_last_nl(cub);
	//affiche_cub(*cub);
	check_map(cub);
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

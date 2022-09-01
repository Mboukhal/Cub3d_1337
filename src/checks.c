/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:18:43 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/01 14:29:27 by mboukhal         ###   ########.fr       */
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
	close(fd);
	init(cub);
	cub->i = 0;
}
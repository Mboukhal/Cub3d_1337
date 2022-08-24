/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:18:43 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/24 09:29:41 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_exteniton(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (ft_strncmp(&file[size - 5], ".cub", 5))
	{
		ft_putstr_fd("ERROR\n\t\e[0;31m", STDERR_FILENO);
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": is not a \".ber\" file :(\e[0m\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	map_init(char *file, t_cub *cub)
{
	int	fd;

    fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror (file);
		exit (EXIT_FAILURE);
	}
	// file loading
	close(fd);
	init(cub);
	cub->i = 0;
}
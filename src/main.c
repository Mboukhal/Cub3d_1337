/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:28:01 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/01 22:50:13 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int ac, char **av)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub) * 1);
	if (!cub)
		return (1);
	errno = 0;
	if (ac != 2)
	{
		ft_putstr_fd("ERROR\n\t\e[31mNeed map file :(\e[0m\n",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	check_exteniton(av[1]);
	map_init(av[1], cub);
	// start_game(&cub);
	// system("leaks cub3d");
	return (EXIT_SUCCESS);
}

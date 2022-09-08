/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:28:01 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/08 16:54:58 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int ac, char **av)
{
	t_cub	*cub;

	errno = 0;
	if (ac != 2)
	{
		ft_putstr_fd("ERROR\n\t\e[31mNeed map file :(\e[0m\n",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	check_exteniton(av[1], ".cub");
	cub = map_init(av[1]);
	// start_game(&cub);
	return (EXIT_SUCCESS);
}

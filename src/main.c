/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:28:01 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/13 10:09:37 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	update_image(t_cub *cub)
{
	moveplayer(cub);
	generate_3d_projection(cub);
	if (cub->key_minimap)
		rander_reys(cub);
}

int	main(int ac, char **av)
{
	t_cub	*cub;
	int		color;

	errno = 0;
	if (ac != 2)
	{
		ft_putstr_fd("ERROR\n\t\e[31mNeed map file :(\e[0m\n",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	check_exteniton(av[1], ".cub");
	cub = map_init(av[1]);
	start_game(cub);
	return (EXIT_SUCCESS);
}

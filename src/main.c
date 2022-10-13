/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:28:01 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/13 11:24:00 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	moveplayer(t_cub *cub)
{
	float	movestep;

	set_map(cub, 0);
	cub->player->rotationangle = normalize_angle(cub->player->rotationangle);
	cub->player->rotationangle += cub->player->turndirection * \
	cub->player->turnspeed;
	movestep = cub->player->walkdirection * cub->player->walkspeed;
	if (!is_it_hitt_wall(cub, (cub->px + cos(cub->player->rotationangle \
		+ cub->player->turnleft) * movestep), \
		(cub->py + sin(cub->player->rotationangle \
		+ cub->player->turnleft) * movestep)))
	{
		cub->px += cos(cub->player->rotationangle
				+ cub->player->turnleft) * movestep;
		cub->py += sin(cub->player->rotationangle
				+ cub->player->turnleft) * movestep;
	}
	drow_rays(cub);
}

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

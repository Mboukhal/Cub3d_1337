/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:52:50 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/24 11:21:28 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void *var_init(int size)
{
	char *ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

void	free_it(void *ptr)
{
	int		i;
	char    *p;

	p = (char *)ptr;
	i = -1;
	while (p[++i])
		p[i] = 0;
	free(ptr);
}

void	*ft_realloc(void *ptr, int size)
{
	char	*tmp;
	int		i;
	char	*p;

	p = (char *) ptr;
	tmp = malloc(size);
	if (!tmp)
		return (NULL);
	i = -1;
	while (p[++i])
		tmp[i] = p[i];
	tmp[i] = p[i];
	free(p);
	return (tmp);
}
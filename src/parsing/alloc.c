/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:52:50 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/08 18:43:05 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	*var_init(int size)
{
	char	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

void	free_it(void *ptr)
{
	int		i;
	char	*p;

	p = (char *)ptr;
	i = -1;
	while (p[++i])
		p[i] = 0;
	free(ptr);
}

void	*ft_realloc(void *old_alloc, size_t old_size, size_t new_size)
{
	unsigned char	*old_alloc_t;
	unsigned char	*new_alloc;
	size_t			i;

	i = 0;
	if (old_alloc == NULL)
		return (malloc(new_size));
	old_alloc_t = (unsigned char *)old_alloc;
	new_alloc = (unsigned char *)malloc(new_size);
	if (new_alloc == NULL)
		return (NULL);
	while (i < old_size && i < new_size)
	{
		new_alloc[i] = old_alloc_t[i];
		i++;
	}
	free(old_alloc);
	return (new_alloc);
}
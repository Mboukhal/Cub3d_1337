/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:08:59 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/02 21:56:33 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"

// void	*ft_realloc(void *ptr, int size);
void	*ft_realloc(void *old_alloc, size_t old_size, size_t new_size);
void	free_it(void *ptr);
void	*var_init(int size);

#endif /* __UTILS_H__ */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:08:59 by mboukhal          #+#    #+#             */
/*   Updated: 2022/08/24 11:31:57 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_H__
#define __UTILS_H__

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../src/libft/libft.h"

void	*ft_realloc(void *ptr, int size);
void	free_it(void *ptr);
void 	*var_init(int size);

#endif /* __UTILS_H__ */
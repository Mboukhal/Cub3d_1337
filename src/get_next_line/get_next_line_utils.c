/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:25:14 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/09/01 22:50:39 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_g(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_g(char const *s1, char const *s2)
{
	char			*str_join;
	size_t			len;
	unsigned int	i;

	if (!s1 && s2)
		return (ft_strdup_g(s2));
	i = 0;
	len = ft_strlen_g(s1) + ft_strlen_g(s2);
	str_join = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_join)
		return (NULL);
	while (s1[i])
	{
		str_join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str_join[i + ft_strlen_g(s1)] = s2[i];
		i++;
	}
	str_join[i + ft_strlen_g(s1)] = '\0';
	free((char *)s1);
	return (str_join);
}

int	ft_strchr_g(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c)
	{
		if (!s)
			return (0);
		while (s[i] != '\0')
		{
			if (s[i] == (char)c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_strdup_g(const char *s1)
{
	int		len;
	char	*cpy;
	int		i;

	len = ft_strlen_g(s1);
	cpy = (char *) malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_substr_g(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen_g(s))
		return (ft_strdup_g(""));
	if (len > (ft_strlen_g(s) - start))
		len = ft_strlen_g(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	else
	{
		while (i < len && s[i + start])
		{
			substr[i] = s[i + start];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}

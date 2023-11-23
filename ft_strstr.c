/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:24:35 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/22 19:49:20 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "CUBE3D.h"

void	initialise_1(size_t *i, size_t *j, size_t *k, size_t *cmp)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*cmp = 0;
}

void	initialise2(size_t *k, size_t *j, size_t *i, size_t *cmp)
{
	*k = 0;
	*j = *i;
	*cmp = 0;
}

void	increment(size_t *j, size_t *k)
{
	*j = *j + 1;
	*k = *k + 1;
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	cmp;

	if (!haystack || !needle)
		return (0);
	if (haystack == 0)
		return (0);
	initialise_1 (&i, &j, &i, &cmp);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < ft_strlen(haystack))
	{
		initialise2(&k, &j, &i, &cmp);
		while (haystack[j] && needle[k])
		{
			cmp_ne_hay(needle[k], haystack[j], &cmp);
			increment (&j, &k);
		}
		if (cmp == ft_strlen(needle))
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

char	*ft_strstr_2(char *haystack, char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	cmp;

	if (haystack == 0)
		return (0);
	initialise_1 (&i, &j, &i, &cmp);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < ft_strlen(haystack))
	{
		initialise2(&k, &j, &i, &cmp);
		while (haystack[j] && needle[k])
		{
			if (needle[k] == haystack[j])
				cmp++;
			increment (&j, &k);
		}
		if (cmp == ft_strlen(needle))
			return (needle);
		i++;
	}
	return (0);
}

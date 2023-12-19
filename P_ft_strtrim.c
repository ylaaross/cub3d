/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_ft_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:18:18 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 19:47:17 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "P_CUBE3D.h"
#include <stdlib.h>
#include <string.h>

int	firstindex(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	boolean;

	j = 0;
	i = 0;
	boolean = 0;
	while (s1[i])
	{
		j = 0;
		boolean = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				boolean = 1;
				break ;
			}
			j++;
		}
		if (!boolean)
			return (i);
		i++;
	}
	return (0);
}

int	lastindex(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	boolean;

	i = ft_strlenp(s1) - 1;
	j = 0;
	boolean = 0;
	while (i >= 0)
	{
		j = 0;
		boolean = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				boolean = 1;
				break ;
			}
			j++;
		}
		if (!boolean)
			return (i);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		fi;
	int		li;
	char	*s;

	if (!s1)
		return (0);
	if (ft_strlenp(s1) == 1 && ft_strlenp(set) == 1 && set[0] != s1[0])
	{
		s = ft_calloc(2, sizeof(char));
		s[0] = s1[0];
		return (s);
	}
	fi = firstindex(s1, set);
	li = lastindex(s1, set);
	if (li == 0)
		return ((char *) ft_calloc(1, 1));
	return (ft_substr(s1, fi, (size_t)(li - fi + 1)));
}

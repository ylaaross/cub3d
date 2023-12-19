/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_ft_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:55:36 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 19:46:10 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "P_CUBE3D.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	ls;

	p = 0;
	i = 0;
	if (!s)
		return (0);
	ls = ft_strlenp(s);
	if (start > ls)
		return ((char *)ft_calloc(1, 1));
	if (len > ls)
		len = ls - start;
	p = (char *)malloc(len + 1);
	if (!p)
		return (0);
	while (s[start + i] && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

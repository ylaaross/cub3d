/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:24:51 by ylaaross          #+#    #+#             */
/*   Updated: 2023/10/29 20:27:42 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "CUBE3D.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size_s1;
	char	*p;

	p = 0;
	i = 0;
	size_s1 = ft_strlen(s1);
	p = malloc((size_s1 * sizeof(char)) + 1);
	if (p == 0)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

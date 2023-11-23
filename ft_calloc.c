/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:46:06 by ylaaross          #+#    #+#             */
/*   Updated: 2022/10/04 18:43:02 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	if (size == SIZE_MAX)
		return (0);
	p = 0;
	p = (char *)malloc(count * size);
	if (p == 0)
		return (0);
	else
		ft_bzero(p, count * size);
	return (p);
}

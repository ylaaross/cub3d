/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:25:16 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/22 19:25:33 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	cmp_ne_hay(char needle, char haystack, size_t *cmp)
{
	if (needle == haystack)
		*cmp = *cmp + 1;
}

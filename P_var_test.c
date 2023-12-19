/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_var_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:19:38 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 19:42:06 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "P_CUBE3D.h"

int	duplicatedor_less_var(t_range *var, char ch)
{
	int	count;

	count = 0;
	while (var)
	{
		if (var->identifiant == ch)
			count++;
		var = var->next;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	duplicated_less_var(t_range	*map_struct)
{
	if (duplicatedor_less_var(map_struct, 'F') 
		|| duplicatedor_less_var(map_struct, 'C'))
		return (1);
	return (0);
}

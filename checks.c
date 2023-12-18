/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:51:46 by asaber            #+#    #+#             */
/*   Updated: 2023/12/06 19:41:54 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	_x_y_to_check(int y, int x, char **map)
{
	unsigned int tmpx;
	unsigned int	tmpy;

	if (x < 0 || y < 0 || x > g_info.WIGHT || y > g_info.HIGHT)
		return (0);
	tmpx = floor(x);
	tmpy = floor(y);
	if (map[tmpy][tmpx] != '1' && map[tmpy][tmpx] != 32 && map[tmpy][tmpx])
		return (1);
	return (0);
}
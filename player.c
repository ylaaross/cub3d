/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:32:38 by asaber            #+#    #+#             */
/*   Updated: 2023/12/13 10:40:38 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	give_rotation(char c)
{
	if (c == 'N')
		g_info.player.rotation_angle = 3 * M_PI / 2;
	else if (c == 'S')
		g_info.player.rotation_angle = M_PI / 2;
	else if (c == 'E')
		g_info.player.rotation_angle = 2 * M_PI;
	else if (c == 'W')
		g_info.player.rotation_angle = M_PI;
}

void	find_player(void)
{
	int	i;
	int	j;
	int	check;

	check = false;
	i = 0;
	while (g_info.map[i])
	{
		j = 0;
		while (g_info.map[i][j])
		{
			if (g_info.map[i][j] == 'N' || g_info.map[i][j] == 'S' || g_info.map[i][j] == 'W' || g_info.map[i][j] == 'E')
			{
				g_info.player.x = (squire_size * j) + (squire_size/2);
				g_info.player.y = (squire_size * i) + (squire_size/2);
				check = true;
				give_rotation(g_info.map[i][j]);
				break ;
			}
			j++;
			if (check)
				break;
		}
		i++;
	}
	
}
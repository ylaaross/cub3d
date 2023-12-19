/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:32:38 by asaber            #+#    #+#             */
/*   Updated: 2023/12/19 20:17:04 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_info *g_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_info->player.raduis)
	{
		j = 0;
		while (j < g_info->player.raduis)
		{
			mlx_put_pixel(g_info->image, g_info->minimap * 
				g_info->player.x + i, g_info->minimap * g_info->player.y + j, 
				ft_pixel(123, 102, 255, 255));
			j++;
		}
		i++;
	}
	cast_all_ray(g_info);
}

void	draw_ray_angel(t_info *g_info)
{
	unsigned int	i;
	double			ray_angle;

	ray_angle = g_info->player.rotation_angle - (g_info->fov_angle / 2);
	i = 0;
	while (i < g_info->wight)
	{
		draw_line_dda(g_info->minimap * (g_info->player.x + 
				cos(ray_angle) * SQUIR_SIZE), g_info->minimap * 
			(g_info->player.y + sin(ray_angle) * SQUIR_SIZE), g_info);
		ray_angle += g_info->fov_angle / g_info->wight;
		i++;
	}
}

void	give_rotation(char c, t_info *g_info)
{
	if (c == 'N')
		g_info->player.rotation_angle = 3 * M_PI / 2;
	else if (c == 'S')
		g_info->player.rotation_angle = M_PI / 2;
	else if (c == 'E')
		g_info->player.rotation_angle = 2 * M_PI;
	else if (c == 'W')
		g_info->player.rotation_angle = M_PI;
}

void	find_player(t_info *g_info)
{
	int	i;
	int	j;
	int	check;

	check = false;
	i = 0;
	while (g_info->map[i] && !check)
	{
		j = 0;
		while (g_info->map[i][j])
		{
			if (g_info->map[i][j] == 'N' || g_info->map[i][j] == 'S' || 
				g_info->map[i][j] == 'W' || g_info->map[i][j] == 'E')
			{
				g_info->player.x = (SQUIR_SIZE * j) + (SQUIR_SIZE / 2);
				g_info->player.y = (SQUIR_SIZE * i) + (SQUIR_SIZE / 2);
				check = true;
				give_rotation(g_info->map[i][j], g_info);
				break ;
			}
			j++;
		}
		i++;
	}
}

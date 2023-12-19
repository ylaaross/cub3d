/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:38:26 by asaber            #+#    #+#             */
/*   Updated: 2023/12/19 20:48:25 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_wall_at(double player_x, double player_y, t_info *g_info)
{
	double	x;
	double	y;

	x = player_x / SQUIR_SIZE; 
	y = player_y / SQUIR_SIZE;
	if (y < 0 || y >= g_info->map_num_rows)
		return (1);
	if (x < 0 || x > g_info->map_num_colom)
		return (1);
	if (g_info->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

int	checkadd_vertical(t_info *g_info, t_raycasting *raycast)
{
	if (check_wall(g_info->map, raycast->nextv_x, raycast->nextv_y, g_info))
	{
		g_info->vray_x = raycast->nextv_x;
		g_info->vray_y = raycast->nextv_y;
		g_info->vfoundwall = true;
		return (1);
	}
	else
	{
		raycast->nextv_x += g_info->xstep;
		raycast->nextv_y += g_info->ystep;
	}
	return (0);
}

int	checkadd_horisontal(t_info *g_info, t_raycasting *raycast)
{
	if (check_wall(g_info->map, raycast->nexth_x, raycast->nexth_y, g_info))
	{
		g_info->hray_x = raycast->nexth_x;
		g_info->hray_y = raycast->nexth_y;
		g_info->hfoundwall = true;
		return (1);
	}
	else
	{
		raycast->nexth_x += g_info->xstep;
		raycast->nexth_y += g_info->ystep;
	}
	return (0);
}

void	check_distence(t_raycasting *raycast, t_info *g_info)
{
	if (g_info->hfoundwall)
		g_info->hdist = sqrt((raycast->nexth_x - g_info->player.x) * 
				(raycast->nexth_x - g_info->player.x) + (raycast->nexth_y - 
					g_info->player.y) * (raycast->nexth_y - g_info->player.y));
	else
		g_info->hdist = MAXFLOAT;
	if (g_info->vfoundwall)
		g_info->vdist = sqrt((raycast->nextv_x - g_info->player.x) * 
				(raycast->nextv_x - g_info->player.x) + (raycast->nextv_y - 
					g_info->player.y) * (raycast->nextv_y - g_info->player.y));
	else
		g_info->vdist = MAXFLOAT;
	if (g_info->vdist < g_info->hdist)
	{
		g_info->f_dist = g_info->vdist;
		g_info->ray_x = g_info->vray_x;
		g_info->ray_y = g_info->vray_y;
	}
	else
	{
		g_info->f_dist = g_info->hdist;
		g_info->ray_x = g_info->hray_x;
		g_info->ray_y = g_info->hray_y;
	}
}

void	updateraydirection(t_info *g_info)
{
	if (g_info->ray_angle > 0 && g_info->ray_angle < M_PI)
		g_info->israyfacingdown = 1;
	else
		g_info->israyfacingdown = 0;
	g_info->israyfacingup = !g_info->israyfacingdown;
	if (g_info->ray_angle < 0.5 * M_PI || g_info->ray_angle > 1.5 * M_PI)
		g_info->israyfacingright = 1;
	else
		g_info->israyfacingright = 0;
	g_info->israyfacingleft = !g_info->israyfacingright;
}

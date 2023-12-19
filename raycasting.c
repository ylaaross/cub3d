/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:05:51 by asaber            #+#    #+#             */
/*   Updated: 2023/12/19 20:46:49 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_horizontal(t_raycasting *raycast, t_info *g_info)
{
	g_info->hfoundwall = false;
	raycast->yinterseption = floor(g_info->player.y / SQUIR_SIZE) * SQUIR_SIZE;
	if (g_info->israyfacingdown)
		raycast->yinterseption += SQUIR_SIZE;
	raycast->xinterseption = g_info->player.x + (raycast->yinterseption - 
			g_info->player.y) / tan(g_info->ray_angle);
	g_info->ystep = SQUIR_SIZE;
	if (g_info->israyfacingup)
		g_info->ystep *= -1;
	g_info->xstep = SQUIR_SIZE / tan(g_info->ray_angle);
	if (g_info->israyfacingleft && g_info->xstep > 0)
		g_info->xstep *= -1;
	if (g_info->israyfacingright && g_info->xstep < 0)
		g_info->xstep *= -1;
	raycast->nexth_x = raycast->xinterseption;
	raycast->nexth_y = raycast->yinterseption;
	if (g_info->israyfacingup)
		raycast->nexth_y--;
	while (raycast->nexth_x >= 0 && raycast->nexth_x <= g_info->wight && 
		raycast->nexth_y >= 0 && raycast->nexth_y <= g_info->hight)
	{
		if (checkadd_horisontal(g_info, raycast))
			break ;
	}
}

void	cast_vertical(t_raycasting *raycast, t_info *g_info)
{
	g_info->vfoundwall = false;
	raycast->xinterseption_v = floor(g_info->player.x / SQUIR_SIZE)
		* SQUIR_SIZE;
	if (g_info->israyfacingright)
		raycast->xinterseption_v += SQUIR_SIZE;
	raycast->yinterseption_v = g_info->player.y + 
		(raycast->xinterseption_v - g_info->player.x) * tan(g_info->ray_angle);
	g_info->xstep = SQUIR_SIZE;
	if (g_info->israyfacingleft)
		g_info->xstep *= -1;
	g_info->ystep = SQUIR_SIZE * tan(g_info->ray_angle);
	if (g_info->israyfacingup && g_info->ystep > 0)
		g_info->ystep *= -1;
	if (g_info->israyfacingdown && g_info->ystep < 0)
		g_info->ystep *= -1;
	raycast->nextv_y = raycast->yinterseption_v;
	raycast->nextv_x = raycast->xinterseption_v;
	if (g_info->israyfacingleft)
		raycast->nextv_x--;
	while (raycast->nextv_x >= 0 && raycast->nextv_x <= g_info->wight && 
		raycast->nextv_y >= 0 && raycast->nextv_y <= g_info->hight)
	{
		if (checkadd_vertical(g_info, raycast))
			break ;
	}
}

void	main_cast(t_info *g_info)
{
	t_raycasting	*raycast;

	raycast = malloc(sizeof(t_raycasting));
	updateraydirection(g_info);
	cast_horizontal(raycast, g_info);
	cast_vertical(raycast, g_info);
	check_distence(raycast, g_info);
}

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	return (fmod(angle, 2 * M_PI));
}

void	cast_all_ray(t_info *g_info)
{
	unsigned int	i;

	g_info->ray_angle = g_info->player.rotation_angle - (g_info->fov_angle / 2);
	i = 0;
	while (i < g_info->wight)
	{
		main_cast(g_info);
		g_info->ray_angle += g_info->fov_angle / g_info->wight;
		g_info->player.rotation_angle = 
			normalize_angle(g_info->player.rotation_angle);
		g_info->ray_angle = normalize_angle(g_info->ray_angle);
		ray_view(g_info->ray_angle, g_info);
		draw_walls(i++, g_info);
	}
}

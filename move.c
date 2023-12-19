/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:53:32 by asaber            #+#    #+#             */
/*   Updated: 2023/12/19 19:42:24 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move(float x, float y, t_info *g_info)
{
	mlx_put_pixel(g_info->image, g_info->minimap * g_info->player.x, 
		g_info->minimap * g_info->player.y, ft_pixel(255, 0, 40, 255));
	mlx_put_pixel(g_info->image, g_info->minimap * x, 
		g_info->minimap * y, ft_pixel(255, 0, 40, 255));
	if (_x_y_to_check(y / SQUIR_SIZE, g_info->player.x / 
			SQUIR_SIZE, g_info->map, g_info))
		g_info->player.y = y;
	if (_x_y_to_check(g_info->player.y / SQUIR_SIZE, x / 
			SQUIR_SIZE, g_info->map, g_info))
		g_info->player.x = x;
}

void	w_a_s_d(t_info *g_info)
{
	if (mlx_is_key_down(*g_info->mlx, MLX_KEY_A))
		player_move(g_info->player.x + cos(g_info->player.rotation_angle 
				- M_PI / 2) * g_info->player.move_speed, g_info->player.y + 
			sin(g_info->player.rotation_angle - M_PI / 2) * 
			g_info->player.move_speed, g_info);
	if (mlx_is_key_down(*g_info->mlx, MLX_KEY_S))
		player_move(g_info->player.x - cos(g_info->player.rotation_angle) * 
			g_info->player.move_speed, g_info->player.y - 
			sin(g_info->player.rotation_angle) * 
			g_info->player.move_speed, g_info);
	if (mlx_is_key_down(*g_info->mlx, MLX_KEY_D))
		player_move(g_info->player.x - cos(g_info->player.rotation_angle 
				- M_PI / 2) * g_info->player.move_speed, g_info->player.y - 
			sin(g_info->player.rotation_angle - M_PI / 2) * 
			g_info->player.move_speed, g_info);
	if (mlx_is_key_down(*g_info->mlx, MLX_KEY_W))
		player_move(g_info->player.x + cos(g_info->player.rotation_angle) * 
			g_info->player.move_speed, g_info->player.y + 
			sin(g_info->player.rotation_angle) * 
			g_info->player.move_speed, g_info);
}

void	mlx_moves(void *param)
{
	t_info	*g_info;

	g_info = (t_info *)param;
	if (mlx_is_key_down(*g_info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(*g_info->mlx);
	w_a_s_d(g_info);
	if (mlx_is_key_down(*g_info->mlx, MLX_KEY_LEFT))
		g_info->player.rotation_angle -= 0.034;
	if (mlx_is_key_down(*g_info->mlx, MLX_KEY_RIGHT))
		g_info->player.rotation_angle += 0.034;
}

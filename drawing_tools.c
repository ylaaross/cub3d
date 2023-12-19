/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:44:50 by asaber            #+#    #+#             */
/*   Updated: 2023/12/19 20:47:38 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line_dda(int x2, int y2, t_info *g_info)
{
	int		i;
	int		steps;
	double	x;
	double	y;

	x = g_info->player.x * g_info->minimap;
	y = g_info->player.y * g_info->minimap;
	if (fabs(x2 - (g_info->player.x * g_info->minimap)) 
		> fabs(y2 - (g_info->player.y * g_info->minimap)))
		steps = fabs(x2 - g_info->player.x * g_info->minimap);
	else
		steps = fabs(y2 - g_info->player.y * g_info->minimap);
	i = 0;
	while (i < steps)
	{
		mlx_put_pixel(g_info->image, round(x), round(y), 0xFFFFFF);
		x += (double)(x2 - (g_info->player.x * g_info->minimap))
			/ (double)steps;
		y += (double)(y2 - (g_info->player.y * g_info->minimap)) 
			/ (double)steps;
		i++;
	}
}

void	draw_by_diriction(t_info *g_info, double id, double s_p, double e_p)
{
	int	offsetx;
	int	offsety;
	int	distancefromtop;

	if (g_info->hdist < g_info->vdist)
		offsetx = (int)g_info->ray_x % SQUIR_SIZE;
	else
		offsetx = (int)g_info->ray_y % SQUIR_SIZE;
	while (s_p < e_p)
	{
		distancefromtop = s_p + (g_info->wallstriphight / 2) - 
			(g_info->hight / 2);
		offsety = distancefromtop * ((float)SQUIR_SIZE / 
				g_info->wallstriphight);
		mlx_put_pixel(g_info->image, id, s_p, 
			get_color(g_info->texture, ((g_info->texture->width * offsety) + 
					offsetx) * 4));
		s_p++;
	}
}

int	check_wall(char **map, double x, double y, t_info *g_info)
{
	int	x_map;
	int	y_map;

	if (x < 0 || y < 0 || x / SQUIR_SIZE > ft_strlen(map[(int)y / 
				SQUIR_SIZE]) || y / SQUIR_SIZE > g_info->map_num_rows)
		return (1);
	x_map = floor(x / SQUIR_SIZE);
	y_map = floor(y / SQUIR_SIZE);
	if (map[y_map][x_map] == '1' || map[y_map][x_map] == 32)
		return (1);
	return (0);
}

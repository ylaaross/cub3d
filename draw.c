/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:34:46 by asaber            #+#    #+#             */
/*   Updated: 2023/12/20 00:10:38 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	squar_draw(float x, float y, int color, t_info *g_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < SQUIR_SIZE * g_info->minimap)
	{
		j = 0;
		while (j < SQUIR_SIZE * g_info->minimap)
		{
			mlx_put_pixel(g_info->image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
	// t_map_struct		*map_struct;
	// t_range				*range;
	
t_range * find_s_rgb(t_range	*range, char c)
{
	

	if (range->identifiant == c)
		return (range);
	else
		return (range->next);
}
void	draw_floor_and_ceiling(t_info *g_info, double s_p, 
double e_p, double id)
{
	t_range *c;
	t_range *f;
	
	c = NULL;
	f = NULL;
	c = find_s_rgb(g_info->rgb, 'C');
	f = find_s_rgb(g_info->rgb, 'F');
	while (s_p >= 0)
	{
		mlx_put_pixel(g_info->image, id, s_p, ft_pixel(c->r, c->g, c->b, 255));
		s_p--;
	}
	while (e_p <= g_info->hight)
	{
		mlx_put_pixel(g_info->image, id, e_p, ft_pixel(f->r, f->g, f->b, 255));
		e_p++;
	}
}

void	draw_walls(double stripId, t_info *g_info)
{
	double	start_point;
	double	end_point;

	g_info->distprojectplane = (g_info->wight / 2) / tan(g_info->fov_angle / 2);
	g_info->f_dist = g_info->f_dist * 
		cos(g_info->ray_angle - g_info->player.rotation_angle);
	g_info->wallstriphight = 
		SQUIR_SIZE / g_info->f_dist * g_info->distprojectplane;
	start_point = (g_info->hight / 2) - (g_info->wallstriphight / 2);
	end_point = (g_info->hight / 2) + (g_info->wallstriphight / 2);
	g_info->start_point = (int)start_point;
	draw_floor_and_ceiling(g_info, start_point, end_point, stripId);
	if (start_point < 0)
		start_point = 0;
	if (end_point > g_info->hight)
		end_point = g_info->hight;
	draw_by_diriction(g_info, stripId, start_point, end_point);
}

void	draw_map(void *param)
{
	int		i;
	int		j;
	t_info	*g_info;

	g_info = (t_info *)param;
	i = 0;
	draw_player(g_info);
	while (g_info->map[i])
	{
		j = 0;
		while (g_info->map[i][j])
		{
			if (g_info->map[i][j] == '1')
				squar_draw(g_info->minimap * (j * SQUIR_SIZE), g_info->minimap 
					* (i * SQUIR_SIZE), ft_pixel(255, 255, 255, 255), g_info);
			else if (g_info->map[i][j] == '0' || g_info->map[i][j] == 'N' 
				|| g_info->map[i][j] == 'S' || g_info->map[i][j] == 'W' 
				|| g_info->map[i][j] == 'E')
				squar_draw(g_info->minimap * (j * SQUIR_SIZE), g_info->minimap
					* (i * SQUIR_SIZE), ft_pixel(0, 0, 0, 255), g_info);
			j++;
		}
		i++;
	}
	draw_ray_angel(g_info);
}

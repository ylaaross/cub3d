/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:34:46 by asaber            #+#    #+#             */
/*   Updated: 2023/12/17 13:54:16 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


uint32_t	get_ocolor()
{
	uint32_t color;
	
	color = ft_pixel(100, 100, 100, 100);
	return (color);
}
uint32_t	get_color(mlx_texture_t	*texture, int pix)
{
	uint32_t	color;
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint8_t		alpha;

	red = texture->pixels[pix++];
	green = texture->pixels[pix++];
	blue = texture->pixels[pix++];
	alpha = texture->pixels[pix];
	color = ft_pixel(red, green, blue, alpha);
	return (color);
}

void	squar_draw(float x, float y, float size_square, int color, mlx_image_t *image)
{
	int i;
	int j;

	i = 0;
	while (i < size_square)
	{
		j = 0;
		while (j < size_square)
		{
			mlx_put_pixel(image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// drawing player

void	draw_player(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_info.player.raduis)
	{
		j = 0;
		while (j < g_info.player.raduis)
		{
			mlx_put_pixel(g_info.image, g_info.minimap * g_info.player.x + i, g_info.minimap *  g_info.player.y + j, ft_pixel(123, 102, 255, 255));
			j++;
		}
		i++;
	}
}

//drwaing floor and ceiling

void	draw_floor_and_ceiling(double start_point, double end_point, double stripId)
{
	while (start_point >= 0)
	{
		mlx_put_pixel(g_info.image, stripId, start_point, ft_pixel(197, 255, 248, 255));
		start_point--;
	}
	while (end_point <= g_info.HIGHT)
	{
		mlx_put_pixel(g_info.image, stripId, end_point, ft_pixel(245, 232, 199, 255));
		end_point++;
	}
}

void	draw_by_diriction(double stripId, double start_point, double end_point)
{
	int offsetx;
	int offsety;
	int static i=0;

	// if (!i)
	// 	g_info.texture = mlx_load_png("desert.png");
	if (g_info.hdist < g_info.vdist)
		offsetx = (int)g_info.ray_x % squire_size;
	else
		offsetx = (int)g_info.ray_y % squire_size;
	while (start_point < end_point)
	{
		offsety = (start_point - g_info.start_point) * ((float)squire_size / g_info.wallStripHight);
		mlx_put_pixel(g_info.image, stripId, start_point, get_ocolor());
		mlx_put_pixel(g_info.image, stripId, start_point, get_color(g_info.texture, ((g_info.texture->width * offsety) + offsetx) * 4));
		start_point++;
	}
	i++;
}

void	draw_walls(double stripId)
{
	double wallStripHight;
	double start_point;
	double end_point;
	
	g_info.distProjectPlane = (g_info.WIGHT / 2) / tan(g_info.fov_angle / 2);
	g_info.f_dist = g_info.f_dist * cos(g_info.ray_angle - g_info.player.rotation_angle);
	g_info.wallStripHight = squire_size / g_info.f_dist * g_info.distProjectPlane;
	
	start_point = (g_info.HIGHT / 2) - (g_info.wallStripHight / 2);
	end_point = (g_info.HIGHT / 2) + (g_info.wallStripHight / 2);
	g_info.start_point = (int)start_point;
	draw_floor_and_ceiling(start_point, end_point, stripId);
	if (start_point < 0)
		start_point = 0;
	if (end_point > g_info.HIGHT)
		end_point = g_info.HIGHT;
	draw_by_diriction(stripId, start_point, end_point);
}


void	draw_ray_angel(void)
{
	int	i;
	double	ray_angle;

	ray_angle = g_info.player.rotation_angle - (g_info.fov_angle / 2);
	i = 0;
	while (i < g_info.WIGHT)
	{
		draw_line_dda(g_info.minimap *  g_info.player.x, g_info.minimap * g_info.player.y, g_info.minimap * (g_info.player.x + cos(ray_angle) * 32), g_info.minimap * (g_info.player.y + sin(ray_angle) * 32));
		ray_angle += g_info.fov_angle / g_info.WIGHT;
		i++;
	}
}

void	draw_map(void* param)
{
	int		i;
	int 	j;

	i = 0;
	(void)param;
	draw_player();
	cast_all_ray();
	while (i < g_info.map_num_rows)
	{
		j = 0;
		while (j < g_info.map_num_colom)
		{
			if (g_info.map[i][j] == '1')
				squar_draw(g_info.minimap * (j * squire_size), g_info.minimap * (i * squire_size), g_info.minimap * squire_size,
					ft_pixel(255, 255, 255, 255), g_info.image);
			else if (g_info.map[i][j] == '0' || g_info.map[i][j] == 'N' || g_info.map[i][j] == 'S' || g_info.map[i][j] == 'W' || g_info.map[i][j] == 'E')
				squar_draw(g_info.minimap * (j * squire_size), g_info.minimap * (i * squire_size), g_info.minimap * squire_size,
					ft_pixel(0, 0, 0, 255), g_info.image);
			j++;
		}
		i++;
	}
	draw_ray_angel();	
}

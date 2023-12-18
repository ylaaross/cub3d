/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:05:51 by asaber            #+#    #+#             */
/*   Updated: 2023/12/17 15:49:58 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// dda algo
void	get_texture()
{
	if (g_info.vdist == g_info.f_dist)
	{
		if (g_info.left == 1)
			g_info.texture = g_info.W;
		else if (g_info.right == 1)
			g_info.texture = g_info.E;
	}
	else
	{
		if (g_info.up == 1)
			g_info.texture = g_info.N;
		else if (g_info.down == 1)
			g_info.texture = g_info.S;
	}
}

void updateRayDirection(void)
{
	// Define PI value
    g_info.isRayFacingDown = g_info.ray_angle > 0 && g_info.ray_angle < M_PI;
    g_info.isRayFacingUp = !g_info.isRayFacingDown;

    g_info.isRayFacingRight = g_info.ray_angle < 0.5 * M_PI || g_info.ray_angle > 1.5 * M_PI;
    g_info.isRayFacingLeft = !g_info.isRayFacingRight;
}

int	check_wall(char **map, int square_size, double x, double y)
{
	if (x < 0 || y < 0 || x > (square_size * ft_strlen(map[0])) || y > (square_size * ft_strlen(map[0])))
		return 1;
	int x_map = floor(x / square_size);
	int y_map = floor(y / square_size);
	if (map[y_map][x_map] == '1')
		return 1;
	return 0;
}

int	has_wall_at(double player_x, double player_y)
{
	double x;
	double y;
	
    x = player_x / squire_size; 
    y = player_y / squire_size;
    if (y < 0 || y >= g_info.map_num_rows)
        return (1);
    if (x < 0 || x > g_info.map_num_colom)
        return (1);
    if (g_info.map[(int)y][(int)x] == '1')
        return (1);
    return (0);
}

void	cast()
{
	double	yinterseption;
	double	xinterseption;

	updateRayDirection();
	g_info.hfoundWall = false;
	yinterseption = floor(g_info.player.y / squire_size) * squire_size;
	yinterseption += g_info.isRayFacingDown ? squire_size : 0;
	xinterseption = g_info.player.x + (yinterseption - g_info.player.y) / tan(g_info.ray_angle);
	g_info.ystep = squire_size;
	g_info.ystep *= g_info.isRayFacingUp ? -1 : 1;
	g_info.xstep = squire_size / tan(g_info.ray_angle);
	g_info.xstep *= (g_info.isRayFacingLeft && g_info.xstep > 0) ? -1 : 1;
	g_info.xstep *= (g_info.isRayFacingRight && g_info.xstep < 0) ? -1 : 1;
	double nexth_x = xinterseption;
	double nexth_y = yinterseption;

	if (g_info.isRayFacingUp)
		nexth_y--;
	while (nexth_x >= 0 && nexth_x <= g_info.WIGHT && nexth_y >= 0 && nexth_y <= g_info.HIGHT)
	{
		if (check_wall(g_info.map, squire_size, nexth_x, nexth_y))
		{
			g_info.hray_x = nexth_x;
			g_info.hray_y = nexth_y;
			g_info.hfoundWall = true;
			break;
		}
		else
		{
			nexth_x += g_info.xstep;
			nexth_y += g_info.ystep;
		}
	}
	// for verstical do it 

	double	xinterseption_v;
	double	yinterseption_v;
	g_info.vfoundWall = false;
	
	xinterseption_v = floor(g_info.player.x / squire_size) * squire_size;
	xinterseption_v += g_info.isRayFacingRight ? + squire_size : 0;
	
	yinterseption_v = g_info.player.y + (xinterseption_v - g_info.player.x) * tan(g_info.ray_angle);
	
	g_info.xstep = squire_size;
	g_info.xstep *= g_info.isRayFacingLeft ? -1 : 1;
	g_info.ystep = squire_size * tan(g_info.ray_angle);
	g_info.ystep *= (g_info.isRayFacingUp && g_info.ystep > 0) ? -1 : 1;
	g_info.ystep *= (g_info.isRayFacingDown && g_info.ystep < 0) ? -1 : 1;
	
	double nextv_x = xinterseption_v;
	double nextv_y = yinterseption_v;
	
	if (g_info.isRayFacingLeft)
		nextv_x--;
		
	while (nextv_x >= 0 && nextv_x <= g_info.WIGHT && nextv_y >= 0 && nextv_y <= g_info.HIGHT)
	{
		if (check_wall(g_info.map, squire_size, nextv_x, nextv_y))
		{
			g_info.vray_x = nextv_x;
			g_info.vray_y = nextv_y;
			g_info.vfoundWall = true;
			break;
		}
		else
		{
			nextv_x += g_info.xstep;
			nextv_y += g_info.ystep;
		}
	}

	
	if (g_info.hfoundWall)
		g_info.hdist = sqrt((nexth_x - g_info.player.x) * (nexth_x - g_info.player.x) + (nexth_y - g_info.player.y) * (nexth_y - g_info.player.y));
	else
		g_info.hdist = MAXFLOAT;
	if (g_info.vfoundWall)
		g_info.vdist = sqrt((nextv_x - g_info.player.x) * (nextv_x - g_info.player.x) + (nextv_y - g_info.player.y) * (nextv_y - g_info.player.y));
	else
		g_info.vdist = MAXFLOAT;
	if (g_info.vdist < g_info.hdist)
	{
		g_info.f_dist = g_info.vdist;
		g_info.ray_x = g_info.vray_x;
		g_info.ray_y = g_info.vray_y;
		g_info.vertical = 1; 
	}
	else
	{
		g_info.f_dist = g_info.hdist;
		g_info.ray_x = g_info.hray_x;
		g_info.ray_y = g_info.hray_y;
		g_info.horizantal = 1; 
	}
}

void draw_line_dda(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    double xIncrement, yIncrement, x = x1, y = y1;
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }
    xIncrement = (double)dx / (double)steps;
    yIncrement = (double)dy / (double)steps;
    for (int i = 0; i < steps; i++) {
		mlx_put_pixel(g_info.image, round(x), round(y), 0xFFFFFF);
        x += xIncrement;
        y += yIncrement;
    }
}

double normalize_angle(double angle) 
{
    if (angle < 0)
    	angle += 2 * M_PI;
    return fmod(angle, 2 * M_PI);
}


void	ray_view( double angle)
{
	g_info.up = 0;
	g_info.down = 0;
	g_info.left = 0;
	g_info.right = 0;
	if (angle > 0 && angle < M_PI)
		g_info.down = 1;
	else
		g_info.up = 1;
	if (angle < M_PI * 0.5 || angle > 1.5 * M_PI)
		g_info.right = 1;
	else
		g_info.left = 1;
	get_texture();
}



void	cast_all_ray(void)
{
	int		i;
	int static s = 0;

	g_info.ray_angle = g_info.player.rotation_angle - (g_info.fov_angle / 2);
	i = 0;
	while (i < g_info.WIGHT)
	{
		cast();
		g_info.ray_angle += g_info.fov_angle / g_info.WIGHT;
		g_info.player.rotation_angle = normalize_angle(g_info.player.rotation_angle);
		g_info.ray_angle = normalize_angle(g_info.ray_angle);
		ray_view(g_info.ray_angle);
		draw_walls(i);
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:20:02 by asaber            #+#    #+#             */
/*   Updated: 2023/12/19 23:37:00 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "/Users/ylaaross/MLX42/include/MLX42/MLX42.h"

# define SQUIR_SIZE 64
# define BUFFER_SIZE 500000
#include "P_CUBE3D.h"

typedef struct playerinfo
{
	double	x;
	double	y;
	double	raduis;
	int		turndir;
	int		walkdir;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
}	t_player;

typedef struct raycasting
{
	double	yinterseption;
	double	xinterseption;
	double	xinterseption_v;
	double	yinterseption_v;
	double	nexth_x;
	double	nexth_y;
	double	nextv_x;
	double	nextv_y;
}	t_raycasting;

typedef struct gameinfo
{
	t_map_struct	*paths;
	t_range			*rgb;
	mlx_t			**mlx;
	mlx_texture_t	*n;
	mlx_texture_t	*w;
	mlx_texture_t	*e;
	mlx_texture_t	*s;
	mlx_texture_t	*texture;
	int				up;
	int				down;
	int				left;
	int				right;
	int				start_point;
	int				horizantal;
	int				vertical;
	mlx_image_t		*image;
	char			*buffer;
	char			**map;
	int				map_num_rows;
	int				map_num_colom;
	unsigned int	hight;
	unsigned int	wight;
	double			fov_angle;
	double			ray_angle;
	bool			israyfacingdown;
	bool			israyfacingup;
	bool			israyfacingright;
	bool			israyfacingleft;
	double			xintercept;
	double			yintercept;
	double			hdist;
	double			vdist;
	double			f_dist;
	double			xstep;
	double			ystep;
	double			ray_x;
	double			ray_y;
	double			hray_x;
	double			hray_y;
	double			vray_x;
	double			vray_y;
	double			distprojectplane;
	double			wallstriphight;
	double			minimap;
	bool			hfoundwall;
	bool			vfoundwall;
	t_player		player;

}	t_info;

char		**ft_split(char const *s, char c);
int			ft_strlen(char *str);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		draw_map(void *param);
void		mlx_moves(void *param);
void		move_player(void);
void		find_player(t_info *g_info);
int			_x_y_to_check(int y, int x, char **map, t_info *g_info);
void		draw_line_dda(int x2, int y2, t_info *g_info);
void		cast_all_ray(t_info *g_info);
void		draw_walls(double stripId, t_info *g_info);
void		draw_player(t_info *g_info);
void		draw_ray_angel(t_info *g_info);
void		draw_by_diriction(t_info *g_info, double id, 
				double s_p, double e_p);
int			check_wall(char **map, double x, double y, t_info *g_info);
int			has_wall_at(double player_x, double player_y, t_info *g_info);
int			checkadd_horisontal(t_info *g_info, t_raycasting *raycast);
int			checkadd_vertical(t_info *g_info, t_raycasting *raycast);
void		updateraydirection(t_info *g_info);
uint32_t	get_color(mlx_texture_t	*texture, int pix);
void		get_texture(t_info *g_info);
void		ray_view(double angle, t_info *g_info);
void		check_distence(t_raycasting *raycast, t_info *g_info);
#endif
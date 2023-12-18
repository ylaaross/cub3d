/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:20:53 by asaber            #+#    #+#             */
/*   Updated: 2023/12/17 17:34:43 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_len_colom(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	pre_init(int fd)
{
	g_info.buffer = malloc(buffer_size);
	read(fd, g_info.buffer, buffer_size);
	g_info.map = ft_split(g_info.buffer, '\n');
	g_info.map_num_colom = ft_strlen(g_info.map[0]);
	g_info.map_num_rows = map_len_colom(g_info.map);
	g_info.HIGHT = g_info.map_num_rows * squire_size;
	g_info.WIGHT = g_info.map_num_colom * squire_size;
	g_info.player.raduis = 3.0;
	g_info.player.walkdir = 0;
	g_info.player.turndir = 0;
	g_info.player.move_speed = 3.0;
	g_info.fov_angle = 60.0 * (M_PI / 180);
	g_info.player.turndir = 0;
	g_info.player.walkdir = 0;
	g_info.ray_x = 0;
	g_info.ray_y = 0;
	g_info.minimap = 0.2;
	find_player();
}

int	mlx_checks(mlx_t **mlx)
{
	if (!(*mlx = mlx_init(g_info.WIGHT, g_info.HIGHT, "cub3d", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(g_info.image = mlx_new_image(*mlx, g_info.WIGHT, g_info.HIGHT)))
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(*mlx, g_info.image, 0, 0) == -1)
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int		fd;
	mlx_t	*mlx;

	if (ac == 2)
	{
		fd = open(av[1], O_RDWR);
		pre_init(fd);
		g_info.N = mlx_load_png("1.png");
		g_info.S = mlx_load_png("2.png");
		g_info.W = mlx_load_png("3.png");
		g_info.E = mlx_load_png("4.png");
		if (!g_info.N || !g_info.S || !g_info.W || !g_info.E)
			return (0);
		if (mlx_checks(&mlx) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		mlx_loop_hook(mlx, draw_map, mlx);
		mlx_loop_hook(mlx, mlx_moves, mlx);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
}

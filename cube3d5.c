/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:05:10 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/23 17:21:57 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUBE3D.h"

void	init_vars(t_file **f, mlx_t **mlx, mlx_image_t **img, t_all_infos *all)
{
	*f = 0;
	*mlx = 0;
	*img = 0;
	all->element_part = 0;
	all->map = 0;
	all->map_only = 0;
	all->map_struct = 0;
	all->range = 0;
}

void	mallocate_find(t_all_infos *all)
{
	mallocate_map(all);
	mallocate_element_var(all);
	find_split(all);
}

void	test_cases(t_all_infos *all)
{
	if (test_lines(all->element_part) == 6 && !test_if_vide(all->map_only)
		&& !detect_inprotected_space(all->map_only)
		&& !element_intru(all->map_only))
	{
		find_rgb(all);
		if (!duplicated_less_elements(all->map_struct)
			&& !duplicated_rgb(all->range) && find_player(all->map_only))
			printf("fuck yo");
		else
			print_err();
	}
	else
		print_err();
}

void	convert_check(t_file *f, t_all_infos *all)
{
	all->map = convertto_arr(f);
	mallocate_find(all);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_file		*f;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_all_infos	all;

	init_vars(&f, &mlx, &img, &all);
	if (argc == 2)
	{
		if (file_check(argv[1]))
		{
			fd = file_d(argv[1]);
			if (fd > 0)
			{
				file_read(&f, fd);
				t_tabcheck(f);
				convert_check(f, &all);
				test_cases(&all);
			}
			else
				print_err();
		}
		else
			print_err();
	}
}

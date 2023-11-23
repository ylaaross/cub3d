#include "/Users/ylaaross/MLX42/include/MLX42/MLX42.h"
#include "get_next_line.h"
#include "CUBE3D.h"
#include <stdlib.h>







uint32_t	ft_pixel(uint32_t red, uint32_t green, uint32_t blue, uint32_t alpha)
{
	return ((red << 24) | (green << 16) | (blue << 8) | alpha);
}


void init(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
}
// int count_line()
// {

// }


// void count_line()
// {
// 	int		fd;
// 	char	buffer[11];
// 	int		sread;

// 	sread = 1;
// 	while (sread > 0)
// 	{
// 		init(buffer);
// 		sread = read(fd, buffer, BUFFER_SIZE);
// 		if (sread == -1 || (sread == 0))
// 		{
// 			return (0);
// 		}
// 		buffer[sread] = 0;
// 		line = ft_strjoin(line, buffer);
// 	}
// }

int	file_d(char *path)
{
	int	fd;

	fd = open (path, O_RDONLY);
	if (fd < 0)
		return (0);
	else
		return (fd);
}

int height(char **o)
{
	int i;

	i = 0;
	while(o[i])
	{
		i++;
	}
	return(i);
}



void copy(char **o, char ***modified_map)
{
	int h;
	int w;
	int i;
	int j;

	j = 0;
	i = 0;
	
	h = height(o);
	w = width(o);
	*modified_map = (char**) malloc(sizeof(char**) * (h+1));
	while(i <  h)
	{
		(*modified_map)[i] = (char*)malloc(sizeof(char) * (w + 1));
		i++;
	}
	(*modified_map)[i] = 0;
	i = 0;
	while(i < h)
	{
		j = 0;
		while(j < w)
		{
			if((*modified_map)[i][j])
				(*modified_map)[i][j] = o[i][j];
			else
				(*modified_map)[i][j] = 'v';
			j++;
		}
			(*modified_map)[i][j] = 0;
		i++;
	}
}


int main(int argc, char **argv)
{
	char		**ch;
	int			fd;
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		**modified_map;
	
	int i = 0;
	int j = 0;

	fd = file_d(argv[1]);
	if (argc == 2)
	{
		if (file_check(argv[1]))
		{
			fd = file_d(argv[1]);
			if (fd > 0)
			{
				concat_and_store(&map, fd);
				// printf("%d",max_width(map));
			}
			else
				printf("///");
		}
		else
			printf("**");
	}
}


















// int main(int argc, char **argv)
// {
// 	char		**ch;
// 	int			fd;
// 	char		**map;
// 	mlx_t		*mlx;
// 	mlx_image_t	*img;
// 	char		**modified_map;
	
// 	int i = 0;
// 	int j = 0;


// 	// mlx = mlx_init(1000, 1500, "Cube3d", true);
//     // img = mlx_new_image(mlx, 1000, 1500);
//     // mlx_image_to_window(mlx, img, 0, 0);
// 	// printf("ssss");
// 	fd = file_d(argv[1]);
// 	if (argc == 2)
// 	{
// 		if (file_check(argv[1]))
// 		{
// 			fd = file_d(argv[1]);
// 			if (fd > 0)
// 			{
// 				concat_and_store(map, fd);

// 				if (wall_check(map) )
// 				{
// 				//	printf("--------------------");
// 					printf("sss");
// 					// copy(map, &modified_map);
// 					// while(modified_map[i])
// 					// {
// 					// 	j = 0;
// 					// 	while(modified_map[i][j])
// 					// 	{
// 					// 		printf("%c",modified_map[i][j]);
// 					// 		j++;
// 					// 	}
// 					// 	i++;
// 					// }
// 				}
// 				else
// 				{
// 					printf("NOOO");
// 				}
// 			}
// 			else
// 				printf("///");
// 		}
// 		else
// 			printf("**");
// 	}
//     // mlx_loop(mlx);
// 	// mlx_terminate(mlx);
// }
CC = cc

CFLAGS = -Wall -Wextra -Werror 

ARGS= -Iinclude -lglfw   -L"/Users/$(USER)/goinfre/homebrew/opt/glfw/lib"

MLX42 = /Users/ylaaross/MLX42/build/libmlx42.a 

NAME = cub3D

SRC =   P_Wall_check.c P_ft_split.c P_cube3d.c P_cube3d1.c P_cube3d2.c P_cube3d3.c P_cube3d4.c P_cube3d5.c P_get_next_line_utils.c P_get_next_line.c P_ft_substr.c P_file_store.c P_file_store1.c P_file_check.c P_ft_strdup.c P_ft_strstr.c P_ft_strstr1.c P_ft_strlen.c P_test_map.c P_test_map2.c P_var_check.c P_var_check1.c P_var_check2.c P_var_check3.c P_ft_strtrim.c P_ft_atoi.c P_size_calculate.c P_var_test.c P_map_create.c P_map_create1.c cub3d.c draw.c put_pixel.c move.c player.c checks.c raycasting.c drawing_tools.c raycasting_checks.c texters.c ft_split.c ft_strlen.c

OBJS =  $(SRC:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJS) 
		$(CC) $(CFLAGS)  $(ARGS) $(MLX42) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY = all clean fclean re
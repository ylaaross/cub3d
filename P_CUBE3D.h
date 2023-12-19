/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_CUBE3D.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:17:57 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 22:46:02 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_CUBE3D_H
# define P_CUBE3D_H

# include "/Users/ylaaross/MLX42/include/MLX42/MLX42.h"
# include "P_get_next_line.h"
# include <stdlib.h>

typedef struct image
{
	mlx_texture_t		*north;
	mlx_texture_t		*south;
	mlx_texture_t		*east;
	mlx_texture_t		*west;
}						t_image;

typedef struct map_struct
{
	char				*element_type;
	char				*path;
	struct map_struct	*next;
}						t_map_struct;

typedef struct file
{
	char				*line;
	struct file			*next;
}						t_file;

typedef struct range
{
	char				identifiant;
	int					r;
	int					g;
	int					b;
	struct range		*next;
}						t_range;

typedef struct rgb
{
	char				identifiant;
	char				*r;
	char				*g;
	char				*b;
}						t_rgb;

typedef struct all_infos
{
	t_map_struct		*map_struct;
	t_range				*range;
	char				**map;
	char				**map_only;
	char				**element_part;
}						t_all_infos;

void					convert_check(t_file *f, t_all_infos *all);
void					test_cases(t_all_infos *all);
void					mallocate_find(t_all_infos *all);
void					init_vars(t_file **f, mlx_t **mlx, mlx_image_t **img,
							t_all_infos *all);
void					print_err(void);
void					t_tabcheck(t_file *f);
int						find_playerp(char **map);
int						element_intru(char **map);
int						detect_inprotected_space(char **map);
int						compare_element(char **map, int i, int j);
int						map_element(char c);
void					last_line(char **map, int *m);
void					init_detect(int *i, int *j, int *m);
int						duplicated_rgb(t_range *r);
int						count_rgb(t_range *r, char c);
int						duplicated_less_elements(t_map_struct *map_struct);
int						duplicatedor_less_test(t_map_struct *map_struct,
							char *ch);
int						test_if_vide(char **map);
int						first_last_line_t(char *ch);
int						first_line(char **t);
int						find_map(char *f);
int						detect_line_element(char *ch);
char					**convertto_arr(t_file *o);
void					callocate(char ***d2, int size, int wid);
void					init_convert(int *size, t_file *o, int *i, int *j);
void					initi_rgb(int *i, t_rgb *v, char **trimed_char,
							char ***s);
void					free_rgb(char **s);
void					test(t_rgb r);
int						first_word_le(char *line);
char					*skip_identifiant2(char *line);
char					*skip_identifiant(char *line);
int						comma_count(char *line);
void					find_split(t_all_infos *o);
void					strlen_fifo(char ***s, t_all_infos *o);
void					init(int *i, int *j, char ***s, t_all_infos **head2);
int						count_words2(char *ch);
int						element_of_map(char *line);
int						empty_line(char *line);
int						free_t1(char *t1, char *trimmed_char, int return1);
int						find_map(char *f);
int						last_char(char *p);
int						test_if_vide(char **map);
int						empty_line(char *line);
int						detect_line_element(char *ch);
int						not_digit(char *s);
int						test_lines(char **p);
int						count_words2(char *ch);
t_map_struct			*fifo_2(t_map_struct *head, char *line, char *line2);
void					mallocate_element_var(t_all_infos *infos);
int						element_of_map(char *line);
void					mallocate_map(t_all_infos *infos);
int						search_eline(char **p);
int						duplicated_less_var(t_range *map_struct);
int						strlen_2d_st(t_file *o);
char					**convertto_arr(t_file *o);
int						width(t_file *o);
void					find_rgb(t_all_infos *o);
t_range					*fifo_3(t_range *head, t_rgb v);
int						ft_atoi(const char *str);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strtrim(char const *s1, char const *set);
void					find_split(t_all_infos *o);
int						strlen_2d(char **mline);
void					cmp_ne_hay(char needle, char haystack, size_t *cmp);
char					*ft_strstr_2(char *haystack, char *needle);
size_t					ft_strlenp(const char *s);
char					*ft_strdup(const char *s1);
int						file_check(char *path);
char					*ft_strchr(char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
void					file_read(t_file **f, int fd);
char					**ft_splitp(char const *s, char c);
int						wall_check(char **map);
int						test_void(char **map);
int						width_teol(char *line, int *i);
int						max_width(char *line);
char					**split_2(char *line);
int						number_line(char *line);
int						check_new_line(char **p, int s);
int						check_pline(char *p);
int						check_aline(char *p);
char					**ft_split(char const *s, char c);
int						file_d(char *path);
int						empty_line(char *line);
char					*ft_strstr(const char *haystack, const char *needle);
int						map_line(char *line);

#endif
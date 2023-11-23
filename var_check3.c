/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:11:39 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/23 16:21:17 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUBE3D.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	store_test(t_rgb *v, char **s)
{
	v->r = s[0];
	v->g = s[1];
	v->b = s[2];
	test(*v);
}

void	store_free(t_all_infos *o, char ***s, t_rgb *v, char *trimed_char)
{
	free(trimed_char);
	if (strlen_2d(*s) == 3)
	{
		store_test(v, *s);
		o->range = fifo_3(o->range, *v);
		free_rgb(*s);
	}
	else
		error();
}

int	test_condition(t_all_infos *o, int i)
{
	if (comma_count(o->element_part[i]) == 2
		&& count_words2(o->element_part[i]) == 4
		&& first_word_le(o->element_part[i]) == 1)
		return (1);
	return (0);
}

void	find_rgb(t_all_infos *o)
{
	char	*c;
	char	**s;
	char	*trimed_char;
	int		i;
	t_rgb	v;

	initi_rgb(&i, &v, &trimed_char, &s);
	while (o->element_part[i])
	{
		if (ft_strstr(o->element_part[i], "F") || ft_strstr(o->element_part[i],
				"C"))
		{
			c = skip_identifiant(o->element_part[i]);
			if (test_condition(o, i))
			{
				v.identifiant = skip_identifiant2(o->element_part[i])[0];
				trimed_char = ft_strtrim(c, "\n");
				s = ft_split(trimed_char, ',');
				store_free(o, &s, &v, trimed_char);
			}
			else
				error();
		}
		i++;
	}
}

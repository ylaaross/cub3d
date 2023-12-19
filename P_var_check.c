/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_var_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:02:24 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 19:50:33 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "P_CUBE3D.h"
#include <stdio.h>

int	count_words2(char *ch)
{
	int	boolean;
	int	count;
	int	i;

	count = 0;
	boolean = 1;
	i = 0;
	while (ch[i])
	{
		if (ch[i] != '\n' && ch[i] != ' ' && ch[i] != ',' && boolean == 1)
		{
			boolean = 0;
			count++;
		}
		else if (ch[i] == ' ' || ch[i] == ',')
			boolean = 1;
		i++;
	}
	return (count);
}

void	init(int *i, int *j, char ***s, t_all_infos **head2)
{
	*i = 0;
	*j = 0;
	*s = 0;
	*head2 = 0;
}

void	strlen_fifo(char ***s, t_all_infos *o)
{
	if (strlen_2d(*s) == 2)
	{
		o->map_struct = fifo_2(o->map_struct, (*s)[0], (*s)[1]);
		free(*s);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	find_split(t_all_infos *o)
{
	char		**s;
	int			i;
	int			j;
	char		*trimed_char;
	t_all_infos	*head2;

	init(&i, &j, &s, &head2);
	if (!o)
		return ;
	if (!o->element_part)
		exit(1);
	while (o->element_part[i])
	{
		if (ft_strstr(o->element_part[i], "NO") || ft_strstr(o->element_part[i],
				"SO") || ft_strstr(o->element_part[i], "WE")
			|| ft_strstr(o->element_part[i], "EA"))
		{
			trimed_char = ft_strtrim(o->element_part[i], "\n");
			s = ft_splitp(trimed_char, ' ');
			free(trimed_char);
			strlen_fifo(&s, o);
		}
		i++;
	}
}

int	comma_count(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:09:35 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/23 16:20:48 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUBE3D.h"

int	not_digit(char *s)
{
	int		i;
	int		f;
	char	*trimmed_char;

	i = 0;
	f = 1;
	trimmed_char = ft_strtrim(s, " ");
	while (trimmed_char[i] && trimmed_char[i] == ' ')
		i++;
	while (trimmed_char[i])
	{
		if (trimmed_char[i] == '+' && f == 1)
			f = 0;
		else if (!(trimmed_char[i] >= '0' && trimmed_char[i] <= '9'))
		{
			free(trimmed_char);
			return (1);
		}
		i++;
	}
	free(trimmed_char);
	return (0);
}

int	first_word_le(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ')
	{
		count++;
		i++;
	}
	return (count);
}

void	test(t_rgb r)
{
	if (not_digit(r.r) || not_digit(r.g) || not_digit(r.b) || ft_atoi(r.r) == -1
		|| ft_atoi(r.g) == -1 || ft_atoi(r.b) == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	free_rgb(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	initi_rgb(int *i, t_rgb *v, char **trimed_char, char ***s)
{
	*i = 0;
	v->identifiant = 0;
	v->r = 0;
	v->g = 0;
	v->b = 0;
	*trimed_char = 0;
	*s = 0;
}

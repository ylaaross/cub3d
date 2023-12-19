/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_file_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:20:01 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 19:38:34 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "P_CUBE3D.h"

int	sign_test(char *c)
{
	int	nbr;
	int	signe;
	int	i;

	signe = 0;
	nbr = 0;
	i = 0;
	while (c[i])
	{
		if (c[i] == '+')
		{
			if (!c[i + 1] || (c[i + 1] && !(c[i + 1] >= '0' && c[i + 1] <= '9'))
				|| (i > 0 && (c[i - 1] >= '0' && c[i - 1] <= '9')))
				return (0);
		}
		i++;
	}
	return (1);
}

void	test_digit(t_rgb v)
{
	if (not_digit(v.r) || not_digit(v.g) || not_digit(v.b) || !sign_test(v.r)
		|| !sign_test(v.g) || !sign_test(v.b))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	store(t_range *head, t_rgb v)
{
	test_digit(v);
	head->r = ft_atoi(v.r);
	head->g = ft_atoi(v.g);
	head->b = ft_atoi(v.b);
	head->identifiant = v.identifiant;
	head->next = 0;
}

t_range	*fifo_3(t_range *head, t_rgb v)
{
	t_range	*t;

	t = 0;
	if (head == 0)
	{
		head = malloc(sizeof(t_range));
		store(head, v);
	}
	else
	{
		test_digit(v);
		t = head;
		while (t->next)
			t = t->next;
		t->next = malloc(sizeof(t_range));
		t->next->r = ft_atoi(v.r);
		t->next->g = ft_atoi(v.g);
		t->next->b = ft_atoi(v.b);
		t->next->identifiant = v.identifiant;
		t->next->next = 0;
	}
	return (head);
}

t_map_struct	*fifo_2(t_map_struct *head, char *line, char *line2)
{
	t_map_struct	*t;

	t = 0;
	if (head == 0)
	{
		head = malloc(sizeof(t_map_struct));
		head->element_type = ft_strdup(line);
		head->path = ft_strdup(line2);
		free(line);
		free(line2);
		head->next = 0;
	}
	else
	{
		t = head;
		while (t->next)
			t = t->next;
		t->next = malloc(sizeof(t_map_struct));
		t->next->element_type = ft_strdup(line);
		t->next->path = ft_strdup(line2);
		free(line);
		free(line2);
		t->next->next = 0;
	}
	return (head);
}

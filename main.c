/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:41:55 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/22 18:43:06 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	count_words(char const *s, char c)
{
	int	boolean;
	int	i;
	int	cmp;

	boolean = 1;
	i = 0;
	cmp = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			boolean = 1;
		}
		else if (s[i] != c && boolean == 1)
		{
			boolean = 0;
			cmp++;
		}
		i++;
	}
	return (cmp);
}

int	ft_strlenm(char const *s, int index, char c)
{
	int	i;

	i = 0;
	while (s[index] != c && s[index])
	{
		i++;
		index++;
	}
	return (i);
}

char	*cp(char const *s, char c, int *index, int ft_strlenm)
{
	char	*p;
	int		i;

	p = 0;
	i = 0;
	p = (char *)malloc((size_t)ft_strlenm * sizeof(char) + 1);
	if (!p)
		return (0);
	else
	{
		while (s[*index] && s[*index] != c)
		{
			p[i] = s[*index];
			i++;
			*index = *index + 1;
		}
		p[i] = 0;
	}
	return (p);
}

void	findwords(char const *s, int *index, char c)
{
	while (s[*index] && s[*index] == c)
		*index = *index + 1;
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**p;
	int		i;
	int		wc;

	i = 0;
	index = 0;
	if (!s)
		return (0);
	wc = count_words(s, c);
	if (wc == 0)
		return (0);
	p = (char **)malloc((wc + 1) * sizeof(char *));
	if (!p)
		return (0);
	while (i < wc)
	{
		findwords(s, &index, c);
		p[i] = cp(s, c, &index, ft_strlenm(s, index, c));
		i++;
	}
	p[i] = 0;
	return (p);
}

int	main(void)
{
	char t[] = "           ";
	char **s = 0;

	s = ft_split(t, ' ');
	if (!s)
		printf("sssssssssssss");
}
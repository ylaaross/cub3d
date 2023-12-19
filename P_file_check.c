/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_file_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:00:45 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 19:46:28 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "P_CUBE3D.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				len;
	unsigned char	*cs1;
	unsigned char	*cs2;

	len = ft_strlenp((char *)s2);
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	while (cs1[i] || cs2[i])
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}

int	file_check(char *path)
{
	int		i;
	char	*s;

	s = 0;
	i = 0;
	s = ft_strchr(path, '.');
	if (!s)
		return (0);
	if (ft_strcmp(s, ".cub") == 0)
	{
		if (ft_strlenp(path) == 4)
			return (0);
		return (1);
	}
	return (0);
}

int	file_d(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	else
		return (fd);
}

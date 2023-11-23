/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:01:46 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/23 16:01:52 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*skip_identifiant(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != 'F' && line[i] != 'C')
		i++;
	if (line[i] && line[i + 1])
	{
		i++;
		return (line + i);
	}
	return (0);
}

char	*skip_identifiant2(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != 'F' && line[i] != 'C')
		i++;
	if (line[i])
	{
		return (line + i);
	}
	return (0);
}

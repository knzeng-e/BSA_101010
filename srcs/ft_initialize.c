/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:14:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/18 04:40:49 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_get_size(int nbr)
{
	if (nbr < 10)
		return (1);
	return (1 + ft_get_size(nbr / 10));
}

char	*ft_extract_size(char *fst_line)
{
	char	*size;
	int		i;
	int		j;

	i = 0;
	if (*fst_line == '\0')
		return ("0");
	while (fst_line[i] != '\n')
		i++;
	size = (char *)malloc(sizeof(char) * i - 3 + 1);
	j = 0;
	while (j < i - 3)
	{
		size[j] = fst_line[j];
		j++;
	}
	size[j] = '\0';
	return (size);
}

void	ft_initialize(char *file, t_map *map, char *buffer)
{
	int	size;

	map->nb_lines = ft_atoi(ft_extract_size(buffer));
	size = ft_get_size(map->nb_lines);
	map->vide = *(buffer + size);
	map->obstacle = *(buffer + size + 1);
	map->plein = *(buffer + size + 2);
	map->file_name = file;
}

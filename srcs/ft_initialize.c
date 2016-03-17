/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:14:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/17 19:20:12 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_get_size(int nbr)
{
	if (nbr < 10)
		return (1);
	return (1 + ft_get_size(nbr / 10));
}

void	ft_initialize(char *file, t_map *map, char *buffer)
{
	int	size;

	map->nb_lines = ft_atoi(buffer);
	size = ft_get_size(map->nb_lines);
	map->vide = *(buffer + size);
	map->obstacle = *(buffer + size + 1);
	map->plein = *(buffer + size + 2);
	map->file_name = file;
}

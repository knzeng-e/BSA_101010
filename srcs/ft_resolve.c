/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:16:31 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/22 19:42:43 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_resolve(t_map *map, char **tab, t_tab placing)
{
	int i;
	int j;

	i = map->nb_columns;
	if (ft_extract_map(map) < 0)
	{
		return (MAP_ERROR);
	}
	map->tempon = (int **)malloc(sizeof(int *) * map->nb_lines * map->nb_columns);
	i = 0;
	while (i < map->nb_lines)
	{
		j = 0;
		map->tempon[i] = (int *)malloc(sizeof(int) * map->nb_columns);
		while (j < map->nb_columns)
		{
			if (tab[i][j] == map->vide)
			{
				map->tempon[i][j] = 1;
				tab[i][j++] = '1';
			}
			else
			{
				map->tempon[i][j] = 0;
				tab[i][j++] = '0';
			}
		}
		i++;
	}
	ft_adding(tab, map);
	placing = check_tab(map, tab);
	exec(map, placing, tab);
	return (MAP_OK);
}

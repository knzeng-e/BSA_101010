/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:16:31 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/24 06:03:34 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_modify(t_map *map, int i, int j, char **tab)
{
	while (j < map->nb_columns)
	{
		if (tab[i][j] == map->vide)
		{
			map->tempon[i][j] = 1;
			j++;
		}
		else
		{
			map->tempon[i][j] = 0;
			j++;
		}
	}
}

int		ft_resolve(t_map *map, char **tab, t_tab placing)
{
	int i;
	int j;

	if (ft_extract_map(map) < 0)
		return (MAP_ERROR);
	if (!(map->tempon = (int **)malloc(sizeof(int *) * map->nb_lines)))
		return (IMPOSSIBLE_MALLOC);
	i = -1;
	while (++i < map->nb_lines)
	{
		j = 0;
		if (!(map->tempon[i] = (int *)malloc(sizeof(int) * map->nb_columns)))
			return (IMPOSSIBLE_MALLOC);
		ft_modify(map, i, j, tab);
	}
	ft_adding(map);
	placing = check_tab(map, tab);
	exec(map, placing, tab);
	free(map->tempon);
	return (MAP_OK);
}

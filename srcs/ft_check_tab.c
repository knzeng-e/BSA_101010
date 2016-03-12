/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:10:05 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/12 05:10:38 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_tab	check_tab(t_map *map, char **tab)
{
	t_tab	place;
	place.data = 0;
	int i = 0;
	int j;

	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			if (tab[i][j] > place.data)
			{
				place.line = i;
				place.column = j;
				place.data = tab[i][j];
			}
			j++;
		}
		i++;
	}
	return (place);
}

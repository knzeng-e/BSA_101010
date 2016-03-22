/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:10:05 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/22 19:43:48 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_tab	check_tab(t_map *map, char **tab)
{
	t_tab	place;
	int		i;
	int		j;

	place.data = 0;
	place.data_i = 0;
	i = 0;
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			if (tab[i][j] > place.data)
				;
			if (map->tempon[i][j] > place.data_i)
			{
				place.line = i;
				place.column = j;
				place.data_i = map->tempon[i][j];
			}
			j++;
		}
		i++;
	}
	return (place);
}

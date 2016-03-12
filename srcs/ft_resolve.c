/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:16:31 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/12 05:17:27 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_resolve(t_map *map, char **tab, t_tab placing)
{
	int i;
	int j;

	ft_extract_map(map, tab);
	i = 0;
	while(i < map->nb_lines)
	{
		j = 0;
		while(j < map->nb_columns)
		{
			if (tab[i][j] == '.')
				tab[i][j] = '1';
			else
				tab[i][j] = '0';
			j++;
		}
		i++;
	}
	ft_adding(tab, map);
	placing = check_tab(map, tab);

	exec(map, placing, tab);

}

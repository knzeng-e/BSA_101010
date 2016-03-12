/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:13:25 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/12 05:14:09 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	exec(t_map *map, t_tab pos, char **tab)
{
	int i = 0;
	int j = 0;

	int k = pos.line - (pos.data - '0') + 1;
	int l = pos.column - (pos.data - '0') + 1;
	i = 0;
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			if ((k <= i && i <= pos.line) && (l <= j && j <= pos.column))
				tab[i][j] = 'x';
			else
				if (tab[i][j] == '0')
					tab[i][j] = map->obstacle;
				else
					tab[i][j] = map->vide;
			j++;
		}
		i++;
	}
	ft_print_map(map, tab);
}

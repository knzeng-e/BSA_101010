/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:13:25 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/22 19:43:06 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_init(int *k, int *l, t_tab *pos)
{
	*k = pos->line - (pos->data_i) + 1;
	*l = pos->column - (pos->data_i) + 1;
}

void	exec(t_map *map, t_tab pos, char **tab)
{
	int i;
	int j;
	int k;
	int l;

	ft_init(&k, &l, &pos);
	i = 0;
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			if ((k <= i && i <= pos.line) && (l <= j && j <= pos.column))
				tab[i][j++] = map->plein;
			else
			{
				if (tab[i][j] == '0')
					tab[i][j++] = map->obstacle;
				else
					tab[i][j++] = map->vide;
			}
		}
		i++;
	}
	ft_print_map(map, tab);
}

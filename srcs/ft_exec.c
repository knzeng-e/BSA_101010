/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 22:49:26 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/28 02:41:02 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_init(int *k, int *l, t_tab *pos)
{
	*k = pos->line - (pos->data_i) + 1;
	*l = pos->column - (pos->data_i) + 1;
}

void	exec(int **tab, t_tab pos, t_map *map)
{
	int i;
	int j;
	int k;
	int l;

	ft_init(&k, &l, &pos);
	i = -1;
	while (++i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			if ((k <= i && i <= pos.line) && (l <= j && j <= pos.column))
				ft_putchar(map->plein);
			else
			{
				if (tab[i][j] == 0)
					ft_putchar(map->obstacle);
				else
					ft_putchar(map->vide);
			}
			j++;
		}
		ft_putstr("\n");
	}
}

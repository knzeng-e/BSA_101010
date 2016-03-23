/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:59:07 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/23 04:17:57 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_map2(t_map *map)
{
	int	k;
	int	j;

	k = 0;
	while (k < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			ft_putnbr(map->tempon[k][j++]);
		}
		ft_putchar('\n');
		k++;
	}
}

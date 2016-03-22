/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:59:07 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/22 19:05:59 by knzeng-e         ###   ########.fr       */
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
			printf("%d",map->tempon[k][j++]);
		}
		printf("\n");
		k++;
		//ft_putstr("\n");
	}
}

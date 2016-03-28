/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 23:05:56 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/28 01:26:29 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**ft_adding(int x, int y, int **tab)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < y)
	{
		j = 1;
		while (j < x)
		{
			if (tab[i][j] != 0)
				tab[i][j] = 1 + (find_minimum2(tab[i - 1][j], \
							tab[i][j - 1], tab[i - 1][j - 1]));
			j++;
		}
		i++;
	}
	return (tab);
}

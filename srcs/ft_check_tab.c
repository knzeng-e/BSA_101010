/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 23:20:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/27 23:21:11 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_tab	ft_check_tab(int **tab, int x, int y)
{
	t_tab	place;
	int		i;
	int		j;

	place.data = 0;
	place.data_i = 0;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (tab[i][j] > place.data)
				;
			if (tab[i][j] > place.data_i)
			{
				place.line = i;
				place.column = j;
				place.data_i = tab[i][j];
			}
			j++;
		}
		i++;
	}
	return (place);
}

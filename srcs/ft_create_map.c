/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:16:04 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/21 01:13:20 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	*ft_create_map(t_map *map, char *file)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	ft_initialize("FILE", map, file);
	if (file[0] != 0)
	{
		while (file[i] && file[i] != '\n')
			i++;
		count = ++i;
		while (file[i] && file[i] != '\n')
			i++;
		map->nb_columns = i - count;
	}
	return (map);
}

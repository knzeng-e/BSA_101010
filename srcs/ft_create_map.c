/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:16:04 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/18 18:02:11 by knzeng-e         ###   ########.fr       */
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
		while (file[i++] != '\n')
			;
		count = ++i;
		while (file[i++] != '\n')
			;
		map->nb_columns = i - count;
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:16:04 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/13 08:48:19 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	*ft_create_map(char *file)
{
	t_map	*map;
	int		fd;
	int		i;
	int		count;
	char	buffer[SIZE_BUF];

	if ((map = (t_map *)malloc(sizeof(t_map))))
	{
		i = 0;
		count = 0;
		if ((fd = open(file, O_RDONLY)) != -1)
		{
			buffer[read(fd, buffer, SIZE_BUF)] = '\0';
			ft_initialize(file, map, buffer);
			while (buffer[i++] != '\n')
				;
			count = ++i;
			while (buffer[i++] != '\n')
				;
			map->nb_columns = i - count;
			close(fd);
		}
	}
	return (map);
}

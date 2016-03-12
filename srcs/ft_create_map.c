/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:16:04 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/12 06:21:05 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	*ft_create_map(char *file)
{
	t_map	*map;
	int		fd;
	int		i;
	int		nb_lus;
	int		count;
	char	buffer[SIZE_BUF];

	map = (t_map *)malloc(sizeof(t_map));
	if (map)
	{
		i = 0;
		count = 0;
		fd = open(file, O_RDONLY);
		if (fd != -1)
		{
			nb_lus = read(fd, buffer, SIZE_BUF);
			buffer[nb_lus] = '\0';
			ft_initialize(file, map, buffer);
			while (buffer[i] != '\n')
				i++;
			count = ++i;
			while (buffer[i] != '\n')
				i++;
			map->nb_columns = i - count;
			close (fd);
		}
	}
	return (map);
}

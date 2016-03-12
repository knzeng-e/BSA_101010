/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:08:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/12 05:09:34 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_extract_map(t_map *map, char **tab)
{
	char	buf[map->nb_columns];
	int		fd;
	int		i;
	int		j;

	i = 0;
	fd = open(map->file_name, O_RDONLY);
	read(fd, buf, ft_get_size(map->nb_lines) + 4);
	buf[ft_get_size(map->nb_lines) + 3] = '\0';
	while((read(fd, buf, map->nb_columns)))
	{
		tab[i] = (char *)malloc(sizeof(char) * map->nb_columns);
		j = 0;
		while (j < map->nb_columns)
		{
			tab[i][j] = buf[j];
			j++;
		}
		read(fd, buf, 1);
		i++;
	}
	close (fd);
}

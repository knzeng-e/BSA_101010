/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:08:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/13 09:04:38 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_extract_map(t_map *map, char **tab)
{
	char	buf[map->nb_columns + 1];
	int		fd;
	int		i;
	int		j;
	int		lus;

	i = 0;
	fd = open(map->file_name, O_RDONLY);
	lus = read(fd, buf, ft_get_size(map->nb_lines) + 4);
	buf[ft_get_size(map->nb_lines) + 3] = '\0';
	while ((lus = (read(fd, buf, map->nb_columns))))
	{
		buf[lus] = '\n';
		buf[lus + 1] = '\0';
		if (i > map->nb_lines && lus != 0)
			return (INVALID_LINE_NUMBER);
		tab[i] = (char *)malloc(sizeof(char) * map->nb_columns + 1);
		j = 0;
		while (j <= map->nb_columns)
		{
			if ((j < map->nb_columns && buf[j] == '\n')\
					|| !(ft_is_valid_content(buf[j], map)))
				return (INVALID_MAP_CONTENT);
			tab[i][j] = buf[j];
			j++;
		}
		read(fd, buf, 1);
		i++;
	}
	close(fd);
	return (VALID_MAP_CONTENT);
}

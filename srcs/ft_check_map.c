/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 22:52:50 by mmoullec          #+#    #+#             */
/*   Updated: 2016/03/17 19:34:21 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <string.h>

void	ft_get_tab(char *rend, t_map *map)
{
	int i;
	int	j;
	int	cpt;
	int	nb_octets;

	map->contenu = (char **)malloc(sizeof(char*) * map->nb_lines);
	nb_octets = ft_get_size(map->nb_lines) + 4;
	map->infos = (char *)malloc(sizeof(char) * nb_octets);
	j = 0;
	while (*rend != '\n')
		map->infos[j++] = *(rend++);
	cpt = 1;
	map->infos[j] = '\0';
	i = 0;
	while (*(rend + cpt))
	{
		map->contenu[i] = (char *)malloc(sizeof(char) * map->nb_columns);
		j = 0;
		while (j < map->nb_columns)
			map->contenu[i][j++] = *(rend + cpt++);
		map->contenu[i++][j] = '\0';
		cpt++;
	}
}

t_map	*ft_check_map(int fd)
{
	t_map	*map;
	char	*rend;
	char	buf[2];

	rend = (char *)malloc(sizeof(char) * SIZE_BUF);
	*rend = '\0';
	map = (t_map *)malloc(sizeof(t_map));
	while ((read(fd, &buf, 1)))
	{
		buf[1] = '\0';
		ft_strcat(rend, buf);
	}
	map = ft_create_map(map, rend);
	if (!ft_check_empty(map))
		ft_get_tab(rend, map);
	free(rend);
	return (map);
}

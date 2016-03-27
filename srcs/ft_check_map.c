/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 22:52:50 by mmoullec          #+#    #+#             */
/*   Updated: 2016/03/27 08:38:08 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <string.h>

char	*ft_get_map2(int *fd)
{
	char	*tmp;
	char	*rend;
	char	buf[2];
	int		i;

	i = 1;
	rend = (char *)malloc(sizeof(char) * (i + 1));
	if (rend)
	{
		rend[0] = 0;
		while (read(*fd, &buf, 1))
		{
			tmp = (char *)malloc(sizeof(char) * (i + 1));
			rend = strcat(rend, &buf[0]);
			tmp = strcpy(tmp, rend);
			free(rend);
			rend = (char *)malloc(sizeof(char) * (i + 2));
			rend = strcpy(rend, tmp);
			free(tmp);
			i++;
		}
	}
	return (rend);
}

void	ft_get_tab(char *rend, t_map *map)
{
	int i;
	int	j;
	int	cpt;

	if (!(map->contenu = (char **)malloc(sizeof(char*) * map->nb_lines)))
		return ;
	if (!(map->infos = (char *)malloc(sizeof(char) * \
					(ft_get_size(map->nb_lines) + 4))))
		return ;
	j = 0;
	while (*rend != '\n')
		map->infos[j++] = *(rend++);
	cpt = 1;
	map->infos[j] = '\0';
	i = 0;
	while (*(rend + cpt))
	{
		if (!(map->contenu[i] = (char *)malloc(sizeof(char) * map->nb_columns)))
			return ;
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

	if (fd == -1)
		return (NULL);
	if (!(rend = ft_get_map2(&fd)))
		return (IMPOSSIBLE_MALLOC);
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (IMPOSSIBLE_MALLOC);
	map = ft_create_map(map, rend);
	if (!ft_check_empty(map))
		ft_get_tab(rend, map);
	free(rend);
	return (map);
}

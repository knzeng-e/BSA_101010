/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 22:52:50 by mmoullec          #+#    #+#             */
/*   Updated: 2016/03/29 16:36:09 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
			rend = ft_strcat(rend, &buf[0]);
			tmp = ft_strcpy(tmp, rend);
			free(rend);
			rend = (char *)malloc(sizeof(char) * (i + 2));
			rend = ft_strcpy(rend, tmp);
			free(tmp);
			i++;
		}
	}
	return (rend);
}

int		ft_modify(char *rend, t_map *map)
{
	int	cpt;
	int	i;
	int	j;

	cpt = 0;
	i = -1;
	while (*(rend + ++cpt))
	{
		++i;
		if ((i >= map->nb_lines) || !(map->tab[i] = (int *)malloc(sizeof(int)\
						* map->nb_columns)))
			return (-4);
		else
		{
			j = 0;
			while (*(rend + cpt) != '\n')
			{
				if (!ft_is_valid_content(*(rend + cpt), map) || \
						j >= map->nb_columns)
					return (-1);
				map->tab[i][j++] = (*(rend + cpt++) == map->vide) ? 1 : 0;
			}
		}
	}
	return (1);
}

int		ft_get_tab(char *rend, t_map *map)
{
	int		i;
	int		j;

	if (!(map->tab = (int **)malloc(sizeof(int*) * map->nb_lines)))
		return (-3);
	if (!(map->infos = (char *)malloc(sizeof(char) * \
					(ft_get_size(map->nb_lines) + 4))))
		return (-2);
	j = 0;
	while (*rend != '\n')
		map->infos[j++] = *(rend++);
	map->infos[j] = '\0';
	i = -1;
	return (ft_modify(rend, map));
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
	if (ft_check_empty(map) || (ft_get_tab(rend, map) < 0))
		return (NULL);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:08:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/17 19:24:08 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_first_line(t_map *map)
{
	int i;
	int	nb_octets;

	nb_octets = ft_get_size(map->nb_lines) + 4;
	i = 0;
	while (i < nb_octets)
		i++;
	if (ft_check_empty(map) || map->infos[i - 1] != '\0')
		return (INVALID_FIRST_LINE_SIZE);
	return (VALID_FIRST_LINE_SIZE);
}

int	ft_extract_map(t_map *map)
{
	int		i;
	int		j;

	if (ft_check_empty(map))
		return (ERROR_EMPTY_FILE);
	i = -1;
	while (++i < map->nb_lines)
	{
		j = -1;
		while (++j < map->nb_columns)
		{
			if ((j < map->nb_columns && (map->contenu[i][j]) == '\0') ||\
					!(ft_is_valid_content((map->contenu[i][j]), map)))
			{
				return (INVALID_MAP_CONTENT);
			}
		}
	}
	if (map->contenu[i - 1][j] != '\0')
	{
		return (INVALID_LINE_NUMBER);
	}
	return (VALID_MAP_CONTENT);
}

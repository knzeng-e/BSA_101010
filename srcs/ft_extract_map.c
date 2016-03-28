/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 05:08:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/28 01:19:14 by knzeng-e         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:26:23 by mmoullec          #+#    #+#             */
/*   Updated: 2016/03/13 08:43:30 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_errors(t_map *map)
{
	if ((ft_check_first_line(map) < 0))
		return (MAP_ERROR);
	return (MAP_OK);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_tab	placing;

	if (ac >= 2)
	{
		while (*(++av))
		{
			ft_putstr("\n===> ");
			ft_putstr(*av);
			ft_putstr(" <===\n");
			map = ft_create_map(*av);
			map->contenu = (char **)malloc(sizeof(char *) * map->nb_lines);
			if (ft_check_first_line(map) > 0)
			{
				if (ft_resolve(map, map->contenu, placing) > 0)
					;
				else
					ft_putstr("map error\n");
			}
			else
				ft_putstr("map error\n");
		}
	}
	return (0);
}

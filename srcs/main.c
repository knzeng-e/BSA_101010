/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:26:23 by mmoullec          #+#    #+#             */
/*   Updated: 2016/03/12 05:31:56 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int ac, char **av)
{
	t_map	*map;
	char	**tab;
	t_tab placing;

	if (ac >= 2)
	{
		while (*(++av))
		{
			map = ft_create_map(*av);
			tab = (char **)malloc(sizeof(char *) * map->nb_lines);
			ft_resolve(map, tab, placing);
		}
	}
	return (0);
}

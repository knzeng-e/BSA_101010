/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 23:03:22 by mmoullec          #+#    #+#             */
/*   Updated: 2016/03/27 08:45:12 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_tab	*placing;
	int		fd;
	int		i;
	int		ret;

	placing = (t_tab *)malloc(sizeof(t_tab));
	i = -1;
	while (++i < ac - 1 || ac == 1)
	{
		if (!(map = malloc(sizeof(t_map))))
			return (IMPOSSIBLE_MALLOC);
		fd = ((ac == 1) ? ac-- : open(av[i + 1], O_RDONLY));
		map = ft_check_map(fd);
		if ((map != NULL) && ft_check_first_line(map) > 0)
		{
			ret = ft_resolve(map, map->contenu, *placing);
			if (ret < 0)
				ft_putstr("map error\n");
		}
		else
			ft_putstr("map error\n");
		free(map);
	}
	return (0 && (close(fd) == -1));
}

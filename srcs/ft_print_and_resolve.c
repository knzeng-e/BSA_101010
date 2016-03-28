/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_and_resolve.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 00:53:37 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/28 02:45:29 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_and_resolve(int **tab, t_map *map)
{
	t_tab place;

	tab = ft_adding(map->nb_columns, map->nb_lines, tab);
	place = ft_check_tab(tab, map->nb_columns, map->nb_lines);
	exec(tab, place, map);
}

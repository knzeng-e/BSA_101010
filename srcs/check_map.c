/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 19:20:57 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/13 08:44:27 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_first_line(t_map *map)
{
	int		fd;
	int		lsize;
	int		lus;
	char	buf[SIZE_BUF + 1];

	fd = open(map->file_name, O_RDONLY);
	lus = read(fd, buf, SIZE_BUF);
	buf[lus] = '\0';
	lsize = 3 + ft_get_size(atoi(buf));
	if (buf[lsize] != '\n')
		return (INVALID_FIRST_LINE_SIZE);
	close(fd);
	return (VALID_FIRST_LINE_SIZE);
}

int	ft_is_valid_content(char c, t_map *map)
{
	return (c == map->vide || c == map->obstacle || c == map->plein || \
			c == '\0' || c == '\n');
}

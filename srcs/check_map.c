/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 19:20:57 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/12 05:44:51 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	if (!(*str))
		return (0);
	return (1 + ft_strlen(++str));
}

int	ft_check_first_line(t_map *map)
{
	int		fd;
	int		lsize;
	char	buf[SIZE_BUF + 1];

	lsize = 3 + ft_get_size(atoi(buf));
	fd = open(map->file_name, O_RDONLY);
	read(fd, buf, SIZE_BUF);
	buf[SIZE_BUF] = '\0';
	if (buf[lsize] != '\n')
		return (INVALID_FIRST_LINE_SIZE);
	close(fd);
	return (VALID_FIRST_LINE_SIZE);
}

int	ft_is_valid_content(char c, t_map *map)
{
	return (c == map->vide || c == map->obstacle || c == map->plein);
}

int	ft_check_config(t_map *map)
{
	int	line;
	int	column;
	int	count_col;
	int	count_lin;

	count_lin = 0;
	column = 0;
	line = 0;
	while (map->contenu[line][column] != '\0')
	{
		count_lin++;
		if (count_lin >= map->nb_lines)
			return (INVALID_LINE_NUMBER);
		column = 0;
		count_col = 0;
		while (map->contenu[line][column++] != '\n')
		{
			count_col++;
			if (count_col >= map->nb_columns)
				return (INVALID_COLUMN_NUMBER);
			if (!ft_is_valid_content(map->contenu[line][column], map))
				return (INVALID_MAP_CONTENT);
		}
		line++;
	}
	return (VALID_MAP_CONTENT);
}

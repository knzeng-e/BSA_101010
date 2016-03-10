/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:26:23 by mmoullec          #+#    #+#             */
/*   Updated: 2016/03/10 19:12:16 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
}

char	find_minimum(char a, char b, char c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= c && b <= a)
		return (b);
	else if (c <= a && c <= b)
		return (c);
	return (a);
}

void	ft_extract_map(t_map *map, char **tab)
{
	char	buf[map->nb_columns];
	int		fd;
	int		i;
	int		j;

	i = 0;
	fd = open(map->file_name, O_RDONLY);
	read(fd, buf, ft_get_size(map->nb_lines) + 4);
	buf[ft_get_size(map->nb_lines) + 3] = '\0';
	while((read(fd, buf, map->nb_columns)))
	{
		tab[i] = (char *)malloc(sizeof(char) * map->nb_columns);
		j = 0;
		while (j < map->nb_columns)
		{
			tab[i][j] = buf[j];
			j++;
		}
		read(fd, buf, 1);
		i++;
	}
	close (fd);
}

t_tab	check_tab(t_map *map, char **tab)
{
	t_tab	place;
	place.data = 0;
	int i = 0;
	int j;

	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			if (tab[i][j] > place.data)
			{
				place.line = i;
				place.column = j;
				place.data = tab[i][j];
			}
			j++;
		}
		i++;
	}
	return (place);
}

void	ft_adding(char **tab, t_map *map)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < map->nb_lines)
	{
		j = 1;
		while (j < map->nb_columns)
		{
			if (tab[i][j] != '0')
				tab[i][j] = 1 + (find_minimum(tab[i-1][j], tab[i][j-1], \
							tab[i-1][j-1]));
			j++;
		}
		i++;
	}
}

void	ft_print_map(t_map *map, char **tab)
{
	int	k;

	k = 0;
	while (k < map->nb_lines)
	{
		ft_putstr(tab[k++]);
		ft_putstr("\n");
	}
}

void	exec(t_map *map, t_tab pos, char **tab)
{
	int i = 0;
	int j = 0;

	int k = pos.line - (pos.data - '0') + 1;
	int l = pos.column - (pos.data - '0') + 1;
	i = 0;
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			if ((k <= i && i <= pos.line) && (l <= j && j <= pos.column))
				tab[i][j] = 'x';
			else
				if (tab[i][j] == '0')
					tab[i][j] = map->obstacle;
				else
					tab[i][j] = map->vide;
			j++;
		}
		i++;
	}
	ft_print_map(map, tab);
}

int		ft_get_size(int nbr)
{
	if (nbr < 10)
		return (1);
	return (1 + ft_get_size(nbr / 10));
}

void	ft_initialize(char *file, t_map *map, char *buffer)
{
	int	size;

	map->nb_lines = atoi(buffer);
	size = ft_get_size(map->nb_lines);
	map->vide = *(buffer + size);
	map->obstacle = *(buffer + size + 1);
	map->plein = *(buffer + size + 2);
	map->file_name = file;
}

t_map	*ft_create_map(char *file)
{
	t_map	*map;
	int		fd;
	int		i;
	int		nb_lus;
	int		count;
	char	buffer[SIZE_BUF];

	map = (t_map *)malloc(sizeof(t_map));
	if (map)
	{
		i = 0;
		count = 0;
		fd = open(file, O_RDONLY);
		if (fd != -1)
		{
			nb_lus = read(fd, buffer, SIZE_BUF);
			buffer[nb_lus] = '\0';
			ft_initialize(file, map, buffer);
			while (buffer[i] != '\n')
				i++;
			count = ++i;
			while (buffer[i] != '\n')
				i++;
			map->nb_columns = i - count;
			close (fd);
		}
	}
	return (map);
}

void	ft_resolve(t_map *map, char **tab, t_tab placing)
{
	int i;
	int j;

	ft_extract_map(map, tab);
	i = 0;
	while(i < map->nb_lines)
	{
		j = 0;
		while(j < map->nb_columns)
		{
			if (tab[i][j] == '.')
				tab[i][j] = '1';
			else
				tab[i][j] = '0';
			j++;
		}
		i++;
	}
	ft_adding(tab, map);
	placing = check_tab(map, tab);

	exec(map, placing, tab);

}

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

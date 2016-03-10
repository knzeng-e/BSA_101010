/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:26:23 by mmoullec          #+#    #+#             */
/*   Updated: 2016/03/10 17:18:51 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		find_minimum(char a, char b, char c)
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
	int		size;
	int		lus;

	i = 0;
	size = ft_get_size(map->nb_lines) + 3;
	fd = open(map->file_name, O_RDONLY);
	read(fd, buf, size + 1);
	buf[size] = '\0';
	while((lus = read(fd, buf, map->nb_columns)))
	{
		tab[i] = (char *)malloc(sizeof(char) * map->nb_columns);
		j = 0;
		while (j < map->nb_columns)
		{
			buf[lus] = '\0';
			tab[i][j] = buf[j];
			j++;
		}
		printf("\n%d = %s", i, tab[i]);
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
				tab[i][j] = 1 + (find_minimum(tab[i-1][j], tab[i][j-1], tab[i-1][j-1]));
			j++;
		}
		i++;
	}
}

void	exec(t_map *map, t_tab pos, char **tab)
{
	int i = 0;
	int j = 0;

	int k = pos.line - (pos.data - '0') + 1;
	int l = pos.column - (pos.data - '0') + 1;
	printf("\n%d, %d", k, l );
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
	printf("==>  tab4  <==\n");
	for (int k = 0; k < map->nb_lines; k++)
		printf("%s\n", tab[k]);
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
	char	buffer[SIZE_BUF + 1];

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
			map->nb_columns =  i - count;
			close (fd);
		}
	}
	return (map);
}

void	ft_wait(int	nb_secondes)
{
	int		a = 1;
	while (a)
	{
		sleep(nb_secondes);
		a = 0;
	}
}
void	print_config(t_map *map)
{

	printf("\n\n *** CONFIGURATION DE LA MAP ***\n\tNombre de lignes ==> %d", map->nb_lines);
	printf("\n\tChar vide ==> %c", map->vide);
	printf("\n\tChar obstacle ==> %c", map->obstacle);
	printf("\n\tChar plein ==> %c", map->plein);
	printf("\n\tnom du fichier ==> \"%s\"\n\n", map->file_name);
	ft_wait(2);

}

int main(int ac, char **av)
{
	t_map	*map;
	char	**tab;
	t_tab placing;
	int i = 0;
	int j = 0;
	int k = 0;

	if (ac >= 2)
	{
		while (*(++av))
		{
			map = ft_create_map(*av);
			tab = (char **)malloc(sizeof(char *) * map->nb_lines);
			print_config(map);
			ft_extract_map(map, tab);
			printf("\nNombre de colonnes = %d", map->nb_columns);
			i = 0;
			printf("\n==> tab <==\n");
			while (i < map->nb_lines)
			{
				printf("%d - %s\n", i, tab[i]);
				i++;
			}
			ft_wait(4);
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
			printf("\n==> tab2 <==\n");
			k = 0;
			while(k < map->nb_lines)
			{
				printf("%s\n", tab[k]);
				k++;
			}
			ft_adding(tab, map);
			printf("\n==> tab3 <==\n");
			k = 0;
			while(k < map->nb_lines)
			{
				printf("%s\n", tab[k]);
				k++;
			}
			placing = check_tab(map, tab);

			printf("\nplacing\n");
			printf("ligne = %d\n", placing.line);
			printf("colonne = %d\n", placing.column);
			printf("taille carre = %c\n", placing.data);
			exec(map, placing, tab);

		}
	}
	return (0);
}

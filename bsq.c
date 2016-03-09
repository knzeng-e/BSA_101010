/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:26:23 by mmoullec          #+#    #+#             */
/*   Updated: 2016/03/09 21:38:20 by knzeng-e         ###   ########.fr       */
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

char	**ft_extraxt_map(t_map *map)
{
	char	**tab;
	char	buff[map->nb_columns];
	int		fd;
	int		i;
	int		lus;

	tab = (char **)malloc(sizeof(char *) * map->nb_lines * map->nb_columns);
	fd = open(map->file_name, O_RDONLY);
	read(fd, buff, 5);
	i = 0;
	while (i < map->nb_lines)
	{
		lus = read(fd, buff, map->nb_columns);
		buff[lus] = '\0';
		strcpy(tab[i++], buff);
		read(fd, buff, 1);
	}
	close(fd);
	return (tab);
}

t_tab	check_tab(t_map *map)
{
	t_tab	place;
	char	**tab;
	place.data = 0;
	int i = 0;
	int j;

	tab = map->ft_extract_map(map);
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

void	exec(char *file_name, t_map *map, t_tab pos)
{
	int fd;
	char **tab;
	char buf[map->nb_columns];
	int i = 0;
	int j = 0;

	tab = map->ft_extract_map(map);
	fd = open(file_name, O_RDONLY);
	while(read(fd, &buf, map->nb_columns))
	{
		buf[map->nb_columns] = '\0';
		strcpy(tab[i], buf);
		i++;
	}
	int k = pos.line - (pos.data - '0') + 1;
	int l = pos.column - (pos.data - '0') + 1;
	printf("%d, %d", k, l );
	close (fd);
	i = 0;
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			if ((k <= i && i <= pos.line) && (l <= j && j <= pos.column))
				tab[i][j] = 'x';
			j++;
		}
		i++;
	}
	printf("==>  tab4  <==\n");
	for (int k = 0; k < map->nb_lines; k++)
		printf("%s\n", tab[k]);
}

void	ft_initialize(char *file, t_map *map, char *buffer)
{
	map->nb_lines = atoi(&buffer[0]);
	map->vide = buffer[1];
	map->obstacle = buffer[2];
	map->plein = buffer[3];
	map->file_name = file;
}

t_map	*ft_create_map(char *file)
{
	t_map	*map;
	int		fd;
	int		nb_lus;
	int		count;
	char	buffer[SIZE_BUF + 1];

	map = (t_map *)malloc(sizeof(t_map));
	if (map)
	{
		count = 0;
		fd = open(file, O_RDONLY);
		if (fd != -1)
		{
			nb_lus = read(fd, buffer, 5);
			ft_initialize(file, map, buffer);
			while (read(fd, buffer, 1) && *buffer != '\n' && ++count)
				;
			map->nb_columns = count;
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
	int fd;
	int	nb_cols;
	int	nb_lines;
	int	lus;
	t_map	*map;
	//char	tab[9][28];
	char	**tab;
	char	*buf;
	t_tab placing;
	int i = 0;
	int j = 0;
	int k = 0;

	if (ac >= 2)
	{
		while (*(++av))
		{
			map = ft_create_map(*av);
			print_config(map);
			tab = (char **)malloc(sizeof(char *) * map->nb_lines * map->nb_columns);
			//tab = map->ft_extract_map(map);
			//printf("\nTAB => %s >>", tab[0]); SEGFAULT::revoir ft_extract
			nb_cols = map->nb_columns;
			nb_lines = map->nb_lines;
			buf = (char *)malloc(sizeof(char) * nb_cols);
			fd = open(*av, O_RDONLY);
			read(fd, buf, 4);
			buf[4] = '\0';
			printf("\nPremiere ligne ==> %s\n", buf);
			read(fd, buf, 1);
			while((lus = read(fd, buf, nb_cols)))
			{
				tab[i] = (char *)malloc(sizeof(char) * nb_cols);
				tab[i] = buf;
				buf[lus] = '\0';
				printf("\n%d = %s", i, tab[i]);
			//	printf("\n%d = %s", i, buf);
				read(fd, buf, 1);
				//strcpy(tab[i], buf);
				i++;
			}
				read(fd, buf, 1);
			close (fd);
			i = 0;
			printf("\n==> tab <==\n");
			while(i < nb_lines)
			{
				printf("%d - %s\n", i, tab[i]);
				i++;
			}
	ft_wait(4);
			i = 0;
			while(i < nb_lines)
			{
				j = 0;
				while(j < nb_cols)
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
			while(k < nb_lines)
			{
				printf("%s\n", tab[k]);
				k++;
			}
			ft_adding(tab, map);
			printf("\n==> tab3 <==\n");
			k = 0;
			while(k < nb_lines)
			{
				printf("%s\n", tab[k]);
				k++;
			}
			placing = check_tab(map);

			printf("placing\n");
			printf("ligne = %d\n", placing.line);
			printf("colonne = %d\n", placing.column);
			printf("taille carre = %c\n", placing.data);
			exec(*av, map, placing);

		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:26:23 by mmoullec          #+#    #+#             */
/*   Updated: 2016/03/09 17:17:19 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_tab
{
	int line;
	int column;
	char data;
}				t_tab;

char		find_minimum(char a, char b, char c)
{
	char d;
	//	printf("%c, %c, %c\n", a, b, c);

	d = '4';
	if (a <= b && a <= c)
		return (a);
	else if (b <= c && b <= a)
		return (b);
	else if (c <= a && c <= b)
		return (c);
	return (a);
}

t_tab	check_tab(char tab[9][28])
{
	t_tab	place;
	place.data = 0;
	int i = 0;
	int j;
	while (i < 9)
	{
		j = 0;
		while (j < 27)
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

void	ft_adding(char	tab[9][28])
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < 9)
	{
		j = 1;
		while (j < 27)
		{
			if (tab[i][j] == '0')
				tab[i][j] = tab[i][j];
			else
				tab[i][j] = 1 + (find_minimum(tab[i-1][j], tab[i][j-1], tab[i-1][j-1]));
			j++;
		}
		i++;
	}
}

void	exec(char *file_name, t_tab placement)
{
	int fd;
	char tab[9][28];
	char buf[28];
	int i = 0;
	int j = 0;
	fd = open(file_name, O_RDONLY);
	while(read(fd, &buf, 28))
	{
		buf[27] = '\0';
		strcpy(tab[i], buf);
		i++;
	}
	int k = placement.line - (placement.data - '0') + 1;
	int l = placement.column - (placement.data - '0') + 1;
	printf("%d, %d", k, l );
	close (fd);
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 27)
		{
			if ((k <= i && i <= placement.line) && (l <= j && j <= placement.column))
			{
				tab[i][j] = 'x';
			}
			j++;
		}
		i++;
	}
	printf("==>  tab4  <==\n");
	for (int k = 0; k < 9; k++)
		printf("%s\n", tab[k]);
}

int main(int ac, char **av)
{
	int fd;
	char tab[9][28];
	char buf[28];
	int i = 0;
	int j = 0;
	t_tab placing;

	if (ac >= 2)
	{
		fd = open(av[1], O_RDONLY);
		while(read(fd, &buf, 28))
		{
			buf[27] = '\0';
			printf("%d = %s\n", i, buf);
			strcpy(tab[i], buf);
			i++;
		}
		close (fd);
		int k = 0;
		printf("\n==> tab <==\n");
		while(k < 9)
		{
			printf("%s\n", tab[k]);
			k++;
		}
		i = 0;
		while(i < 9)
		{
			j = 0;
			while(j < 27)
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
		while(k < 9)
		{
			printf("%s\n", tab[k]);
			k++;
		}
		ft_adding(tab);
		printf("\n==> tab3 <==\n");
		k = 0;
		while(k < 9)
		{
			printf("%s\n", tab[k]);
			k++;
		}
		placing = check_tab(tab);

		printf("placing\n");
		printf("ligne = %d\n", placing.line);
		printf("colonne = %d\n", placing.column);
		printf("taille carre = %c\n", placing.data);
		exec(av[1], placing);
	}
}

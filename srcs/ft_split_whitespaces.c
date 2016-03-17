/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 19:50:47 by mmoullec          #+#    #+#             */
/*   Updated: 2016/03/15 22:49:08 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\v'
			|| c == '\f' || c == '\r' || c == '\n')
		return (1);
	return (0);
}

int		ft_count_words(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (!(ft_isspace(str[i]) == 1))
			if ((ft_isspace(str[i + 1]) || str[i + 1] == '\0'))
				k++;
		i++;
	}
	return (k);
}

char	*ft_put_in_line(char *str, char *tab, int i)
{
	int j;

	j = 0;
	if ((tab = (char*)malloc(sizeof(tab) * i)) == NULL)
		return (0);
	while (j < i)
	{
		tab[j] = str[j];
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

int		ft_count_letters(char *str)
{
	int i;

	i = 0;
	while (!(ft_isspace(str[i])) && str[i] != '\0')
		i++;
	return (i);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		x;
	int		j;
	char	**tab;

	i = 0;
	x = 0;
	j = ft_count_words(str);
	if ((tab = (char**)malloc(sizeof(*tab) * (j + 1))) == NULL)
		return (0);
	while (x < j)
	{
		i = ft_count_letters(str);
		if (i > 0)
		{
			tab[x] = ft_put_in_line(str, tab[x], i);
			x++;
		}
		if (str[i] != '\0' && x < j)
			i++;
		str = &str[i];
	}
	tab[x] = 0;
	return (tab);
}

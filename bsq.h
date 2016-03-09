/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 09:24:14 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/09 17:09:13 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <string.h>

# define SIZE_BUF 4096



typedef struct	s_tab
{
	int line;
	int column;
	char data;
}				t_tab;

typedef struct	s_plateau
{
	int			nb_lines;
	int			nb_columns;
	char		*file_name;
	char		vide;
	char		obstacle;
	char		plein;
	char		**(*ft_extract_map)(struct s_plateau *);
}				t_map;

/*typedef struct	s_map
{
	t_plateau	*config;
	//t_tab		tab[config->nb_lines][config->nb_columns];
}				t_map;*/

char			find_minimum(char a, char b, char c);
t_tab			check_tab(t_map *map);
char			**(*ft_extract_map)(t_map *plat);
void			ft_adding(char **tab, t_map *map);
void			exec(char *file_name,t_map *map, t_tab pos);
t_map			ft_get_map(char *file_name);
t_map			*ft_create_map(char	*file);
void			ft_initialize(char *file, t_map *map, char *buffer);

#endif

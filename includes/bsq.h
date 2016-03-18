/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 09:24:14 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/18 03:27:08 by knzeng-e         ###   ########.fr       */
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
# define INVALID_FIRST_LINE_SIZE -1
# define VALID_FIRST_LINE_SIZE 1
# define INVALID_MAP_CONTENT -2
# define VALID_MAP_CONTENT 2
# define INVALID_LINE_NUMBER -3
# define INVALID_COLUMN_NUMBER -4
# define ERROR_EMPTY_FILE -5
# define MAP_ERROR -6
# define MAP_OK 3



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
	char		*infos;
	char		vide;
	char		obstacle;
	char		plein;
	char		**contenu;
}				t_map;

int				ft_get_size(int nbr);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
int				ft_check_empty(t_map *map);
int				ft_check_first_line(t_map *map);
int				ft_is_valid_content(char c, t_map *map);
int				ft_check_config(t_map *map);
int				ft_extract_map(t_map *map);
int				ft_resolve(t_map *map, char **tab, t_tab placing);
int				ft_invalid_content(char c, t_map *map);
char			find_minimum(char a, char b, char c);
void			ft_putstr(char *str);
void			ft_initialize(char *file, t_map *map, char *buffer);
void			ft_adding(char **tab, t_map *map);
void			ft_print_map(t_map *map, char **tab);
void			exec(t_map *map, t_tab pos, char **tab);
t_map			ft_get_map(char *file_name);
t_map			*ft_create_map(t_map *map, char *file);
t_tab			check_tab(t_map *map, char **tab);
void			ft_bsq_analyse(t_map *map, t_tab placing);
t_map			*ft_create_map2();
char			**ft_split_whitespaces(char *str);
t_map			*ft_check_map(int fd);
char			*ft_strcat(char *s1, char *s2);
int				ft_isspace(char c);

#endif

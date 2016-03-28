/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 09:24:14 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/28 02:38:04 by knzeng-e         ###   ########.fr       */
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
# define IMPOSSIBLE_MALLOC 0
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
	int			line;
	int			column;
	int			data_i;
	char		data;
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
	int			**tab;
}				t_map;

int				ft_get_size(int nbr);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
int				ft_check_empty(t_map *map);
int				ft_check_first_line(t_map *map);
int				ft_is_valid_content(char c, t_map *map);
int				ft_check_config(t_map *map);
int				ft_extract_map(t_map *map);
int				ft_resolve(t_map *map);
int				ft_invalid_content(char c, t_map *map);
int				**ft_adding(int x, int y, int **tab);
int				find_minimum2(int a, int b, int c);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_initialize(char *file, t_map *map, char *buffer);
void			ft_print_and_resolve(int **tab, t_map *map);
void			ft_print_map(t_map *map, char **tab);
void			ft_print_map2(t_map *map);
void			exec(int **tab, t_tab pos, t_map *map);
void			ft_bsq_analyse(t_map *map, t_tab placing);
t_map			ft_get_map(char *file_name);
t_map			*ft_create_map(t_map *map, char *file);
t_tab			check_tab(t_map *map, char **tab);
t_tab			ft_check_tab(int **tab, int x, int y);
t_map			*ft_check_map(int fd);
char			find_minimum(char a, char b, char c);
char			**ft_split_whitespaces(char *str);
char			*ft_strcat(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
int				ft_isspace(char c);
#endif

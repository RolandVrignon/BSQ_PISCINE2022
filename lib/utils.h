/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eannesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:36:06 by eannesta          #+#    #+#             */
/*   Updated: 2022/03/27 23:36:09 by eannesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct solutions
{
    int     x;
    int     y;
    int     L;
    struct solutions *prev;
    struct solutions *next;
} t_solutions;

typedef struct s_infos
{
    int lines;
    char obstacle;
    char full;
}   t_infos;

typedef struct s_point
{
    int x;
    int y;
}   t_point;

void			ft_putchar(char c);

void			ft_putstr(char *str);

int				ft_nblen(long nb);

char			*ft_itoa(int nbr);

int				ft_strlen(char *str);

int				ft_strcmp(char *s1, char *s2);

int				ft_atoi(char *str);

int				x(char c, char *charset);

int				how_many_str(char *str, char *charset);

void			fill_tab(int index, int last_index, char *tab, char *str);

char			**process(int size, char **tab, char *s, char *ch);

char			**ft_split(char *str, char *charset);

unsigned int	strlen_space(char *str);

char			*ft_split_key(char *str);

char			*ft_split_value(char *str);

t_solutions	    *create_element(t_solutions *tmp, int x, int y, int l);

void			add_element(t_solutions *solutions, int x, int y, int l);

// t_dict			*create_list(int ac, char *file);

// t_dict			*go_to(t_dict *dict, int int_search);

int             linear_congruenial_generator(int x_gen, int c);

void			print_element(char *str);

char			*ft_substr(char *str, int pos, int len);

char			**triple_process(char *str, char **tab, int len, int modulo);

char			**triple_tab(char *str);

int     		check_points(char **tab, t_point *point, int l, t_infos *infos);

char            **solve(char **tab, int x, int y, t_infos *infos);

#endif

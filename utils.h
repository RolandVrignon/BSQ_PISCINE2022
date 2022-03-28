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

typedef struct dict
{
	char		*key;
	char		*value;
	struct dict	*next;
	struct dict	*previous;
}	t_dict;

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

t_dict			*create_element(char *str, t_dict *tmp);

void			add_element(char *str, t_dict *elem);

t_dict			*create_list(int ac, char *file);

t_dict			*go_to(t_dict *dict, int int_search);

void			print_element(char *str);

char			*ft_substr(char *str, int pos, int len);

char			**triple_process(char *str, char **tab, int len, int modulo);

char			**triple_tab(char *str);

void			print_number(char *nbr, t_dict *dict);

void			print_tab(t_dict *dict, char **tab);

int				linear_congruenial_generator(int x_gen, int c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eannesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:34:18 by eannesta          #+#    #+#             */
/*   Updated: 2022/03/27 23:34:20 by eannesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// t_dict	*go_to(t_dict *dict, int int_search)
// {
// 	char	*search;
// 	int		current_key;

// 	search = ft_itoa(int_search);
// 	current_key = ft_atoi(dict->key);
// 	if (int_search > current_key)
// 	{
// 		while (ft_strcmp(search, dict->key) != 0 && dict->next != NULL)
// 			dict = dict->next;
// 	}
// 	else if (int_search < current_key)
// 	{
// 		while (ft_strcmp(search, dict->key) != 0 && dict->next != NULL)
// 			dict = dict->previous;
// 	}
// 	return (dict);
// }

char	*ft_substr(char *str, int pos, int len)
{
	int		i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		tmp[i] = str[i + pos];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**triple_process(char *str, char **tab, int len, int modulo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (modulo != 0)
	{
		tab[0] = ft_substr(str, i, modulo);
		j++;
		i = modulo;
	}
	while (len > 0)
	{
		tab[j] = ft_substr(str, i, 3);
		j++;
		i += 3;
		len--;
	}
	tab[j] = malloc(sizeof(char) * 1);
	tab[j] = 0;
	return (tab);
}

char	**triple_tab(char *str)
{
	int		i;
	int		len;
	int		modulo;
	char	**tab;

	i = 0;
	while (str[i] != '\0')
		i++;
	len = i / 3;
	modulo = i % 3;
	if (modulo != 0)
		tab = malloc(sizeof(char *) * (len + 2));
	else
		tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (0);
	tab = triple_process(str, tab, len, modulo);
	return (tab);
}

void	print_element(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, " ", 1);
}

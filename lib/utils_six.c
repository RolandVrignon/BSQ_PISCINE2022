/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eannesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:35:02 by eannesta          #+#    #+#             */
/*   Updated: 2022/03/27 23:35:03 by eannesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// void	end_print(int hundred, int dizaine, int units, t_dict *dict)
// {
// 	if (hundred != 0)
// 	{
// 		dict = go_to(dict, hundred);
// 		print_element(dict->value);
// 		dict = go_to(dict, 100);
// 		print_element(dict->value);
// 	}
// 	if (dizaine != 0)
// 	{
// 		dict = go_to(dict, dizaine);
// 		print_element(dict->value);
// 	}
// 	if (units != 0)
// 	{
// 		dict = go_to(dict, units);
// 		print_element(dict->value);
// 	}
// 	if (!hundred && !dizaine && !units)
// 		return ;
// }

// void	print_number(char *nbr, t_dict *dict)
// {
// 	int		nb;
// 	int		hundred;
// 	int		dizaine;
// 	int		units;

// 	hundred = 0;
// 	dizaine = 0;
// 	units = 0;
// 	nb = ft_atoi(nbr);
// 	if (nb / 100 > 0)
// 	{
// 		hundred = nb / 100;
// 		nb = nb % (hundred * 100);
// 	}
// 	if (nb / 10 > 1)
// 	{
// 		dizaine = (nb / 10) * 10;
// 		nb = nb % dizaine;
// 	}
// 	if (nb > 0)
// 		units = nb;
// 	end_print(hundred, dizaine, units, dict);
// }

// void	test(t_dict *dict, int power)
// {
// 	char	*test;
// 	int		k;
// 	t_dict	*p_dict;

// 	test = malloc(sizeof(char) * 3);
// 	k = 0;
// 	while (power + 1 > 0)
// 	{
// 		if (k == 0)
// 			test[0] = '1';
// 		else
// 			test[k] = '0';
// 		k++;
// 		power--;
// 	}
// 	test[k] = '\0';
// 	p_dict = dict;
// 	while (ft_strcmp(test, p_dict->key) != 0 && p_dict->next != NULL)
// 		p_dict = p_dict->next;
// 	print_element(p_dict->value);
// }

// void	print_tab(t_dict *dict, char **tab)
// {
// 	int	size;
// 	int	i;
// 	int	power;

// 	size = 0;
// 	i = 0;
// 	power = 0;
// 	while (tab[size])
// 		size++;
// 	while (i < size)
// 	{
// 		print_number(tab[i], dict);
// 		power = ((size - 1) - i) * 3;
// 		if (power != 0 && strcmp(tab[i], "000") != 0)
// 			test(dict, power);
// 		i++;
// 	}
// }

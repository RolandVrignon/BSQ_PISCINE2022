/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eannesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:35:17 by eannesta          #+#    #+#             */
/*   Updated: 2022/03/27 23:35:18 by eannesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_nblen(long nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nbr)
{
	long	nb;
	int		i;
	char	*tab;

	nb = nbr;
	i = ft_nblen(nbr);
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	tab[i] = '\0';
	i--;
	if (nb == 0)
		tab[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		tab[0] = '-';
	}
	while (nb > 0)
	{
		tab[i] = '0' + (nb % 10);
		nb /= 10;
		i--;
	}
	return (tab);
}

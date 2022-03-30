/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eannesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:34:01 by eannesta          #+#    #+#             */
/*   Updated: 2022/03/27 23:34:03 by eannesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

int	x(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	how_many_str(char *str, char *charset)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!x(str[0], charset))
		nb = nb + 1;
	while (str[i] != '\0')
	{
		if (x(str[i], charset) && !x(str[i + 1], charset) && str[i + 1] != '\0')
			nb = nb + 1;
		i++;
	}
	return (nb + 1);
}

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

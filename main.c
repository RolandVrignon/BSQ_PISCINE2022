/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:52:06 by rvrignon          #+#    #+#             */
/*   Updated: 2022/03/30 13:54:09 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "lib/utils.h"

int	main(int ac, char **av)
{
	char	**lines;
	int		i;

	if (ac >= 2)
	{
		i = 1;
		while (av[i])
		{
			lines = open_file(av[i]);
			if (!check(lines))
				i++;
			else
			{
				make_process(lines);
				i++;
			}
		}
	}
	else if (ac == 1)
		write(1, "Hello\n", 6);
	return (0);
}

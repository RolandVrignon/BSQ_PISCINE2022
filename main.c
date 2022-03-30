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

char	*parser(int file)
{
	int		fd;
	char	ch;
	char	*filename;

	filename = malloc(sizeof(char) * 9);
	filename = "./tmp.ox";
	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		return (0);
	while (read(file, &ch, 1) != 0 && ch != EOF)
		write(fd, &ch, 1);
	close(fd);
	return (filename);
}

int	main(int ac, char **av)
{
	char	**lines;
	int		i;
	char	*file;

	if (ac >= 2)
	{
		i = 1;
		while (av[i])
		{
			lines = open_file(av[i]);
			if (check(lines))
				make_process(lines);
			i++;
		}
	}
	else if (ac == 1)
	{
		file = parser(0);
		lines = open_file(file);
		write(1, "\n\n", 2);
		if (check(lines))
			make_process(lines);
	}
	return (0);
}

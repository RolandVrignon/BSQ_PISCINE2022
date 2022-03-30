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

void	free_tab(char **lines)
{
	int		i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
}

char	*parser(int file)
{
	int		fd;
	char	ch;
	char	*filename;

	filename = malloc(sizeof(char) * 9);
	filename = "./tmp.ox";
	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	while (read(file, &ch, 1) != 0 && ch != EOF)
		write(fd, &ch, 1);
	close(fd);
	return (filename);
}

void	without_args(void)
{
	char	**lines;
	char	*file;

	file = parser(0);
	lines = open_file(file);
	write(1, "\n\n", 2);
	if (!check(lines))
		return ;
	make_process(lines);
	free_tab(lines);
	free(lines);
}

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
			if (check(lines))
			{
				make_process(lines);
				free_tab(lines);
				free(lines);
			}
			i++;
		}
	}
	else if (ac == 1)
		without_args();
	return (0);
}

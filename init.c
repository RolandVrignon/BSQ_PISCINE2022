/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:59:35 by rvrignon          #+#    #+#             */
/*   Updated: 2022/03/30 14:03:13 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/utils.h"

t_infos	*get_informations(char *str)
{
	t_infos	*infos;
	int		i;
	char	*line;

	i = 0;
	infos = (t_infos *)malloc(sizeof(t_infos));
	while (str[i] != '\0')
		i++;
	infos->empty = str[i - 3];
	infos->obstacle = str[i - 2];
	infos->full = str[i - 1];
	line = ft_substr(str, 0, i - 3);
	infos->lines = ft_atoi(line);
	infos->line_length = 0;
	return (infos);
}

int	file_size(char *file)
{
	int		fd;
	char	i;
	int		n;

	i = 0;
	n = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &i, 1) != 0 && i != EOF)
		n++;
	close(fd);
	return (n);
}

char	**open_file(char *str)
{
	char	**lines;
	void	*read_buffer;
	int		file_length;
	int		fd;

	file_length = file_size(str);
	if (!file_length)
		return (0);
	fd = open(str, O_RDONLY);
	read_buffer = malloc(sizeof(char *) * file_length);
	close(fd);
	fd = open(str, O_RDONLY);
	read(fd, read_buffer, file_length);
	lines = ft_split(read_buffer, "\n");
	return (lines);
}

char	**create_tab(char **lines, t_infos *infos, int line_length)
{
	char	**map;
	int		i;
	int		j;
	int		a;
	int		b;

	map = malloc(sizeof(char *) * infos->lines);
	i = 1;
	a = 0;
	while (i < infos->lines + 1)
	{
		j = 0;
		b = 0;
		map[a] = malloc(sizeof(char) * line_length + 1);
		while (j < line_length)
		{
			map[a][b] = lines[i][j];
			j++;
			b++;
		}
		a++;
		i++;
	}
	return (map);
}

int	get_line_length(char *lines)
{
	int	i;

	i = 0;
	while (lines[i] != '\0')
		i++;
	return (i);
}

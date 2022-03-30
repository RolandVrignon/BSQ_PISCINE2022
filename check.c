/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:07:02 by rvrignon          #+#    #+#             */
/*   Updated: 2022/03/30 14:07:04 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/utils.h"

int	check_infos(t_infos	*infos)
{
	if (infos->empty == infos->obstacle || infos->empty == infos->full
		|| infos->full == infos->obstacle)
		return (0);
	else
		return (1);
}

int	check_lines_lenght(char **lines)
{
	int		i;
	int		j;
	int		size;
	t_infos	*infos;

	infos = get_informations(lines[0]);
	if (!check_infos(infos))
		return (0);
	i = 1;
	size = -1;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] && (lines[i][j] == infos->obstacle
			|| lines[i][j] == infos->empty))
			j++;
		if (j != size && size != -1)
			return (0);
		else
			size = j;
		i++;
	}
	return (1);
}

int	check(char **lines)
{
	int	go;

	go = 1;
	if (!lines)
		go = 0;
	else if (!check_lines_lenght(lines))
		go = 0;
	if (go == 0)
		write(1, "map error\n\n", 11);
	return (go);
}

void	make_process(char **lines)
{
	t_infos	*infos;
	int		line_length;
	char	**map;

	infos = get_informations(lines[0]);
	line_length = get_line_length(lines[1]);
	infos->line_length = line_length;
	map = create_tab(lines, infos, line_length);
	map = solve(map, infos);
	print_map(map, infos, line_length);
	free(lines);
	free(map);
}

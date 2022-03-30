/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:09:02 by rvrignon          #+#    #+#             */
/*   Updated: 2022/03/30 14:40:33 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/utils.h"

t_solutions	*solve_process(t_solutions *solution, char **tab, t_infos *infos)
{
	t_point	*point;
	int		l;
	int		i;
	int		j;

	point = (t_point *)malloc(sizeof(t_point));
	i = -1;
	l = 1;
	while (i++ + l <= infos->lines)
	{
		j = -1;
		while (j++ + l <= infos->line_length)
		{
			point->x = j;
			point->y = i;
			while (check_points(tab, point, l, infos)
				&& j + l <= infos->line_length && i + l <= infos->lines)
			{
				add_element(solution, i, j, l);
				solution = solution->next;
				l++;
			}
		}
	}
	return (solution);
}

char	**solve(char **tab, t_infos *infos)
{
	t_solutions	*solution;
	int			i;
	int			j;
	int			l;

	solution = malloc(sizeof(t_solutions));
	solution = create_element(0, 0, 0, 1);
	solution = solve_process(solution, tab, infos);
	i = solution->x;
	j = solution->y;
	l = solution->length;
	while (i < solution->x + l)
	{
		j = solution->y;
		while (j < solution->y + l)
		{
			tab[i][j] = infos->full;
			j++;
		}
		i++;
	}
	return (tab);
}

void	print_map(char **map, t_infos *infos, int line_length)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = line_length;
	y = infos->lines;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			write(1, &map[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

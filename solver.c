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

void	free_solution(t_solutions *solution)
{
	t_solutions	*prev;

	while (solution != 0)
	{
		prev = solution->prev;
		free(solution);
		solution = prev;
	}
}

int	is_ok(int j, int i, int l, t_infos *infos)
{
	if (j + l <= infos->line_length && i + l <= infos->lines)
		return (1);
	return (0);
}

t_solutions	*solve_process(t_solutions *solution, char **tab, t_infos *infos)
{
	t_point	*point;
	int		l;
	int		i;
	int		j;

	point = (t_point *)malloc(sizeof(t_point));
	i = -1;
	l = 0;
	while (i++ + l <= infos->lines)
	{
		j = -1;
		while (j++ + l <= infos->line_length)
		{
			point->x = j;
			point->y = i;
			while (check_points(tab, point, l, infos) && is_ok(j, i, l, infos))
			{
				add_element(solution, i, j, l);
				solution = solution->next;
				l++;
			}
		}
	}
	free(point);
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
	free_solution(solution);
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
			write(1, "", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

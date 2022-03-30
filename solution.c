/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:59:09 by rvrignon          #+#    #+#             */
/*   Updated: 2022/03/30 14:59:11 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/utils.h"

int	check_points(char **tab, t_point *point, int l, t_infos *infos)
{
	int	j;
	int	i;
	int	j_cp;
	int	i_cp;

	j = point->x;
	i = point->y;
	j_cp = j;
	i_cp = i;
	while (i < i_cp + l)
	{
		j = j_cp;
		while (j < j_cp + l && tab[i][j] != '\n')
		{
			if (tab[i][j] == infos->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_solutions	*create_element(t_solutions *tmp, int x, int y, int l)
{
	t_solutions	*solutions;

	solutions = (t_solutions *)malloc(sizeof(t_solutions));
	solutions->x = x;
	solutions->y = y;
	solutions->length = l;
	solutions->next = NULL;
	solutions->prev = tmp;
	return (solutions);
}

void	add_element(t_solutions *solutions, int x, int y, int l)
{
	t_solutions	*tmp;

	while (solutions->next != NULL)
		solutions = solutions->next;
	tmp = solutions;
	solutions->next = create_element(tmp, x, y, l);
}

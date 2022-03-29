#include "lib/utils.h"

int     check_points(char **tab, t_point *point, int l, t_infos *infos)
{
    int j;
    int i;
    int j_cp;
    int i_cp;

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
    solutions->L = l;
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

char    **solve(char **tab, int x, int y, t_infos *infos)
{
    int l;
    int i;
    int j;
    t_solutions *solution;
    t_point *point;

    solution = create_element(0, 0, 0, 1);
    point = (t_point *)malloc(sizeof(t_point));

    l = 1;
    i = 0;
    j = 0;

    while (i + l <= y)
    {
        j = 0;
        while (j + l <= x)
        {
            point->x = j;
            point->y = i;
            while(check_points(tab, point, l, infos) && j + l <= x && i + l <= y)
            {
                add_element(solution, i, j, l);
                solution = solution->next;
                l++;
            }
            j++;
        }
        i++;
    }

    i = solution->x;
    j = solution->y;
    l = solution->L;

    while (i < solution->x + l)
    {
        j = solution->y;
        while(j < solution->y + l)
        {
            tab[i][j] = infos->full;
            j++;
        }
        i++;
    }

    return(tab);
}

void    print_map(char **map, t_infos *infos, int line_length)
{
        int i;
        int j;
        int x;
        int y;

        x = line_length;
        y = infos->lines;
        i = 0;
        while (i < y)
        {
            j = 0;
            while (j< x)
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
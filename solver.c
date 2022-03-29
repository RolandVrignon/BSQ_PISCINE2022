#include "lib/utils.h"

int     check_points(char **tab, int i, int j, int l)
{
    int j_cp;
    int i_cp;

    j_cp = j;
    i_cp = i;
    while (i < i_cp + l)
    {
        j = j_cp;
        while (j < j_cp + l && tab[i][j] != '\n')
        {
            // printf("Tab[%d][%d] = %c\n", i, j, tab[i][j]);
            if (tab[i][j] == 'o')
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

char    **solve(char **tab, int x, int y)
{
    int l;
    int i;
    int j;
    t_solutions *solution;

    solution = create_element(0, 0, 0, 1);

    l = 1;
    i = 0;
    j = 0;

    while (i + l <= y)
    {
        j = 0;
        while (j + l <= x)
        {
            while(check_points(tab, i, j, l) && j + l < x && i + l < y)
            {
                // printf("LA SOLUTION au point [%d][%d] de longueur %d\n", i, j, l);
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
            tab[i][j] = 'X';
            j++;
        }
        i++;
    }

    // printf("Adresse Solution : %p || X : %d || Y : %d || L : %d\n", solution, solution->x, solution->y, solution->L);

    return(tab);
}
#include "utils.h"
#include <math.h>
/* int i;
int j;

int L; */

//map_surface_max[i-1][j-1] = L * L;

int     check_points(char **map, int i, int j, int L)
{
    int max_i;
    int max_j;

    max_i = i + L;
    max_j = j + L;
    while (i <= max_i)
    {
        while (j <= max_j)
        {
            if (map[i][j] == 'o')
                return (0);
            else
                j++;
        }
        i++;
    }
    return (1);
}


/* 
i = 0;
j = 0;
while (i < ft_atoi(argv[1]))
{
    while (j < ft_atoi(argv[2]))
    {
        while (j + L < ft_atoi(argv[2]) && i + L < ft_atoi(argv[1]))
        {
            if (map[i + L][j + L] == '.' && check_points(map, i, j, L))
            {
                solutions->y = i;
                solutions->x = j;
                solutions->L = L;
                L++;
            }
            else
            {
                solution = solution->next;
                //condition pour break du while l++;
                L = 0;
            }
        }
        j++;
    }
    i++;
} */

//iter on list until we put all biggest lengths and their adresses
/* int L_max;

L_max = 0;
while (solution->next != NULL)
{
    if (solutions->L >= L_max)
    {
        L_max = solutions->L;
        adress = solutions->curr;
    }
    solutions = solutions->next;
} */

//
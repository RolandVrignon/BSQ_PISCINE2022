#include "utils.h"
#include <math.h>
int i;
int j;

int L;

tab_surface_max[i-1][j-1] = L * L;

typedef struct solutions
{
    int     x;
    int     y;
    int     L;
    struct solutions *prev;
    struct solutions *next;
} t_solutions;

int     check_points(char **tab, int i, int j, int L)
{
    while ()
    {
        while ()
        {
            
        }
    }
}

i = 0;
j = 0;
while (i <= ft_atoi(argv[1]))
{
    while (j <= ft_atoi(argv[2]))
    {
        while (l <= ft_atoi(argv[2]))
        {
            if (tab[i + l][j + l] == '.' && check_points(tab, i, j, l))
            {
                solutions->y = i;
                solutions->x = j;
                solutions->L = l;
                l++;
            }
            else
            {
                solution->next;
                //condition pour break du while l++;
                l = 0;
            }
        }
        j++;
    }
    i++;
}
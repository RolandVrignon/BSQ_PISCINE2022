#include "utils.h"
#include <math.h>
int i;
int j;

int L;

map_surface_max[i-1][j-1] = L * L;

typedef struct solutions
{
    int     x;
    int     y;
    int     L;
    struct solutions *prev;
    struct solutions *next;
} t_solutions;

int     check_points(char **map, int i, int j, int L)
{
    int max_i;
    int max_j;

    max_i = i + L;
    max_j = j + L;
    while (i < max_i)
    {
        while (j < max_j)
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

i = 0;
j = 0;
while (i <= ft_atoi(argv[1]))
{
    while (j <= ft_atoi(argv[2]))
    {
        while (l <= ft_atoi(argv[2]) && l <= ft_atoi(argv[1]))
        {
            if (map[i + l][j + l] == '.' && check_points(map, i, j, l))
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
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int main(int argc, char **argv)
{
    char **map;
    int x = ft_atoi(argv[1]);
    int y = ft_atoi(argv[2]);
    int i;
    int j;
    map = malloc(sizeof(char *) * y + 1);

    if (argc == 4)
    {
        int rand_num = 4;
        int density = ft_atoi(argv[3]);
        for (i = 0; i < y; i++) {
            map[i] = malloc(sizeof(char) * x + 1);
            for (j = 0; j < x; j ++) {
                rand_num = linear_congruenial_generator(rand_num, j);
                if (rand_num < density) 
                    map[i][j] = 'o';
                else 
                    map[i][j] = '.';
            }
        }
    }

    map = solve(map, x, y);

    j = 0;
	i = -1;
	while (i++ < y)
	{
		j = -1;
		while (j++ < x)
		{
			write(1, &map[i][j], 1);
            write(1, " ", 1);
		}
		write(1, "\n", 1);
    }

    

    return (0);
}
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int main(int argc, char **argv)
{
    char **tab;
    int x = ft_atoi(argv[1]);
    int y = ft_atoi(argv[2]);
    int i;
    int j;
    tab = malloc(sizeof(char *) * y + 1);

    if (argc == 4)
    {
        int rand_num = 3;
        int density = ft_atoi(argv[3]);
        for (i = 0; i < y; i++) {
            tab[i] = malloc(sizeof(char) * x + 1);
            for (j = 0; j < x; j ++) {
                rand_num = linear_congruenial_generator(rand_num, j);
                if (rand_num < density) 
                {
                    write(1, "o", 1);
                    tab[i][j] = 'o';
                }
                else 
                {
                    write(1, ".", 1);
                    tab[i][j] = '.';
                }
            }
           write(1, "\n", 1);
        }
    }

    write(1, "\n", 1);
    write(1, "\n", 1);
    write(1, "\n", 1);
    write(1, "\n", 1);

    j = 0;
	i = -1;
	while (i++ < y)
	{
		j = -1;
		while (j++ < x)
		{
			write(1, &tab[i][j], 1);
		}
		write(1, "\n", 1);
	}

    return (0);
}
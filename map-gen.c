#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int map_gen(int argc, char **argv)
{
    if (argc == 4)
    {
        int rand_num = 3;
        int x = ft_atoi(argv[1]);
        int y = ft_atoi(argv[2]);
        int density = ft_atoi(argv[3]);
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j ++) {
                rand_num = linear_congruenial_generator(rand_num, j);
                if (rand_num < density) 
                {
                    write(1, "o", 1);
                }
                else 
                {
                    write(1, ".", 1);
                }
            }
           write(1, "\n", 1);
        }
    }
}
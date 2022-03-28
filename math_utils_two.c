#include "utils.h"

int     linear_congruenial_generator(int x_gen, int c)
{
    int     a;
    int     m;
    
    a = 2;
    m = 9;
    return((((a * x_gen + c) % m)));
}

/* int     main(int ac, char **av)
{
    (void)ac;
    (void)av;
    int x_gen = 3;
    int c = 0;

    while (c < 15)
    {
        x_gen = linear_congruenial_generator(x_gen, c);
        printf("\n%d\n", x_gen);
        c++;
    }
} */
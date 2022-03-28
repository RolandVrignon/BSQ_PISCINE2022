#include "utils.h"

int     linear_congruenial_generator(int x_gen, int c)
{
    int     a;
    int     m;
    
    a = 2;
    m = 9;
    return((((a * x_gen + c) % m)));
}
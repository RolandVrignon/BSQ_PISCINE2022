#include <stdlib.h>
#include <stdio.h>

int     ft_strlen(int *str)
{   
    int     i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}

int     ft_strlen2(int **str)
{   
    int     i;

    i = 0;
    while(str[i])
    {
        i++;
    }
    return(i);
}

int     ft_tablen(int **tab)
{
    return (sizeof(tab[0])/sizeof(tab[0][0]));
}
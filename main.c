

#include <stdlib.h>
#include <stdio.h>
#include "lib/utils.h"
#include <time.h>

int check_lines_lenght(char **lines)
{
    int i;
    int j;
    int size;

    i = 1;
    size = -1;
    while (lines[i])
    {
        j = 0;
        while (lines[i][j])
        {
            j++;
        }
        if (j != size && size != -1)
            return (0);
        else
            size = j;
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    t_infos *infos;
    char **lines;
    int i;
    int x;
    int y;
    int line_length;
    char **map;

    if (ac >= 2)
    {
        i = 1;
        while (av[i])
        {
            lines = open_file(av[i]);
            if (!lines || !check_lines_lenght(lines))
            {
                write(1, "map error\n\n", 11);
                i++;
            }
            else
            {
                infos = get_informations(lines[0]);
                line_length = get_line_length(lines[1]);
                map = create_tab(lines, infos, line_length);
                x = line_length;
                y = infos->lines;
                map = solve(map, x, y, infos);
                print_map(map, infos, line_length);
                free(lines);
                free(map);
                i++;
            }
        }
    }

    return (0);
}
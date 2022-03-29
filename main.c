#include <stdlib.h>
#include <stdio.h>
#include "lib/utils.h"
#include <time.h>

int     main(int ac, char **av)
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
        while(av[i])
        {
            lines = open_file(av[i]);
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
    return (0);
}
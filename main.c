#include <stdlib.h>
#include <stdio.h>
#include "lib/utils.h"
#include <time.h>

int     main(int ac, char **av)
{
    (void)ac;
    t_infos *infos;
    char **lines;
    int i;
    int j;
    int x;
    int y;
    int z;
    int line_length;
    char **map;

    if (ac >= 2)
    {
        z = 1;
        while(av[z])
        {
            lines = open_file(av[z]);
            infos = get_informations(lines[0]);
            line_length = get_line_length(lines[1]);
            map = create_tab(lines, infos, line_length);
            x = line_length;
            y = infos->lines;
            map = solve(map, x, y, infos);
            i = 0;
            while (i < y)
            {
                j = 0;
                while (j< x)
                {
                    write(1, &map[i][j], 1);
                    write(1, " ", 1);
                    j++;
                }
                write(1, "\n", 1);
                i++;
            }
            write(1, "\n", 1);
            free(lines);
            free(map);
            z++;
        }
    }
    return (0);
}
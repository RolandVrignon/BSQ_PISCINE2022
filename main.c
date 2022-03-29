#include <stdlib.h>
#include <stdio.h>
#include "lib/utils.h"
#include <time.h>

t_infos *get_informations(char *str)
{
    t_infos *infos;
    int i;
    char *lines;

    while (str[i] != '\0')
        i++;
    lines = ft_split_key(str);
    infos = (t_infos *)malloc(sizeof(t_infos));
    infos->lines = ft_atoi(lines);
    infos->obstacle = str[i - 2];
    infos->full = str[i - 1];
    return (infos);
}

int    file_size(char *file)
{
    int fd;
    char i;
    int n;

    i = 0;
    n = 0;
    fd = open(file, O_RDONLY);
    while (read(fd, &i, 1) != 0 && i != EOF)
        n++;
    close(fd);
    return (n);
}

char    **open_file(char *str)
{
    char    **lines;
    void    *read_buffer;
    int   fileLength;
    int     fd;

    fileLength = file_size(str);
    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (0);
    if (fileLength < 0)
        return (0);
    read_buffer = malloc(sizeof(char) * fileLength);
    close(fd);
    fd = open(str, O_RDONLY);
    read(fd, read_buffer, fileLength);
    lines = ft_split(read_buffer, "\n");
    return (lines);
}

char    **create_tab(char **lines, t_infos *infos, int line_length)
{
    char **map;
    int i;
    int j;
    int a;
    int b;

    map = malloc(sizeof(char *) * infos->lines);
    i = 1;
    a = 0;
    while (i < infos->lines + 1)
    {
        j = 0;
        b = 0;
        map[a] = malloc(sizeof(char) * line_length + 1);
        while (j < line_length)
        {
            map[a][b] = lines[i][j];
            j++;
            b++;
        }
        a++;
        i++;
    }
    return (map);
}

int     get_line_length(char *lines)
{
    int i;

    i = 0;
    while (lines[i] != '\0')
        i++;

    // printf("length : %d", i);
    return (i);
}

int     main(int ac, char **av)
{
    (void)ac;
    t_infos *infos;
    char **lines;
    int i;
    int j;
    int x;
    int y;
    int line_length;
    char **map;

    if (ac == 2)
    {
        lines = open_file(av[1]);
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
    }
    return (0);
}
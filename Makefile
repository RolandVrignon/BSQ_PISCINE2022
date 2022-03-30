bsq: main.c ./lib/utils.h solver.c init.c check.c solution.c
	gcc -g -Wall -Werror -Wextra ./lib/*.c check.c init.c solver.c solution.c main.c -o bsq

fclean:
	rm -rf bsq


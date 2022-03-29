bsq: main.c ./lib/utils.h solver.c init.c
	gcc -Wall -Werror -Wextra ./lib/*.c main.c solver.c init.c -o bsq

fclean:
	rm bsq


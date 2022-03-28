bsq: main.c ./lib/utils.h solver.c
	gcc -Wall -Werror -Wextra ./lib/*.c main.c solver.c -o bsq

fclean:
	rm *.o bsq


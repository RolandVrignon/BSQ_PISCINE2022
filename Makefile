bsq: map-gen.o utils.o utils.h
	gcc -Wall -Werror -Wextra *.o -o bsq

map-gen.o: map-gen.c utils.h
	gcc -Wall -Werror -Wextra -c map-gen.c

utils.o: utils.c one.c two.c three.c four.c five.c utils.h math_utils_two.c
	gcc -Wall -Werror -Wextra -c utils.c one.c two.c three.c four.c five.c math_utils_two.c

fclean:
	rm *.o bsq


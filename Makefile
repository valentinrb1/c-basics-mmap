FLAGS = -Wall -Werror -pedantic -g

bin/memMap : obj/Lab6.o
	mkdir -p bin
	gcc $(FLAGS) obj/Lab6.o -o bin/memMap

obj/Lab6.o : inc/Lab6.h src/Lab6.c
	mkdir -p obj
	gcc $(FLAGS) -c src/Lab6.c -o obj/Lab6.o

.PHONY: clean

clean:
	rm -f -r bin
	rm -f -r obj
all:
	gcc *.c -Wall


run:
	./a.out


tudo:
	gcc *.c -Wall
	./a.out


val:
		gcc *.c -Wall -g
		valgrind --leak-check=full --track-origins=yes ./a.out

gdb:
	gcc *.c -Wall -g
	gdb ./a.out

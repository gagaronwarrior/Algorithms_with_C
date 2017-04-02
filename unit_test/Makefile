all:
	gcc -c -Wall -g -I../includes main.c
	gcc -static -o main main.o ../lib/lib_gagaron.a -lm

valgrind:
	valgrind ./main   
clean:
	rm -f main.o main

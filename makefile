all: sieve.o main.o
	gcc -o a.out sieve.o main.o -lm

sieve.o: sieve.h sieve.c
	gcc -c sieve.c -lm

main.o: sieve.h main.c
	gcc -c main.c

run:
	time ./a.out $(args)

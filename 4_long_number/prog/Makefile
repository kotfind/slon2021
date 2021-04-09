CC=g++
CFLAGS=-fsanitize=address,undefined -march=native -Wall -Wextra -Wpedantic -std=c++2a -g3 -O0
LDFLAGS=-fsanitize=address,undefined -std=c++2a -g3 -O0

all: main.out
	
main.out: main.o
	$(CC) $(LDFLAGS) main.o -o main.out

main.o : main.cpp
	$(CC) -c $(CFLAGS) main.cpp -o main.o

debug: main.out
	gdb main.out

run: main.out
	./main.out

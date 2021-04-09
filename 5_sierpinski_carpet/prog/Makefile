CFLAGS=-std=c++20 -fsanitize=address,undefined -march=native -Wall -Wextra -Wpedantic -O0 -g3 `libpng-config --cflags`
LDFLAGS=-std=c++20 -fsanitize=address,undefined `libpng-config --ldflags`

ifeq (run,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval .PHONY:$(RUN_ARGS))
  $(eval $(RUN_ARGS):;@:)
endif

all: main.out

main.out: main.o
	g++ main.o $(LDFLAGS) -o main.out 

main.o: main.cpp vec.hpp
	g++ -c main.cpp -o main.o $(CFLAGS)

.PHONY: run
run: main.out
	./main.out $(RUN_ARGS)
	@# feh --force-aliasing -Z output.png

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.out

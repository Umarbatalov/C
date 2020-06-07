C=gcc
STANDARD=-std=c18
DEBUG=-g3
BIT=-m64

run: build start

test: build-test start-test

debug: build-debug start-debug

memcheck: build-debug start-memcheck

callgrind: build-debug start-callgrind

gprof: build-gprof start-gprof

build:
	$(C) $(STANDARD) $(BIT) -Wall main.c -o main

build-debug:
	$(C) $(STANDARD) $(DEBUG) $(BIT) -Wall main.c -o main-debug

build-test:
	$(C) $(STANDARD) $(BIT) -Wall main-test.c -o main-test

build-gprof:
	$(C) $(STANDARD) -Wall -pg --static -g3 -o main-gprof main.c

start:
	./main

start-test:
	./main-test

start-debug:
	gdb ./main-debug

start-memcheck:
	valgrind -q --tool=memcheck ./main-debug

start-callgrind:
	time valgrind --tool=callgrind ./main-debug

start-gprof:
	./main-gprof && gprof ./main-gprof

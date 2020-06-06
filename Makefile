C=gcc
STANDART=-std=c18
DEBUG=-g3

run: build start

test: build-test start-test

debug: build-debug start-debug

build:
	$(C) $(STANDART) -o main main.c

build-debug:
	$(C) $(STANDART) $(DEBUG) -o main-debug main.c

build-test:
	$(C) $(STANDART) -o main-test main-test.c

start:
	./main

start-test:
	./main-test

start-debug:
	gdb ./main-debug

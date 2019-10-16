all: clean build

clean:
	rm bin/*
	rmdir bin

build:
	mkdir bin
	gcc -o bin/bfuck src/bfuck.c

all: add-nbo

add-nbo: add-nbo.o
	g++ -g -O2 -o add-nbo add-nbo.o

add-nbo.o: add-nbo.c
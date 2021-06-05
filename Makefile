# -*- MakeFile -*-

#all: game clean

game: snake.o funcs.o
	gcc snake.c funcs.c -o game

snake.o: snake.c head.h
	gcc -c snake.c

funcs.o: funcs.c
	gcc -c funcs.c

clean:
	rm -f *.o

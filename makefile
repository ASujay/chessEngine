aCEngine: main.o pawns.o knights.o king.o define.o
	gcc -oFast -o aCEngine main.o pawns.o knights.o king.o define.o

debug: main.o pawns.o knights.o king.o define.o
	gcc -o debug main.o pawns.o knights.o king.o define.o

main.o: main.c define.h 
	gcc -c -o main.o main.c 
pawns.o: pawns.c pawns.h define.h
	gcc -c -o pawns.o pawns.c
knights.o: knights.c knights.h define.h
	gcc -c -o knights.o knights.c

king.o: king.c king.h define.h
	gcc -c -o king.o king.c
define.o: define.c define.h
	gcc -c -o define.o define.c
clean:
	del *.o

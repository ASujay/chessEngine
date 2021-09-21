aCEngine: main.o
	gcc -oFast -o aCEngine main.o

debug: main.o
	gcc -o debug main.o

main.o: main.c
	gcc -c -o main.o main.c

clean:
	del *.o
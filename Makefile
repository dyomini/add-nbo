all: sum-nbo

sum-nbo: main.o
	gcc -o sum-nbo main.o

main.o: main.c
	gcc -c -o main.o main.c

clean:
	rm -f main main.o

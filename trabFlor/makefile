run: final
	./final < in

final: main.c Matriz.o 
	gcc -o final main.c Matriz.o  -lm

Matriz.o: Matriz.c Matriz.h
	gcc -o Matriz.o Matriz.c -c -lm
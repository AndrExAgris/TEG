run: final
	./final < IrisDataset.csv

final: main.c matriz.o 
	gcc -o final main.c matriz.o  -lm

matriz.o: matriz.c matriz.h
	gcc -o matriz.o matriz.c -c -lm
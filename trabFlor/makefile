run: grafo.py
	python3 grafo.py  

grafo.py: final
	./final

final: main.c bibflores.o 
	gcc -o final main.c bibflores.o  -lm

bibflores.o: bibflores.c bibflores.h
	gcc -o bibflores.o bibflores.c -c -lm
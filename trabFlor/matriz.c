#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void inicializa_matriz( Matriz *p, int l, int c ){
	p->lin = l;
	p->col = c;
	p->dados = malloc( sizeof( float* ) * l );
	int i, j;
	for( i = 0 ; i < l ; i++ ){
		p->dados[i] = malloc( sizeof( float ) * c );
		for( j = 0 ; j < c ; j++ )
			p->dados[i][j] = 0,0;
	}
}

void mostra_matriz( Matriz m ){
	int i, j;
	printf("Dados da matriz (%dx%d):\n", m.lin, m.col);
	for( i = 0 ; i < m.lin ; i++ ){
		for( j = 0 ; j < m.col ; j++ ){
			printf("%4f ", m.dados[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void libera_matriz( Matriz *p ){
	int i;
	for( i = 0 ; i < p->lin ; i++ )
		free( p->dados[i] );
	free( p->dados );
}





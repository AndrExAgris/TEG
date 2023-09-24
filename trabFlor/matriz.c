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

int set_valor( Matriz *p, int i, int j, float v ){
	if( i >= p->lin || j >= p->col )
		return ERRO_COORD_INVALIDA;
	
	p->dados[i][j] = v;
	return 1; // Sucesso;
}

int get_valor( Matriz m, int i, int j, float *p ){
	if( i >= m.lin || j >= m.col )
		return ERRO_COORD_INVALIDA;
	
	*p = m.dados[i][j];
	return 1; // Sucesso;	
}

int carrega_arquivo( char *nome, Matriz *p ){
	FILE *f = fopen( nome, "rt" );
	if( f == NULL )
		return 0;
	
	int l, c, i, j;
	fscanf( f, "%d%d", &l, &c);
	inicializa_matriz( p, l, c );
	for( i = 0 ; i < l ; i++ )
		for( j = 0 ; j < c ; j++ )
			fscanf( f , "%f", &p->dados[i][j] );
	
	fclose( f );
	return 1;
}

int salva_arquivo( char *nome, Matriz m ){
	FILE *f = fopen( nome, "wt" );
	if( f == NULL )
		return 0;

	int i, j;
	fprintf( f, "%d %d\n", m.lin, m.col);
	for( i = 0 ; i < m.lin ; i++ ){
		for( j = 0 ; j < m.col ; j++ ){
			fprintf( f, "%4f", m.dados[i][j]);
		}
		fprintf( f, "\n");
	}

	fclose( f );
	return 1;	
}



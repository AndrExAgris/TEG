#define ERRO_COORD_INVALIDA -2
#define MATRIZES_INCOMPATIVEIS -3

typedef struct{
	float **dados;
	int lin, col;
} Matriz;

void inicializa_matriz( Matriz *p, int l, int c );
void mostra_matriz( Matriz m );
void libera_matriz( Matriz *p );



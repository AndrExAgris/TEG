#define ERRO_COORD_INVALIDA -2
#define MATRIZES_INCOMPATIVEIS -3

typedef struct{
	int **dados;
	int lin, col;
} Matriz;

void inicializa_matriz( Matriz *p, int l, int c );
void mostra_matriz( Matriz m );
void libera_matriz( Matriz *p );
int set_valor( Matriz *p, int i, int j, int v );
int get_valor( Matriz m, int i, int j, int *p );
int carrega_arquivo( char *nome, Matriz *p );
int salva_arquivo( char *nome, Matriz m );

#define NUM_OCORRENCIAS 150
#define NUM_ATRIBUTOS 4

// Definição da estrutura de um vértice
typedef struct {
    double sepal_length;
    double sepal_width;
    double petal_length;
    double petal_width;
} Vertice;

// Definição da estrutura de uma lista de adjacencias
typedef struct elemento{
    struct elemento *pointer;
    int verticea;
    int verticeb;
} Lista_adjacencias;

double distancia_euclidiana(Vertice v1, Vertice v2);

Lista_adjacencias * cria_lista(Lista_adjacencias *list, int va, int vb);
Lista_adjacencias * adicionar_lista(Lista_adjacencias *list, int a, int b);
void imprimir_lista();

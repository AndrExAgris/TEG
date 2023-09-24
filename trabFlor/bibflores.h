#define NUM_OCORRENCIAS 150
#define NUM_ATRIBUTOS 4


// Definição da estrutura de um vértice
typedef struct {
    double sepal_length;
    double sepal_width;
    double petal_length;
    double petal_width;
} Vertice;

double distancia_euclidiana(Vertice v1, Vertice v2);

#include "cidade.h"

typedef struct rota Rota;

void criaLista();
Rota* criaRota(char*, char*, float);
void inserirLista(Rota*);
void adicionaCidade(Rota*, Cidade*);
void mostrarRota(Rota*);
Rota* melhorRota(char*, float);
void listar();

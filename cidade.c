#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cidade.h"
#include "rota.h"

struct cidade{
    char nome[50];
    char desc[100];
    Cidade *prox;
    Cidade *ant;
};

Cidade *criaCidade(char* nome, char *descricao){
    Cidade *city;
    city = (Cidade*)malloc(sizeof(Cidade));
    strcpy(city->nome, nome);
    strcpy(city->desc, descricao);
    city->ant = NULL;
    city->prox = NULL;
    return city;
}

void mostrarCidade(Cidade* cidadeInicial){
    Cidade* c;
    c = cidadeInicial;
    char nav;
    if(c != NULL){
        printf("Iniciamos a viagem em %s: %s\n", c->nome, c->desc);
    }
    while(c != NULL){
        printf("\nDigite A ou D para navegar para a próxima ou para a cidade anterior: \n");
        scanf(" %c", &nav);
        if(nav == 'a')
            c = c->ant;
        else if(nav == 'd')
            c = c->prox;
        if(c!=NULL)
            printf("Estamos em %s: %s\n", c->nome, c->desc);
    }
    printf("----FIM DA ROTA----");
}

void adicionar(Cidade* inicial, Cidade* cidade){
    Cidade* c;
    c = inicial;
    if(inicial == NULL){

    }

    while(c->prox != NULL){
        c = c->prox;
    }
    c->prox = cidade;
    cidade->ant = c;
}






#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "rota.h"
#include "cidade.h"
#include <string.h>

struct rota{
    char nome[50];
    char destino[50];
    float hora_chegada; // Farei a parte inteira ser a hora e a parte decimal ser os minutos.
    Rota *prox;
    Cidade *inicioRota;
};

Rota* inicio = NULL;
Rota* cauda = NULL;

void criaLista(){
    inicio = NULL;
    cauda = NULL;
}

Rota* criaRota(char* nome, char* destino, float chegada){
    Rota *r;
    r = (Rota*)malloc(sizeof(Rota));
    strcpy(r->nome, nome);
    strcpy(r->destino, destino);
    r->hora_chegada = chegada;
    r->prox = NULL;
    r->inicioRota = NULL;
    return r;

}
void inserirLista(Rota* rota){
    if(inicio == NULL)
        inicio = cauda = rota;
    else{
        cauda->prox = rota;
        cauda = rota;
    }
}
void adicionaCidade(Rota *rota, Cidade *cidade){
    if(rota->inicioRota == NULL)
        rota->inicioRota = cidade;
    else
        adicionar(rota->inicioRota, cidade);
}
void mostrarRota(Rota* rota){
    mostrarCidade(rota->inicioRota);
}

void tratarHora(float horario){
    float hora, minuto;
    hora = floor(horario);
    minuto = horario - hora;
    minuto = minuto*60;
    printf("%.0f:%.0f\n", hora, minuto);
}
void listar(){
    Rota* rota;
    if(inicio == NULL){
        printf("-----Não Há Rotas-----");
        return;
    }
    rota = inicio;
    while(rota != NULL){
        printf("%s - ", rota->nome);
        printf("%s - ", rota->destino);
        tratarHora(rota->hora_chegada);
        rota = rota->prox;
    }
    printf("-----FIM-----");
}

Rota* melhorRota(char* destino, float hora){
    float diff = 0;
    Rota* melhor = NULL;
    Rota* rota = inicio;

    while(rota != NULL){
        if(strcmp(rota->destino, destino) == 0){
            if(melhor == NULL){
                melhor = rota;
                diff = fabs(rota->hora_chegada - hora);
            }
            else if(fabs(rota->hora_chegada - hora) < diff){
                melhor = rota;
                diff = fabs(rota->hora_chegada - hora);
            }
        }
        rota = rota->prox;
    }

    printf("Melhor rota: %s\n", melhor->nome);
    return melhor;
}



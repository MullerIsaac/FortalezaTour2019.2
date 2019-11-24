#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rota.h"
#include "cidade.h"


void escolherRota(char* destino, float hora){
    Rota* rota;
    rota = melhorRota(destino, hora);
    mostrarRota(rota);
}
float horaParaDec(float hora, float minuto){
    float horaFormatada;
    minuto = minuto*100/6000;
    horaFormatada = hora + minuto;
    return horaFormatada;
}
void getInfo(){
    char destino[50];
    float horas, minutos, fhora;

    printf("Informe o seu destino: \n");
    scanf("%s", destino);
    printf("Informe o horário de chegada desejado:  (HH:mm)\n");
    scanf("%f:%f", &horas, &minutos);

    printf("\n");
    fhora = horaParaDec(horas, minutos);

    escolherRota(destino, fhora);


}
void menu(){
    int op;

    printf("O que você deseja? \n\n");
    printf("1. Listar as rotas disponíveis.\n");
    printf("2. Escolher a melhor rota para meu destino.\n");
    printf("3. Sair.\n");
    scanf("%d", &op);

    switch(op){
        case 1:
            listar();
            printf("Voltado pro menu inicial...");
            menu();
            break;
        case 2:
            getInfo();
            break;
        case 3:
            exit(0);
            break;
    }

}


int main()
{
    criaLista();
    Rota* r1 = criaRota("Guanabara", "camocim", 15.5);
    inserirLista(r1);
    Rota* r2 = criaRota("CE Tour", "camocim", 15.40);
    inserirLista(r2);
    Cidade *c1 = criaCidade("pentecoste", "lugar bonito");
    Cidade *c2 = criaCidade("Sobral", "arquitetuta bonita");
    adicionaCidade(r2, c1);
    adicionaCidade(r2, c2);
    menu();
}

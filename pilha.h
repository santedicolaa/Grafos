#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int numero[60];
    int Topo;
} Pilha;

void FazPilhaVazia(Pilha *pilha){
    pilha->Topo = -1;
}

int PilhaVazia(Pilha *pilha){
    return (pilha->Topo == -1);
}

int Empilha(int x, Pilha *pilha){
    if (pilha->Topo == (60-1))
        return 0;
    else{
        pilha->Topo = pilha->Topo + 1;
        pilha->numero[pilha->Topo] = x;
        return 1;
    }
}

int Desempilha(Pilha *pilha, int *x){
    if (PilhaVazia(pilha))
        return 0;
    else{
        *x = pilha->numero[pilha->Topo];
        pilha->Topo = pilha->Topo - 1;
        return 1;
    }
}

void ImprimePilha(Pilha *pilha){
    int x;
    Pilha pilhaAux;
    FazPilhaVazia(&pilhaAux);

    while (!PilhaVazia(pilha)){
        Desempilha(pilha, &x);
        printf("%d ", x);
        Empilha(x, &pilhaAux);
    }
    printf("\n");

    while (!PilhaVazia(&pilhaAux)){
        Desempilha(&pilhaAux, &x);
        Empilha(x, pilha);
    }
}

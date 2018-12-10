typedef struct {
    int numero[50];
    int inicio, fim, quantidade;
} Fila;

Fila *FazFilaVazia(){
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila->fim = fila->inicio = -1;
    fila->quantidade = 0;
    return fila;
}

int FilaVazia(Fila *fila){
    return fila->quantidade == 0;
}

int topo(Fila *fila){
    return fila->numero[fila->inicio];
}

void Enfileira(Fila *fila, int valor){
    fila->numero[fila->fim++] = valor;
    fila->quantidade++;
}

int Desenfileira(Fila *fila){
    fila->quantidade--;
    return fila->numero[fila->inicio++];
}

void ImprimeFila(Fila *fila){
    int i;
    for(i = fila->inicio; i < fila->fim; i++)
        printf("%d ", fila->numero[i]);
    printf("\n");
}

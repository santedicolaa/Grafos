#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"

struct grafo {
   int V;
   int A;
   int **adj;
};

typedef struct grafo *Grafo;

int i, j, v, w;

int **fazMatriz(int linha, int coluna, int val){
   int **m = malloc(linha * sizeof (int *));
   for (i = 0; i < linha; ++i)
      m[i] = malloc(coluna * sizeof (int));
   for (i = 0; i < linha; ++i)
      for (j = 0; j < coluna; ++j)
         m[i][j] = val;
   return m;
}

Grafo fazGrafo(int vertices){
   Grafo G = malloc(sizeof *G);
   G->V = vertices;
   G->A = 0;
   G->adj = fazMatriz(vertices, vertices, 0);
   return G;
}

void removeAresta(Grafo G, int v, int w){
   if (G->adj[v][w] != 0) {
      G->adj[v][w] = 0;
      G->adj[w][v] = 0;
      G->A--;
   }
}

void insereAresta(Grafo G, int v, int w){
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->adj[w][v] = 1;
      G->A++;
   }
}

void mostraAdj(Grafo G){
   for (v = 0; v < G->V; ++v) {
      printf("%2d:", v);
      for (w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1)
            printf( " %2d", w);
      printf("\n");
   }
}

int calculaGrau(Grafo G, int vertice){
    int grau=0;
    for(i=0;i<G->V;i++){
        if(G->adj[vertice][i] != 0)
            grau++;
    }
    return grau;
}

void caminhoMinimo(Grafo G, int inicio, int *dist, int *pa){
    int v;
    const int maximo = G->V;
    for(v = 0; v < G->V; v++)
    {
        pa[v] = -1;
        dist[v] = maximo;
    }
    pa[inicio] = inicio;
    dist[inicio] = 0;
    Fila *fila = FazFilaVazia();
    Enfileira(fila, inicio);

    while(!FilaVazia(fila))
    {
        int v = Desenfileira(fila);
        for(w = 0; w < G->V; w++)
        {
            if(G->adj[v][w] == 1 && dist[w] == maximo)
            {
                dist[w] = dist[v] +1;
                pa[w] = v;
                Enfileira(fila, w);
            }
        }
    }
}

void sequenciaMinima(Grafo G, int ini, int fim, Pilha *ordem){
    int dist[G->A];
    int pa[G->V];
    caminhoMinimo(G, ini, dist, pa);
    Empilha(fim, ordem);
    while (pa[fim] != fim){
        Empilha(pa[fim], ordem);
        fim = pa[fim];
    }
}

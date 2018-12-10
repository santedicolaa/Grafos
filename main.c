#include <stdio.h>
#include <stdlib.h>
#include "tipoGrafo.h"

int main()
{
    int continuar = 1;
    do{
        Grafo Cidade;
        char estacoes[15][8];
        int vertices, i=0, v, w, num, v1, v2, caso;
        Pilha ordem;

        printf("\n********** Mapa de estacoes **********\n\n");
        printf("Escolha uma opcao:\n\n");
        printf("1. Criar um mapa\n");
        printf("2. Mostrar Estacoes\n");
        printf("3. Mostrar Conexoes\n");
        printf("4. Mostrar menor caminho\n");
        printf("5. Editar Conexoes\n");
        printf("6. Encerrar\n\n");
        scanf("%d", &continuar);
        system("cls");

        switch(continuar)
        {
            case 1:
                printf("\nNumero de estacoes: ");
                scanf("%d", &vertices);
                Cidade = fazGrafo(vertices);
                printf("\n");
                while(i<vertices){
                    printf("Nome da Estacao %d: ", i);
                    scanf("%s", estacoes[i]);
                    printf("\n");
                    i++;
                }
                system("cls");
                int condicao = 12;
                do{
                    printf("Estacoes Criadas:\n");
                    for(i=0; i<vertices; i++){
                        printf("%d. %s", i, estacoes[i]);
                        printf("\n");
                    }
                    printf("\n");
                    printf("- Insira o numero correspondente a estacao desejada\n");
                    printf("- Insira '0 0' para encerrar\n");
                    printf("\nConexoes entre estacoes (est a est b): ");
                    scanf("%d %d", &v1, &v2);
                    condicao = v1 + v2;
                    if (condicao == 0){
                        system("cls");
                        break;
                    }
                    insereAresta(Cidade, v1, v2);
                    condicao = v1 + v2;
                    system("cls");
                } while(condicao != 0);
                break;

            case 2:
                printf("Estacoes Criadas:\n");
                for(i=0; i<vertices; i++){
                    printf("%d. %s", i, estacoes[i]);
                    printf("\n");
                }
                break;

            case 3:
                printf("\nConexoes entre Estacoes:\n\n");
                printf("         ");
                for(v = 0; v < Cidade->V; v++) {
                    printf("%9s", estacoes[v]);
                }
                printf("\n");
                for(v = 0; v < Cidade->V; ++v){
                    printf("%9s", estacoes[v]);
                    for(w=0;w<Cidade->V;w++){
                    if(Cidade->adj[v][w] == 0){
                        printf("        -");
                    }
                    else{
                        printf("       %s", "OK");
                        }
                    }
                    printf("\n");
                }
                break;

            case 4:
                FazPilhaVazia(&ordem);
                for(i=0; i<vertices; i++){
                    printf("%d. %s", i, estacoes[i]);
                    printf("\n");
                }
                printf("\nEncontre o menor trajeto entre duas estacoes (est a est b): ");
                scanf("%d %d", &v1, &v2);
                printf("\n");
                sequenciaMinima(Cidade, v1, v2, &ordem);
                while(PilhaVazia(&ordem) != 1){
                    Desempilha(&ordem, &num);
                    if(num == v2)
                        printf(" %s", estacoes[num]);
                    else{
                    printf(" %s ->", estacoes[num]);
                }
                }
                printf("\n");

                break;

            case 5:
                    caso = 1;
                    do{
                        printf("\nConexoes entre Estacoes:\n\n");
                        printf("            ");
                        for(v = 0; v < Cidade->V; v++) {
                            printf("%9d", v);
                        }
                        printf("\n");
                        printf("            ");
                        for(v = 0; v < Cidade->V; v++) {
                            printf("%9s", estacoes[v]);
                        }
                        printf("\n");
                        for(v = 0; v < Cidade->V; ++v){
                            printf("%2d %-9s", v, estacoes[v]);
                            for(w=0;w<Cidade->V;w++){
                            if(Cidade->adj[v][w] == 0){
                                printf("        -");
                            }
                            else{
                                printf("       %s", "OK");
                            }
                            }
                            printf("\n");
                        }
                        printf("\n");
                        printf("\n1. Criar conexao");
                        printf("\n2. Remover conexao");
                        printf("\n3. Sair\n\n");
                        scanf("%d", &caso);
                        switch(caso){
                            case 1:
                                printf("- Insira o numero correspondente a estacao desejada\n");
                                printf("- Insira '0 0' para encerrar\n");
                                printf("\nCriar conexao entre estacoes (est a est b): ");
                                scanf("%d %d", &v1, &v2);
                                condicao = v1 + v2;
                                if (condicao == 0){
                                    system("cls");
                                    break;
                                }
                                insereAresta(Cidade, v1, v2);
                                condicao = v1 + v2;
                                system("cls");
                                break;

                            case 2:
                                printf("- Insira o numero correspondente a estacao desejada\n");
                                printf("- Insira '0 0' para encerrar\n");
                                printf("\nRemover conexao entre estacoes (est a est b): ");
                                scanf("%d %d", &v1, &v2);
                                condicao = v1 + v2;
                                if (condicao == 0){
                                    system("cls");
                                    break;
                                }
                                removeAresta(Cidade, v1, v2);
                                condicao = v1 + v2;
                                system("cls");
                                break;

                            case 3:
                                system("cls");
                                break;
                        }
                    }while (caso != 3);
                    break;





            case 6:
                printf("\n\n Bye, bye!\n\n");
                break;

            default:
                printf("*** Digite uma opcao valida! ***\n\n");
        }
    } while(continuar!=6);
    return 0;
}

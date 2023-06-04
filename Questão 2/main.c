#include <stdlib.h>
#include <stdio.h>

#include "FunçaoPilha.h"
#include "FunçaoFila.h"
#include "FunçaoArvore.h"

int main()
{
    int opcao,variavel_pilha,variavel_fila,variavel_arvore;
    int valor;
    
    //----------Alocação da Pilha-----------------
    nopilha *PILHA = (nopilha *) malloc(sizeof(nopilha));
    PILHA-> prox = NULL;
    int tam = 0;
   

    //----------Alocação da Fila------------------
    noFILA *FILA = (noFILA*)malloc(sizeof(noFILA));
    FILA ->prox = NULL; 

    //----------Alocação da Arvore------------------
    ArvB arvore;
    arvore.raiz = NULL;
    No *raiz = NULL;
  
    do{
        
    
    printf("\n");
    printf("1-PILHA\n");
    printf("2-FILA\n");
    printf("3-ARVORE\n");
    printf("0-SAIR\n");
    
    scanf("%d",&opcao);
  
    switch(opcao){
        case 1:
        do{
        
            printf("----------PILHA----------\n ");
            printf("\n1-EMPILHAR\n");
            printf("2-DESEMPILHAr\n");
            printf("3-IMPRIMIR PILHA\n");
            printf("4-IMPRIMIR TOPO\n");
            printf("5- LIMPAR PILHA\n");
            printf("0-SAIR\n");
            scanf("%d",&variavel_pilha);
        
            
            switch(variavel_pilha){
                case 1:
                PUSH(PILHA,tam);
                break;
                
                case 2:
                POP(PILHA,tam);
                break;
                
                case 3:
                IMPRIMEPILHA(PILHA,tam);
                break;
                
                case 4:
                imprimirTopoPilha(PILHA);
                break;

                case 5:
                limparPilha(PILHA,tam);
                break;
                
                case 0:
                break;

                default:
                printf("Digite uma opção valida!");
                break;
            }
        }while(variavel_pilha != 0);
        break;
      
        case 2:

      do{
        
            printf("----------FILA----------\n ");
            printf("\n1-ENQUEUE\n");
            printf("2-DEQUEUE\n");
            printf("3-IMPRIMIR FILA\n");
            printf("4-MAIOR ELEMENTO DA FILA\n");
            printf("5-MENOR ELEMENTO DA FILA\n");
            printf("6-LIMPAR\n");
            printf("0-SAIR\n");
            scanf("%d",&variavel_fila);
        
            
            switch(variavel_fila){
                case 1:
                ENQUEUE(FILA,tam);
                break;
                
                case 2:
                 DEQUEUE(FILA,tam);
                break;
                
                case 3:
                  IMPRIME(FILA,tam);
                break;
                
                case 4:
                  maiorElementoFila(FILA);
                break;

                case 5:
                  menorElementoFila(FILA);
                break;
                
                case 6:
                  limparFila(FILA,tam);
                break;

                case 0:
                break;

                default:
                printf("Digite um numero valido!");
                break;
            }
        }while(variavel_fila != 0);
        break;
      
        case 3:

      do{
        
            printf("\n----------ÁRVORE BINÁRIA----------\n");
            printf("\n1-INSERIR ELEMENTO\n");
            printf("2-IMPRIMIR PARA DIREITA\n");
            printf("3-IMPRIMIR PARA ESQUERDA\n");
            printf("4-MAIOR ELEMENTO\n");
            printf("5-BUSCAR ELEMENTO\n");
            printf("6-REMOVER ELEMENTO\n");
            printf("0-SAIR\n");
            printf("=> ");
            scanf("%d",&variavel_arvore);
        
            
            switch(variavel_arvore){
                case 1:
                 printf("Digite o valor a ser inserido na árvore: \n=>");
                scanf("%d", &valor);
                arvore.raiz = inserir(arvore.raiz, valor);
                break;
                
                case 2:
                printf("Arvore binaria:\n");
                 imprimeArvore(arvore.raiz);
                break;
                
                case 3:
                  printf("Arvore binaria do maior pro menor:\n");
                 imprime(arvore.raiz);
                break;
                case 4:
                  printf("Maior elemento da árvore: %d\n", encontrarMaiorElemento(arvore.raiz));
                break;

                case 5:
                buscar(arvore.raiz);
                break;
                
                case 6:
                printf("Digite o valor a ser removido da árvore: \n=>");
                scanf("%d", &valor);
                arvore.raiz = remover(arvore.raiz, valor);
                break;

                case 0:
                break;

                default:
                
                break;
            }
        }while(variavel_arvore != 0);
        
        default:
        break;
    }
  }while(opcao != 0);
  return 0;
}

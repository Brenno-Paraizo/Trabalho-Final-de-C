struct NodeFILA{
int conteudo;
struct NodeFILA *prox;

};
typedef struct NodeFILA noFILA;

int EMPTY(noFILA *FILA){
    if(FILA->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

noFILA* ENQUEUE(noFILA *FILA, int tam){
  noFILA *novo = (noFILA *) malloc(sizeof(noFILA));
  novo->prox = NULL;

  printf("Novo item da Fila: ");
  scanf("%d", &novo->conteudo);

  if(EMPTY(FILA)){
    FILA->prox = novo;
    
  }else{
    noFILA *tmp = FILA->prox;
    while(tmp->prox != NULL){
      tmp = tmp->prox;
      
    }
    tmp->prox = novo;
  }
  tam++;
  return novo;
}

void DEQUEUE(noFILA *FILA, int tam){
  if(FILA->prox == NULL){
    printf("Fila esta vazia\n");
    return;
    
  }else{
    noFILA *tmp = FILA->prox;
    FILA->prox = tmp->prox;
    tam--;
    free(tmp);
  }
}

void IMPRIME(noFILA *FILA, int tam){
    if(EMPTY(FILA)){
        printf("FILA vazia! \n\n");
        return;
    }
    noFILA *tmp = FILA-> prox;
    printf("\nFILA: ");
    
    while( tmp != NULL){
        printf(" %3d", tmp-> conteudo);
        tmp = tmp->prox;
        tam++;
    }
    printf("\n Quantidades de Itens na FILA: %d", tam);
    printf("\n");
}

void limparFila(noFILA *FILA, int tam) {
    if (EMPTY(FILA)) {
        printf("FILA já vazia!\n");
        return;
    }

    noFILA *atual = FILA->prox;
    noFILA *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    FILA->prox = NULL;
    tam = 0;

    printf("FILA limpa com sucesso!\n");
}

int maiorElementoFila(noFILA *FILA) {
    if (vazia(FILA)) {
        printf("FILA vazia!\n");
        return 0;
    }

    int maior = FILA->prox->conteudo;
    noFILA *tmp = FILA->prox->prox;

    while (tmp != NULL) {
        if (tmp->conteudo > maior) {
            maior = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
  printf("Maior numero é: %d", maior);

    return maior;
}

int menorElementoFila(noFILA *FILA) {
    if (EMPTY(FILA)) {
        printf("FILA vazia!\n");
        return 0;
    }

    int menor = FILA->prox->conteudo;
    noFILA *tmp = FILA->prox->prox;

    while (tmp != NULL) {
        if (tmp->conteudo < menor) {
            menor = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    printf("Menor numero é: %d ",menor);
    return menor;
}

struct NodePilha{
    int item;
    struct NodePilha *prox;
    
};
typedef struct NodePilha nopilha;

int vazia(nopilha *PILHA){
    if(PILHA->prox == NULL)
    return 1;
    
    else
    return 0;
}

void PUSH(nopilha *PILHA, int tam){
    nopilha *novo =(nopilha *)malloc(sizeof(nopilha));
    novo->prox = NULL;
    
    printf("Novo item: ");
    scanf("%d", &novo->item);
    
    if(vazia(PILHA))
    PILHA->prox = novo;
    
    else{
        nopilha *tmp = PILHA->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    tam++;
}

void POP(nopilha *PILHA, int tam){
    if(PILHA->prox == NULL){
        printf("PILHA ja vazia\n\n");
        return;
    }else{
        nopilha *ultimo = PILHA->prox;
        nopilha *penultimo = PILHA;
        
    
    while(ultimo -> prox != NULL){
        penultimo = ultimo;
        ultimo = ultimo->prox;
    }
    free(ultimo);
    penultimo->prox = NULL;
    tam--;
    
  }
}

void IMPRIMEPILHA(nopilha *PILHA, int tam){
    if(vazia(PILHA)){
        printf("PILHA vazia! \n\n");
        return;
    }
    nopilha *tmp;
    tmp = PILHA->prox;
    printf("\nPILHA: ");
    
    while( tmp != NULL){
        printf(" %3d", tmp->item);
        tmp = tmp->prox;
        tam++;
        
    }
    printf("\n Quantidades de Itens na PILHA: %d", tam);
    printf("\n");
}

void limparPilha(nopilha *PILHA, int tam) {
    if (vazia(PILHA)) {
        printf("PILHA já vazia!\n");
        return;
    }

    nopilha *atual = PILHA->prox;
    nopilha *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    PILHA->prox = NULL;
    tam = 0;

    printf("PILHA limpa com sucesso!\n");
}

void imprimirTopoPilha(nopilha *PILHA){
    if(vazia(PILHA)){
        
        printf("\nA Pilha ja está vazia! \n\n");
        return ;
        
    }else{
        
        nopilha *tmp = PILHA -> prox;
        
        printf("\nNumero no topo da pilha é:");
        while (tmp->prox != NULL){
            tmp = tmp -> prox;
        }   
    printf("%d",tmp -> item);
    printf("\n");
    }
}


typedef struct no{
  int chave;
struct no *esquerda, *direita;

}No;

typedef struct{
  No *raiz;
  int tam;
} ArvB;



No* inserir(No *raiz, int valor){
  if(raiz == NULL){
    No *novo = (No *) malloc(sizeof(No));
    novo->chave = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
    
  }else{
    if(valor < raiz->chave)
      raiz->esquerda = inserir(raiz->esquerda, valor);
    if(valor > raiz->chave)
      raiz->direita = inserir(raiz->direita, valor);
    
    return raiz;
  }
}

void imprimeArvore(No *raiz){
  if(raiz != NULL){
    imprimeArvore(raiz->esquerda);
    printf("%d ", raiz->chave);
    imprimeArvore(raiz->direita);
  }
}

No* remover(No* raiz, int item) {
    if (raiz == NULL) {
        printf("Valor nao encontrado!\n");
        return NULL;
    } else {
        if (raiz->chave == item) {
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                return NULL;
            } else {
                No* aux;
                if (raiz->esquerda != NULL) {
                    aux = raiz->esquerda;
                } else {
                    aux = raiz->direita;
                }
                free(raiz);
                return aux;
            }
        } else {
            if (item < raiz->chave) {
                raiz->esquerda = remover(raiz->esquerda, item);
            } else {
                raiz->direita = remover(raiz->direita, item);
            }
            return raiz;
        }
    }
}


void buscar(No* raiz) {
    int valorDesejado;
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valorDesejado);

    if (raiz == NULL) {
        printf("Valor não encontrado na árvore.\n");
    } else if (valorDesejado == raiz->chave) {
        printf("Valor encontrado na árvore.\n");
    } else if (valorDesejado < raiz->chave) {
        buscar(raiz->esquerda);
    } else {
        buscar(raiz->direita);
    }
}

void imprime(No *raiz){
  if(raiz != NULL){
    imprime(raiz->direita);
    printf("%d ", raiz->chave);
    imprime(raiz->esquerda);
  }
}

int encontrarMaiorElemento(No* raiz) {
    if (raiz == NULL) {
        printf("Árvore vazia!\n");
        return 0;
    }

    if (raiz->direita == NULL) {
        return raiz->chave;
    }

    return encontrarMaiorElemento(raiz->direita);
}

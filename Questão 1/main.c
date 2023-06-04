#include <stdio.h>

void bubbleSort(int vetor[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int vetor[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }

        vetor[j + 1] = chave;
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho, i, opcao;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("\nEscolha um algoritmo de ordenacao:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            bubbleSort(vetor, tamanho);
            printf("\nVetor ordenado usando Bubble Sort: ");
            imprimirVetor(vetor, tamanho);
            break;
        case 2:
            insertionSort(vetor, tamanho);
            printf("\nVetor ordenado usando Insertion Sort: ");
            imprimirVetor(vetor, tamanho);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ========================
// DEFINIÇÕES E CONSTANTES
// ========================
#define TAMANHO 1000      // Tamanho do vetor (lista encadeada)
#define LIMITE 9999       // Valor máximo para os elementos
#define CRESCENTE 1       // Ordenação crescente
#define DECRESCENTE 0     // Ordenação decrescente

// ========================
// DEFINIÇÃO DA ESTRUTURA
// ========================
typedef struct vetor {
    int elemento;
    struct vetor *prox;
} Vetor;

// ====================================
// FUNÇÕES DE MANIPULAÇÃO DA LISTA
// ====================================

// Inicializa a lista
Vetor *inicializarVetor() {
    return NULL;
}

// Insere novo elemento no início da lista
Vetor *inserirElemento(Vetor *vetor, int info) {
    Vetor *novo = malloc(sizeof(Vetor));
    novo->elemento = info;
    novo->prox = vetor;
    return novo;
}

// Preenche a lista com valores aleatórios
void preenchedorDeVetor(Vetor **vetor) {
    for (int i = 0; i < TAMANHO; i++) {
        *vetor = inserirElemento(*vetor, rand() % (LIMITE + 1));
    }
}

// Lê e imprime os 20 primeiros e 20 últimos elementos da lista
void leitorDeVetor(Vetor *vetor) {
    Vetor *aux = vetor;
    int i = 0;

    printf("Primeiros 20 elementos: ");
    while (aux != NULL && i < 20) {
        printf("%d ", aux->elemento);
        aux = aux->prox;
        i++;
    }
    printf("\n");

    while (aux != NULL && i < TAMANHO - 20) {
        aux = aux->prox;
        i++;
    }

    printf("Últimos 20 elementos: ");
    while (aux != NULL && i < TAMANHO) {
        printf("%d ", aux->elemento);
        aux = aux->prox;
        i++;
    }
    printf("\n");
}

// Cria uma cópia da lista original
void copiarVetor(Vetor *original, Vetor **copia) {
    Vetor *novo = NULL, *ultimo = NULL;
    while (original != NULL) {
        novo = malloc(sizeof(Vetor));
        novo->elemento = original->elemento;
        novo->prox = NULL;

        if (ultimo != NULL)
            ultimo->prox = novo;
        else
            *copia = novo;

        ultimo = novo;
        original = original->prox;
    }
}

// Libera a memória da lista
void freeVetor(Vetor *vetor) {
    Vetor *temp;
    while (vetor != NULL) {
        temp = vetor;
        vetor = vetor->prox;
        free(temp);
    }
}

// Troca os valores de dois nós
void trocar(Vetor *a, Vetor *b) {
    int temp = a->elemento;
    a->elemento = b->elemento;
    b->elemento = temp;
}

// ========================
// BUBBLE SORT
// ========================
void bubbleSort(Vetor *inicio, int crescente) {
    int trocou;
    Vetor *aux;
    Vetor *fim = NULL;

    do {
        trocou = 0;
        aux = inicio;

        while (aux->prox != fim) {
            if ((crescente && aux->elemento > aux->prox->elemento) ||
                (!crescente && aux->elemento < aux->prox->elemento)) {
                trocar(aux, aux->prox);
                trocou = 1;
            }
            aux = aux->prox;
        }
        fim = aux;
    } while (trocou);
}

// ========================
// QUICK SORT
// ========================

// Particiona a lista em menores e maiores que o pivô
void particionar(Vetor *inicio, Vetor **menores, Vetor **maiores, int pivo, int crescente) {
    Vetor *atual = inicio, *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        if ((crescente && atual->elemento < pivo) || (!crescente && atual->elemento > pivo)) {
            atual->prox = *menores;
            *menores = atual;
        } else {
            atual->prox = *maiores;
            *maiores = atual;
        }
        atual = proximo;
    }
}

// Função principal do QuickSort
void quickSort(Vetor **inicio, int crescente) {
    if (*inicio == NULL || (*inicio)->prox == NULL)
        return;

    Vetor *menores = NULL, *maiores = NULL;
    Vetor *pivo = *inicio;
    Vetor *resto = pivo->prox;
    pivo->prox = NULL;

    particionar(resto, &menores, &maiores, pivo->elemento, crescente);

    quickSort(&menores, crescente);
    quickSort(&maiores, crescente);

    Vetor *fimMenores = menores;
    if (fimMenores != NULL) {
        while (fimMenores->prox != NULL)
            fimMenores = fimMenores->prox;
        fimMenores->prox = pivo;
    } else {
        menores = pivo;
    }

    pivo->prox = maiores;
    *inicio = menores;
}

// ========================
// FUNÇÃO PRINCIPAL
// ========================
int main() {
    srand(time(NULL)); // Semente aleatória

    // Criação e preenchimento da lista original
    Vetor *vetorOriginal = inicializarVetor();
    preenchedorDeVetor(&vetorOriginal);

    // Cópias para ordenações
    Vetor *v1 = inicializarVetor(), *v2 = inicializarVetor();
    Vetor *v3 = inicializarVetor(), *v4 = inicializarVetor();
    copiarVetor(vetorOriginal, &v1);
    copiarVetor(vetorOriginal, &v2);
    copiarVetor(vetorOriginal, &v3);
    copiarVetor(vetorOriginal, &v4);

    // Imprime vetor original
    printf("=== VETOR ORIGINAL ===\n");
    leitorDeVetor(vetorOriginal);
    printf("\n\n");
    freeVetor(vetorOriginal);

    // Bubble Sort Crescente
    bubbleSort(v1, CRESCENTE);
    printf("=== BUBBLE SORT - CRESCENTE ===\n");
    leitorDeVetor(v1);
    printf("\n\n");
    freeVetor(v1);

    // Bubble Sort Decrescente
    bubbleSort(v2, DECRESCENTE);
    printf("=== BUBBLE SORT - DECRESCENTE ===\n");
    leitorDeVetor(v2);
    printf("\n\n");
    freeVetor(v2);

    // Quick Sort Crescente
    quickSort(&v3, CRESCENTE);
    printf("=== QUICK SORT - CRESCENTE ===\n");
    leitorDeVetor(v3);
    printf("\n\n");
    freeVetor(v3);

    // Quick Sort Decrescente
    quickSort(&v4, DECRESCENTE);
    printf("=== QUICK SORT - DECRESCENTE ===\n");
    leitorDeVetor(v4);
    printf("\n\n");
    freeVetor(v4);

    return 0;
}

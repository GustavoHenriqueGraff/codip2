#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "constantes.h"

// Inicializa o ponteiro do vetor (lista encadeada)
Vetor *inicializarVetor() {
    return NULL;
}

// Insere um novo elemento no início da lista
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

// Imprime os 20 primeiros e os 20 últimos elementos
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

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "constantes.h"


No *criarLista() {
    return NULL;
}

No *inserirNoInicio(No *lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

void preencherLista(No **lista) {
    for (int i = 0; i < TAMANHO; i++) {
        *lista = inserirNoInicio(*lista, rand() % (LIMITE + 1));
    }
}

void imprimirLista(No *lista) {
    No *atual = lista;
    int i = 0;

    printf("Primeiros 20: ");
    while (atual != NULL && i < 20) {
        printf("%d ", atual->valor);
        atual = atual->prox;
        i++;
    }
    printf("\n");

    while (atual != NULL && i < TAMANHO - 20) {
        atual = atual->prox;
        i++;
    }

    printf("Últimos 20: ");
    while (atual != NULL && i < TAMANHO) {
        printf("%d ", atual->valor);
        atual = atual->prox;
        i++;
    }
    printf("\n");
}

void copiarLista(No *original, No **copia) {
    No *novo = NULL, *ultimo = NULL;
    while (original != NULL) {
        novo = malloc(sizeof(No));
        novo->valor = original->valor;
        novo->prox = NULL;

        if (ultimo != NULL)
            ultimo->prox = novo;
        else
            *copia = novo;

        ultimo = novo;
        original = original->prox;
    }
}

void liberarLista(No *lista) {
    No *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

void trocarValores(No *a, No *b) {
    int temp = a->valor;
    a->valor = b->valor;
    b->valor = temp;
}


#ifndef VETOR_H
#define VETOR_H

#include "constantes.h"

typedef struct vetor {
    int elemento;
    struct vetor *prox;
} Vetor;

// Inicialização e manipulação da lista
Vetor *inicializarVetor();
Vetor *inserirElemento(Vetor *vetor, int info);
void preenchedorDeVetor(Vetor **vetor);
void leitorDeVetor(Vetor *vetor);
void copiarVetor(Vetor *original, Vetor **copia);
void freeVetor(Vetor *vetor);
void trocar(Vetor *a, Vetor *b);

#endif

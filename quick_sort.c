#include <stdlib.h>
#include "lista.h"         // Estrutura No e funções auxiliares
#include "ordenacao.h"     // Declarações de quickSort()


void particionar(No *inicio, No **menores, No **maiores, int pivo, int crescente) {
    No *atual = inicio;
    while (atual != NULL) {
        No *proximo = atual->prox;

        if ((crescente && atual->valor < pivo) ||
            (!crescente && atual->valor > pivo)) {
            atual->prox = *menores;
            *menores = atual;
        } else {
            atual->prox = *maiores;
            *maiores = atual;
        }

        atual = proximo;
    }
}


void quickSort(No **inicio, int crescente) {
    if (*inicio == NULL || (*inicio)->prox == NULL)
        return;

    No *menores = NULL, *maiores = NULL;
    No *pivo = *inicio;
    No *resto = pivo->prox;
    pivo->prox = NULL;

    particionar(resto, &menores, &maiores, pivo->valor, crescente);

    quickSort(&menores, crescente);
    quickSort(&maiores, crescente);

    No *fimMenores = menores;
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

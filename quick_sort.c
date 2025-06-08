#include <stdlib.h>
#include "vetor.h"
#include "quick_sort.h"

// Função auxiliar para particionar a lista
Vetor *particionar(Vetor *inicio, Vetor **menores, Vetor **maiores, int pivo, int crescente) {
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

    return *menores;
}

// Função principal do QuickSort
void quickSort(Vetor **inicio, int crescente) {
    if (*inicio == NULL || (*inicio)->prox == NULL)
        return;

    Vetor *menores = NULL, *maiores = NULL, *pivo = *inicio;
    Vetor *resto = pivo->prox;
    pivo->prox = NULL;

    particionar(resto, &menores, &maiores, pivo->elemento, crescente);

    quickSort(&menores, crescente);
    quickSort(&maiores, crescente);

    // Junta menores + pivo + maiores
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

#include <stdlib.h>
#include "vetor.h"
#include "bubble_sort.h"
#include "constantes.h"

// Implementação do Bubble Sort para listas encadeadas
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

#include <stdlib.h>
#include "lista.h"         
#include "bubble_sort.h"
#include "constantes.h"

void bubbleSort(Item *inicio, int crescente) {
    int houveTroca;
    Item *atual;
    Item *limite = NULL;

    do {
        houveTroca = 0;
        atual = inicio;

        while (atual->prox != limite) {
            int precisaTrocar = (crescente && atual->dado > atual->prox->dado) ||
                                (!crescente && atual->dado < atual->prox->dado);

            if (precisaTrocar) {
                trocarDados(atual, atual->prox);
                houveTroca = 1;
            }

            atual = atual->prox;
        }

        limite = atual; // Após cada passada, o maior (ou menor) está no final
    } while (houveTroca);
}

     

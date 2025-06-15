#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"          
#include "ordenacao.h"     

int main() {
    srand(time(NULL)); 

   
    No *original = criarLista();
    preencherLista(&original);

    // Cópias para teste de ordenações
    No *bubCresc = criarLista();
    No *bubDecr  = criarLista();
    No *qkCresc  = criarLista();
    No *qkDecr   = criarLista();

    copiarLista(original, &bubCresc);
    copiarLista(original, &bubDecr);
    copiarLista(original, &qkCresc);
    copiarLista(original, &qkDecr);

    printf("=== LISTA ORIGINAL ===\n");
    imprimirLista(original);
    printf("\n\n");
    liberarLista(original);

   
    bubbleSort(bubCresc, CRESCENTE);
    printf("=== BUBBLE SORT - CRESCENTE ===\n");
    imprimirLista(bubCresc);
    printf("\n\n");
    liberarLista(bubCresc);

   
    bubbleSort(bubDecr, DECRESCENTE);
    printf("=== BUBBLE SORT - DECRESCENTE ===\n");
    imprimirLista(bubDecr);
    printf("\n\n");
    liberarLista(bubDecr);

    
    quickSort(&qkCresc, CRESCENTE);
    printf("=== QUICK SORT - CRESCENTE ===\n");
    imprimirLista(qkCresc);
    printf("\n\n");
    liberarLista(qkCresc);

  
    quickSort(&qkDecr, DECRESCENTE);
    printf("=== QUICK SORT - DECRESCENTE ===\n");
    imprimirLista(qkDecr);
    printf("\n\n");
    liberarLista(qkDecr);

    return 0;
}

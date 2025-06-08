#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constantes.h"
#include "vetor.h"
#include "bubble_sort.h"
#include "quick_sort.h"

int main() {
    srand(time(NULL)); // Inicializa semente aleatória

    // Criação e preenchimento do vetor original
    Vetor *vetorOriginal = inicializarVetor();
    preenchedorDeVetor(&vetorOriginal);

    // Cópias para diferentes algoritmos
    Vetor *v1 = inicializarVetor(), *v2 = inicializarVetor();
    Vetor *v3 = inicializarVetor(), *v4 = inicializarVetor();

    copiarVetor(vetorOriginal, &v1);
    copiarVetor(vetorOriginal, &v2);
    copiarVetor(vetorOriginal, &v3);
    copiarVetor(vetorOriginal, &v4);

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

    // QuickSort Crescente
    quickSort(&v3, CRESCENTE);
    printf("=== QUICK SORT - CRESCENTE ===\n");
    leitorDeVetor(v3);
    printf("\n\n");
    freeVetor(v3);

    // QuickSort Decrescente
    quickSort(&v4, DECRESCENTE);
    printf("=== QUICK SORT - DECRESCENTE ===\n");
    leitorDeVetor(v4);
    printf("\n\n");
    freeVetor(v4);

    return 0;
}

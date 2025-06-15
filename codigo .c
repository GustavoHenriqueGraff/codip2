#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 1000
#define LIMITE 9999
#define CRESCENTE 1
#define DECRESCENTE 0

typedef struct No {
    int valor;
    struct No *prox;
} No;

No *criarLista() {
    return NULL;
}

No *inserirNoInicio(No *lista, int valor) {
    No *novo = malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

void preencherLista(No **lista) {
    for (int i = 0; i < TAMANHO; i++) {
        *lista = inserirNoInicio(*lista, rand() % (LIMITE + 1));
    }
}

// Imprime 20 primeiros e 20 últimos elementos da lista
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
        if (!novo) {
            fprintf(stderr, "Erro de alocação de memória\n");
            exit(EXIT_FAILURE);
        }
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

void bubbleSort(No *inicio, int crescente) {
    int trocou;
    No *aux;
    No *fim = NULL;

    if (inicio == NULL) return;

    do {
        trocou = 0;
        aux = inicio;

        while (aux->prox != fim) {
            if ((crescente && aux->valor > aux->prox->valor) ||
                (!crescente && aux->valor < aux->prox->valor)) {
                trocarValores(aux, aux->prox);
                trocou = 1;
            }
            aux = aux->prox;
        }
        fim = aux;
    } while (trocou);
}

void particionar(No *inicio, No **menores, No **maiores, int pivo, int crescente) {
    No *atual = inicio, *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        if ((crescente && atual->valor < pivo) || (!crescente && atual->valor > pivo)) {
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

    No *menores = NULL, *maiores = NULL, *pivo = *inicio;
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


int main() {
    srand(time(NULL));

    No *listaOriginal = criarLista();
    preencherLista(&listaOriginal);

    No *listaBubbleCresc = criarLista();
    No *listaBubbleDecresc = criarLista();
    No *listaQuickCresc = criarLista();
    No *listaQuickDecresc = criarLista();

    copiarLista(listaOriginal, &listaBubbleCresc);
    copiarLista(listaOriginal, &listaBubbleDecresc);
    copiarLista(listaOriginal, &listaQuickCresc);
    copiarLista(listaOriginal, &listaQuickDecresc);

    printf("=== LISTA ORIGINAL ===\n");
    imprimirLista(listaOriginal);
    printf("\n");

    bubbleSort(listaBubbleCresc, CRESCENTE);
    printf("=== BUBBLE SORT CRESCENTE ===\n");
    imprimirLista(listaBubbleCresc);
    printf("\n");

    bubbleSort(listaBubbleDecresc, DECRESCENTE);
    printf("=== BUBBLE SORT DECRESCENTE ===\n");
    imprimirLista(listaBubbleDecresc);
    printf("\n");

    quickSort(&listaQuickCresc, CRESCENTE);
    printf("=== QUICK SORT CRESCENTE ===\n");
    imprimirLista(listaQuickCresc);
    printf("\n");

    quickSort(&listaQuickDecresc, DECRESCENTE);
    printf("=== QUICK SORT DECRESCENTE ===\n");
    imprimirLista(listaQuickDecresc);
    printf("\n");

  
    liberarLista(listaOriginal);
    liberarLista(listaBubbleCresc);
    liberarLista(listaBubbleDecresc);
    liberarLista(listaQuickCresc);
    liberarLista(listaQuickDecresc);

    return 0;
}

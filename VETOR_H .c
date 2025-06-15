#ifndef LISTA_H
#define LISTA_H

#include "constantes.h"

// Estrutura de um item da lista
typedef struct Item {
    int dado;
    struct Item *prox;
} Item;

// Funções principais
Item *criarLista();                        // Cria lista vazia
Item *adicionar(Item *lista, int dado);   // Adiciona novo item
void preencher(Item **lista);             // Preenche lista com dados
void mostrar(Item *lista);                // Mostra todos os dados
void copiar(Item *origem, Item **copia);  // Copia lista para nova
void liberar(Item *lista);                // Libera memória da lista
void trocarDados(Item *a, Item *b);       // Troca dados entre dois itens

#endif

#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

void insere_inicio(No **head, int val) {
    No *novo = malloc(sizeof(No));
    novo->dado = val;
    novo->prox = *head;
    *head = novo;
}

void imprime_lista(const char *mensagem, No *no) {
    No *lista = no;
    int i = 0;
    printf("%s\n[", mensagem);
    while (lista) {
        if (i > 0) printf(" -> ");
        printf("%d", lista->dado);
        lista = lista->prox;
        i++;
    }
    printf("]\n");
}

void libera_lista(No **head) {
    No *aux = *head;
    No *prox;
    while (aux) {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
    *head = NULL;
}
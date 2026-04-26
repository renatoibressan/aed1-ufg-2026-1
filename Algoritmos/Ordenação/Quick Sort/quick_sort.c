#include <stdio.h>
#include "quick_sort.h"

void imprime_vetor(const char *mensagem, int v[], int n) {
    printf("%s\n[", mensagem);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", v[i]);
    }
    printf("]\n");
}

void quick_sort(int v[], int inicio, int fim) {
    if (inicio >= fim) return;
    int pivo = v[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (v[j] < pivo) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int aux = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = aux;
    int pos_pivo = i + 1;
    quick_sort(v, inicio, pos_pivo - 1);
    quick_sort(v, pos_pivo + 1, fim);
}
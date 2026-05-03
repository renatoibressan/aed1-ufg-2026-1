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

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int mediana_de_tres(int v[], int inicio, int fim) {
    int meio = (inicio + fim) / 2;
    if (v[inicio] > v[meio]) troca(&v[inicio], &v[meio]);
    if (v[inicio] > v[fim]) troca(&v[inicio], &v[fim]);
    if (v[meio] > v[fim]) troca(&v[meio], &v[fim]);
    troca(&v[meio], &v[fim]);
    return v[fim];
}

int particao_lomuto(int v[], int inicio, int fim) {
    int pivo = mediana_de_tres(v, inicio, fim);
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (v[j] < pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[fim]);
    return (i + 1);
}

void quick_sort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particao_lomuto(v, inicio, fim);
        quick_sort(v, inicio, p - 1);
        quick_sort(v, p + 1, fim);
    }
}
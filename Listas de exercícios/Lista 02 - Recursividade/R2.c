#include <stdio.h>
#define N 8
// Permutações
int aux[N], perm[N];

void vetorOriginal(int v[], int n);

void inicializarVetor(int n);

void permutacoes(int v[], int n, int idx);

int main() {
    int n, v[N];
    scanf("%d", &n);
    vetorOriginal(v, n);
    permutacoes(v, n, 0);
    return 0;
}

void vetorOriginal(int v[], int n) {
    int k = 1;
    for (int i = 0; i < n; i++) {
        v[i] = k;
        k++;
    }
}

void inicializarVetor(int n) {
    for (int i = 0; i < n; i++) {
        aux[i] = 0;
    }
}

void permutacoes(int v[], int n, int idx) {
    if (idx == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", perm[i]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        if (aux[i] == 0) {
            aux[i] = 1;
            perm[idx] = v[i];
            permutacoes(v, n, idx + 1);
            aux[i] = 0;
        }
    }
}
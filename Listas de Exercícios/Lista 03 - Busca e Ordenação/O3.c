#include <stdio.h>
#include <stdlib.h>
#define N 200000
// Ordenação 3 (contagem de inversões com Merge Sort)
unsigned long int mesclaVetor(int v[], int aux[], int esquerda, int meio, int direita);

unsigned long int ordenaVetor(int v[], int aux[], int esquerda, int direita);

int main() {
    int n, *v = NULL, *aux = NULL;
    scanf("%d", &n);
    v = (int *)malloc(n*sizeof(int));
    aux = (int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    unsigned long int soma = ordenaVetor(v, aux, 0, n - 1);
    printf("%lu\n", soma);
    free(v);
    free(aux);
    return 0;
}

unsigned long int mesclaVetor(int v[], int aux[], int esquerda, int meio, int direita) {
    int k, j, count = 0;
    for (k = esquerda; k <= direita; k++) {
        aux[k] = v[k];
    }
    j = meio + 1;
    for (k = esquerda; k <= direita; k++) {
        if (esquerda > meio) v[k] = aux[j++];
        else if (j > direita) v[k] = aux[esquerda++];
        else if (aux[esquerda] <= aux[j]) v[k] = aux[esquerda++];
        else {
            count += (meio - esquerda + 1);
            v[k] = aux[j++];
        }
    }
    return count;
}

unsigned long int ordenaVetor(int v[], int aux[], int esquerda, int direita) {
    unsigned long int soma = 0;
    if (direita > esquerda) {
        int meio = (esquerda + direita) / 2;
        soma += ordenaVetor(v, aux, esquerda, meio);
        soma += ordenaVetor(v, aux, meio + 1, direita);
        soma += mesclaVetor(v, aux, esquerda, meio, direita);
    }
    return soma;
}
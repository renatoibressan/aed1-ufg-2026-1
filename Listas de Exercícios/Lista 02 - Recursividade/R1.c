#include <stdio.h>
#define N 10
// N-rainhas
void totalCombinacoes(int n, int coluna, int rainhas[], int *count);

int main() {
    int n, count = 0, rainhas[N];
    scanf("%d", &n);
    totalCombinacoes(n, 0, rainhas, &count);
    printf("%d\n", count);
    return 0;
}

void totalCombinacoes(int n, int coluna, int rainhas[], int *count) {
    if (coluna == n) {
        (*count)++;
        return;
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int k = 0; k < coluna; k++) {
            if ((rainhas[k] == i) || (rainhas[k] - k == i - coluna) || (rainhas[k] + k == i + coluna)) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            rainhas[coluna] = i;
            totalCombinacoes(n, coluna + 1, rainhas, count);
        }
    }
}
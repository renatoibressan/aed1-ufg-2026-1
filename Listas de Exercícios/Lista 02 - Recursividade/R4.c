#include <stdio.h>
// Partições
int particoes(int n);

int main() {
    int n, p;
    scanf("%d", &n);
    p = particoes(n);
    printf("%d\n", p);
    return 0;
}

int particoes(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    int resultado = 0;
    for (int k = 1;; k++) {
        int g1 = (k * (3 * k - 1)) / 2;
        int g2 = (k * (3 * k + 1)) / 2;
        if ((n - g1) < 0 && (n - g2) < 0) break;
        if (k % 2 != 0) {
            if (n - g1 >= 0) resultado += particoes(n - g1);
            if (n - g2 >= 0) resultado += particoes(n - g2);
        }
        else if (k % 2 == 0) {
            if (n - g1 >= 0) resultado -= particoes(n - g1);
            if (n - g2 >= 0) resultado -= particoes(n - g2);
        }
    }
    return resultado;
}
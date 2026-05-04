#include <stdio.h>
#include "mdc.h"

int main() {
    int a, b, resultado;
    printf("Insira dois numeros naturais: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Leitura nao suportada!\n(Programa abortado)\n");
        return 1;
    }
    if (a < 0 || b < 0) {
        printf("Valor(es) ");
        if (a < 0) printf("%d ", a);
        if (b < 0) printf("%d ", b);
        printf("invalido(s)!\n(Programa abortado)\n");
        return 1;
    }
    resultado = mdc(a, b);
    printf("mdc(%d, %d) = %d\n", a, b, resultado);
    return 0;
}
#include <stdio.h>
#define N 8
// Joãozinho e o Labirinto
int visit[N][N];

void saida(int n, int m[N][N], int l, int c, int *flag);

int main() {
    int n, m[N][N], flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    saida(n, m, 0, 0, &flag);
    printf("%d\n", flag);
    return 0;
}

void saida(int n, int m[N][N], int l, int c, int *flag) {
    if (m[l][c] == 0) return;
    if (visit[l][c] == 1) return;
    if (l == n - 1 && c == n - 1) {
        *flag = 1;
        return;
    }
    visit[l][c] = 1;
    if (l + 1 < n) {
        saida(n, m, l + 1, c, flag);
        if (*flag == 1) return;
    }
    if (c + 1 < n) {
        saida(n, m, l, c + 1, flag);
        if (*flag == 1) return;
    }
    if (l - 1 > -1) {
        saida(n, m, l - 1, c, flag);
        if (*flag == 1) return;
    }
    if (c - 1 > -1) {
        saida(n, m, l, c - 1, flag);
        if (*flag == 1) return;
    }
    visit[l][c] = 0;
    return;
}
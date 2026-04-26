static const int MAX = 100;

struct no {
    int dado;
    struct no *prox;
};

typedef struct no No;

void insere_inicio(No **head, int val);
void imprime_lista(const char *mensagem, No *no);
void libera_lista(No **head);
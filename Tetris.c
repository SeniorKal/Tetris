#include <stdio.h>

#define TAMANHO_FILA 5

typedef struct {
    char nome;
    int id;
} Peca;

typedef struct {
    Peca itens[TAMANHO_FILA];
    int inicio;
    int fim;
    int total;
} Fila;

void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->total = 0;
}

int filaCheia(const Fila *fila) {
    return fila->total == TAMANHO_FILA;
}

int filaVazia(const Fila *fila) {
    return fila->total == 0;
}

Peca gerarPeca(void) {
    static int proximoId = 0;
    char tipos[] = {'T', 'O', 'I', 'L'};
    Peca peca;

    peca.nome = tipos[proximoId % 4];
    peca.id = proximoId;
    proximoId++;

    return peca;
}

int inserirPeca(Fila *fila, Peca peca) {
    if (filaCheia(fila)) {
        printf("Fila cheia! Nao foi possivel inserir uma nova peca.\n");
        return 0;
    }

    fila->itens[fila->fim] = peca;
    fila->fim = (fila->fim + 1) % TAMANHO_FILA;
    fila->total++;
    return 1;
}

int jogarPeca(Fila *fila, Peca *pecaRemovida) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Nao ha peca para jogar.\n");
        return 0;
    }

    *pecaRemovida = fila->itens[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAMANHO_FILA;
    fila->total--;
    return 1;
}

void exibirFila(const Fila *fila) {
    printf("\nFila de pecas\n");

    if (filaVazia(fila)) {
        printf("(vazia)\n\n");
        return;
    }

    for (int i = 0, indice = fila->inicio; i < fila->total; i++) {
        printf("[%c %d] ", fila->itens[indice].nome, fila->itens[indice].id);
        indice = (indice + 1) % TAMANHO_FILA;
    }

    printf("\n\n");
}

void exibirMenu(void) {
    printf("Opcoes de acao:\n");
    printf("1 - Jogar peca (dequeue)\n");
    printf("2 - Inserir nova peca (enqueue)\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

int main(void) {
    Fila fila;
    int opcao;

    inicializarFila(&fila);

    for (int i = 0; i < TAMANHO_FILA; i++) {
        inserirPeca(&fila, gerarPeca());
    }

    printf("Tetris Stack - Fila de pecas futuras\n");
    exibirFila(&fila);

    do {
        exibirMenu();

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Encerrando o programa.\n");
            return 1;
        }

        switch (opcao) {
            case 1: {
                Peca pecaJogada;

                if (jogarPeca(&fila, &pecaJogada)) {
                    printf("Peca jogada: [%c %d]\n", pecaJogada.nome, pecaJogada.id);
                }

                exibirFila(&fila);
                break;
            }
            case 2:
                if (inserirPeca(&fila, gerarPeca())) {
                    printf("Nova peca inserida no final da fila.\n");
                }

                exibirFila(&fila);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Escolha 1, 2 ou 0.\n");
                exibirFila(&fila);
                break;
        }
    } while (opcao != 0);

    return 0;
}

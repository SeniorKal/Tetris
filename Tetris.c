#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_FILA 5
#define TAMANHO_PILHA 3

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

typedef struct {
    Peca itens[TAMANHO_PILHA];
    int topo;
} Pilha;

void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->total = 0;
}

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int filaCheia(const Fila *fila) {
    return fila->total == TAMANHO_FILA;
}

int filaVazia(const Fila *fila) {
    return fila->total == 0;
}

int pilhaCheia(const Pilha *pilha) {
    return pilha->topo == TAMANHO_PILHA - 1;
}

int pilhaVazia(const Pilha *pilha) {
    return pilha->topo == -1;
}

Peca gerarPeca(void) {
    static int proximoId = 0;
    char tipos[] = {'T', 'O', 'I', 'L'};
    Peca peca;

    peca.nome = tipos[rand() % 4];
    peca.id = proximoId;
    proximoId++;

    return peca;
}

int enfileirar(Fila *fila, Peca peca) {
    if (filaCheia(fila)) {
        return 0;
    }

    fila->itens[fila->fim] = peca;
    fila->fim = (fila->fim + 1) % TAMANHO_FILA;
    fila->total++;

    return 1;
}

int desenfileirar(Fila *fila, Peca *pecaRemovida) {
    if (filaVazia(fila)) {
        return 0;
    }

    *pecaRemovida = fila->itens[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAMANHO_FILA;
    fila->total--;

    return 1;
}

int empilhar(Pilha *pilha, Peca peca) {
    if (pilhaCheia(pilha)) {
        return 0;
    }

    pilha->topo++;
    pilha->itens[pilha->topo] = peca;

    return 1;
}

int desempilhar(Pilha *pilha, Peca *pecaRemovida) {
    if (pilhaVazia(pilha)) {
        return 0;
    }

    *pecaRemovida = pilha->itens[pilha->topo];
    pilha->topo--;

    return 1;
}

void completarFila(Fila *fila) {
    while (!filaCheia(fila)) {
        enfileirar(fila, gerarPeca());
    }
}

void exibirPeca(Peca peca) {
    printf("[%c %d]", peca.nome, peca.id);
}

void exibirFila(const Fila *fila) {
    int i;
    int indice;

    printf("Fila de pecas: ");

    if (filaVazia(fila)) {
        printf("(vazia)");
    } else {
        indice = fila->inicio;

        for (i = 0; i < fila->total; i++) {
            exibirPeca(fila->itens[indice]);
            printf(" ");
            indice = (indice + 1) % TAMANHO_FILA;
        }
    }

    printf("\n");
}

void exibirPilha(const Pilha *pilha) {
    int i;

    printf("Pilha de reserva (Topo -> Base): ");

    if (pilhaVazia(pilha)) {
        printf("(vazia)");
    } else {
        for (i = pilha->topo; i >= 0; i--) {
            exibirPeca(pilha->itens[i]);
            printf(" ");
        }
    }

    printf("\n");
}

void exibirEstadoAtual(const Fila *fila, const Pilha *pilha) {
    printf("\nEstado atual:\n");
    exibirFila(fila);
    exibirPilha(pilha);
    printf("\n");
}

void exibirMenu(void) {
    printf("Opcoes de Acao:\n");
    printf("1 - Jogar peca\n");
    printf("2 - Reservar peca\n");
    printf("3 - Usar peca reservada\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

void jogarPeca(Fila *fila) {
    Peca pecaJogada;

    if (desenfileirar(fila, &pecaJogada)) {
        printf("\nPeca jogada: ");
        exibirPeca(pecaJogada);
        printf("\n");
        completarFila(fila);
    } else {
        printf("\nFila vazia. Nao ha peca para jogar.\n");
    }
}

void reservarPeca(Fila *fila, Pilha *pilha) {
    Peca pecaReservada;

    if (pilhaCheia(pilha)) {
        printf("\nPilha de reserva cheia. Nao foi possivel reservar outra peca.\n");
        return;
    }

    if (desenfileirar(fila, &pecaReservada)) {
        empilhar(pilha, pecaReservada);
        printf("\nPeca reservada: ");
        exibirPeca(pecaReservada);
        printf("\n");
        completarFila(fila);
    } else {
        printf("\nFila vazia. Nao ha peca para reservar.\n");
    }
}

void usarPecaReservada(Pilha *pilha) {
    Peca pecaUsada;

    if (desempilhar(pilha, &pecaUsada)) {
        printf("\nPeca reservada usada: ");
        exibirPeca(pecaUsada);
        printf("\n");
    } else {
        printf("\nPilha de reserva vazia. Nao ha peca reservada para usar.\n");
    }
}

void limparEntrada(void) {
    int caractere;

    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

int main(void) {
    Fila fila;
    Pilha pilha;
    int opcao;

    srand((unsigned int) time(NULL));

    inicializarFila(&fila);
    inicializarPilha(&pilha);
    completarFila(&fila);

    printf("Tetris Stack - Fila circular e pilha de reserva\n");
    exibirEstadoAtual(&fila, &pilha);

    do {
        exibirMenu();

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida. Digite apenas numeros.\n");
            limparEntrada();
            exibirEstadoAtual(&fila, &pilha);
            continue;
        }

        switch (opcao) {
            case 1:
                jogarPeca(&fila);
                exibirEstadoAtual(&fila, &pilha);
                break;
            case 2:
                reservarPeca(&fila, &pilha);
                exibirEstadoAtual(&fila, &pilha);
                break;
            case 3:
                usarPecaReservada(&pilha);
                exibirEstadoAtual(&fila, &pilha);
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida. Escolha 1, 2, 3 ou 0.\n");
                exibirEstadoAtual(&fila, &pilha);
                break;
        }
    } while (opcao != 0);

    return 0;
}

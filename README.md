# Tetris Stack

Projeto em linguagem C que simula a fila de pecas futuras de um jogo inspirado em Tetris.

O objetivo principal e praticar o uso de estruturas de dados, especialmente fila circular, structs, arrays, funcoes e interacao com o usuario pelo terminal.

## O que o programa faz

O programa controla uma fila de pecas futuras. Cada peca possui:

- `nome`: caractere que representa o tipo da peca, como `T`, `O`, `I` ou `L`.
- `id`: numero inteiro unico que identifica a ordem de criacao da peca.

Ao iniciar, o programa cria automaticamente uma fila com 5 pecas. Depois disso, o usuario pode escolher uma das opcoes do menu:

- `1`: jogar uma peca, removendo a peca da frente da fila.
- `2`: inserir uma nova peca no final da fila, caso exista espaco.
- `0`: sair do programa.

Depois de cada acao, o estado atual da fila e exibido no terminal.

## Conceitos utilizados

- Fila circular
- Structs
- Arrays
- Funcoes
- Entrada e saida de dados
- Condicionais
- Controle de fluxo com menu

## Niveis do projeto

Este projeto sera desenvolvido em tres niveis:

### Novato

Nivel atual do projeto.

Neste nivel, o programa trabalha apenas com a fila principal de pecas futuras. O usuario pode jogar uma peca, inserir uma nova peca e visualizar a fila apos cada acao.

### Aventureiro

Nivel que ainda sera implementado.

Neste nivel, o projeto deve evoluir com novas funcionalidades e uma logica mais completa para manipular as pecas.

### Mestre

Nivel que ainda sera implementado.

Neste nivel, o projeto deve representar uma versao mais avancada, usando uma estrutura mais completa e regras mais elaboradas para aproximar melhor a simulacao de um jogo.

## Como compilar

Use o GCC no terminal:

```bash
gcc Tetris.c -o Tetris.exe
```

## Como executar

No Windows, execute:

```bash
./Tetris.exe
```

Em seguida, escolha as opcoes do menu pelo terminal.

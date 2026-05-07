# Tetris Stack

Projeto em linguagem C que simula o gerenciamento de pecas no estilo Tetris Stack, usando uma fila circular para as pecas futuras e uma pilha para pecas reservadas.

## Funcionalidades

Cada peca possui:

- `nome`: caractere que representa o tipo da peca, como `T`, `O`, `I` ou `L`.
- `id`: numero inteiro unico que representa a ordem de criacao da peca.

Ao iniciar, o programa:

- cria uma fila circular com 5 pecas;
- cria uma pilha de reserva com capacidade maxima de 3 pecas;
- exibe o estado atual da fila e da pilha.

O menu permite:

- `1` - Jogar peca: remove a peca da frente da fila.
- `2` - Reservar peca: move a peca da frente da fila para o topo da pilha, se houver espaco.
- `3` - Usar peca reservada: remove a peca do topo da pilha.
- `0` - Sair.

Depois de jogar ou reservar uma peca, uma nova peca e gerada automaticamente e adicionada ao final da fila, mantendo a fila sempre cheia.

## Conceitos Utilizados

- Fila circular
- Pilha linear
- Structs
- Arrays
- Funcoes
- Menus interativos
- Validacao simples de entrada

## Como Compilar

Use o GCC no terminal:

```bash
gcc Tetris.c -o Tetris.exe
```

## Como Executar

No Windows:

```bash
./Tetris.exe
```

Depois disso, escolha as opcoes do menu pelo terminal.

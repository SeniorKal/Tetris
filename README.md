# Tetris Stack

Projeto desenvolvido em linguagem C que simula a fila de peças futuras de um jogo inspirado em Tetris.

O principal objetivo do projeto é praticar conceitos de estruturas de dados, especialmente filas circulares, além de trabalhar com structs, arrays, funções e interação com o usuário pelo terminal.

---

# Funcionalidades

O programa controla uma fila de peças futuras. Cada peça possui:

- `nome`: caractere que representa o tipo da peça, como `T`, `O`, `I` ou `L`.
- `id`: número inteiro único utilizado para identificar a ordem de criação da peça.

Ao iniciar, o programa gera automaticamente uma fila com 5 peças. Depois disso, o usuário pode utilizar o menu para realizar as seguintes ações:

- `1` → Jogar uma peça (remove a peça da frente da fila)
- `2` → Inserir uma nova peça no final da fila
- `0` → Encerrar o programa

Após cada ação, o estado atual da fila é exibido no terminal.

---

# Conceitos Utilizados

- Filas circulares
- Structs
- Arrays
- Funções
- Entrada e saída de dados
- Condicionais
- Menus interativos
- Controle de fluxo

---

# Estrutura do Projeto

O projeto será dividido em três níveis de evolução:

## Novato

Nível atual do projeto.

Nesta etapa, o programa trabalha apenas com a fila principal de peças futuras. O usuário pode inserir peças, jogar peças e visualizar o estado da fila após cada operação.

---

## Aventureiro

Nível que será implementado futuramente.

Nesta etapa, o projeto ganhará novas funcionalidades e uma lógica mais avançada para manipulação das peças.

---

## Mestre

Nível mais avançado do projeto.

Nesta versão, o sistema terá estruturas mais completas e regras mais elaboradas, aproximando a simulação de uma lógica mais próxima de um jogo real.

---

# Como Compilar

Utilize o GCC no terminal:

```bash
gcc Tetris.c -o Tetris.exe
```

---

# Como Executar

No Windows:

```bash
./Tetris.exe
```

Depois disso, basta escolher as opções do menu diretamente pelo terminal.

---

# Objetivo Educacional

Este projeto foi criado com foco em aprendizado e prática de lógica de programação e estruturas de dados em linguagem C.
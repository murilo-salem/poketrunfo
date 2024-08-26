// baralho.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "baralho.h"
#include "fila.h"

void inicializarBaralho(Fila* baralho) {
    // Exemplo de inicialização: criar cartas a partir de um arquivo CSV ou outro método
    Carta c1 = criarCarta(1, "Bulbasaur", 45, 49, 49, 65, 65, false);
    enfileirar(baralho, c1);
    // Adicionar mais cartas como necessário
}

void embaralharBaralho(Fila* baralho) {
    // Implementar lógica de embaralhamento
    // Pode-se copiar as cartas para um array, embaralhar o array e refazer a fila
}

void distribuirCartas(Fila* baralho, Fila* jogador1, Fila* jogador2, int numCartas) {
    for (int i = 0; i < numCartas; i++) {
        enfileirar(jogador1, desenfileirar(baralho));
        enfileirar(jogador2, desenfileirar(baralho));
    }
}

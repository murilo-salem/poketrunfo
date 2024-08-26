// baralho.h
#ifndef BARALHO_H
#define BARALHO_H

#include "fila.h"

void inicializarBaralho(Fila* baralho);
void embaralharBaralho(Fila* baralho);
void distribuirCartas(Fila* baralho, Fila* jogador1, Fila* jogador2, int numCartas);

#endif

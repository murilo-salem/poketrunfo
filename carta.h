// carta.h
#ifndef CARTA_H
#define CARTA_H

#include <stdbool.h>

typedef struct {
    int id;
    char nome[50];
    int hp;
    int ataque;
    int defesa;
    int ataque_especial;
    int defesa_especial;
    bool lendario;
} Carta;

Carta criarCarta(int id, char* nome, int hp, int ataque, int defesa, int ataque_especial, int defesa_especial, bool lendario);

#endif

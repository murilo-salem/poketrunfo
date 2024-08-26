// carta.c
#include <stdio.h>
#include <string.h>
#include "carta.h"

Carta criarCarta(int id, char* nome, int hp, int ataque, int defesa, int ataque_especial, int defesa_especial, bool lendario) {
    Carta c;
    c.id = id;
    strcpy(c.nome, nome);
    c.hp = hp;
    c.ataque = ataque;
    c.defesa = defesa;
    c.ataque_especial = ataque_especial;
    c.defesa_especial = defesa_especial;
    c.lendario = lendario;
    return c;
}

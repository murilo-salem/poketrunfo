// fila.h
#ifndef FILA_H
#define FILA_H

#include "carta.h"

typedef struct Node {
    Carta carta;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Fila;

Fila* criarFila();
void enfileirar(Fila* fila, Carta carta);
Carta desenfileirar(Fila* fila);
int filaVazia(Fila* fila);
void liberarFila(Fila* fila);

#endif

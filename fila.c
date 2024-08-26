// fila.c
#include <stdlib.h>
#include "fila.h"

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->front = NULL;
    fila->rear = NULL;
    return fila;
}

void enfileirar(Fila* fila, Carta carta) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->carta = carta;
    novoNode->next = NULL;
    if (fila->rear == NULL) {
        fila->front = novoNode;
        fila->rear = novoNode;
    } else {
        fila->rear->next = novoNode;
        fila->rear = novoNode;
    }
}

Carta desenfileirar(Fila* fila) {
    if (fila->front == NULL) {
        // Caso de erro: fila vazia
        exit(1);
    }
    Node* temp = fila->front;
    Carta carta = temp->carta;
    fila->front = fila->front->next;
    if (fila->front == NULL) {
        fila->rear = NULL;
    }
    free(temp);
    return carta;
}

int filaVazia(Fila* fila) {
    return fila->front == NULL;
}

void liberarFila(Fila* fila) {
    while (!filaVazia(fila)) {
        desenfileirar(fila);
    }
    free(fila);
}

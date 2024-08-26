#ifndef POKEMON_H
#define POKEMON_H

#include <stdbool.h>

// Estrutura para armazenar informações do Pokémon
typedef struct Pokemon {
    int id;
    char name[50];
    char type1[20];
    char type2[20];
    int total;
    int hp;
    int attack;
    int defense;
    int spAtk;
    int spDef;
    int speed;
    int generation;
    bool legendary;
} Pokemon;

// Nó da lista duplamente encadeada
typedef struct Node {
    Pokemon data;
    struct Node* prev;
    struct Node* next;
} Node;

// Funções
Node* createNode(Pokemon data);
void insertEnd(Node** head, Pokemon data);
Node* findPokemon(Node* head, const char* name);
void printPokemon(Pokemon p);

#endif

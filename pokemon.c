#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pokemon.h"

// Cria um novo nó
Node* createNode(Pokemon data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insere um nó no final da lista
void insertEnd(Node** head, Pokemon data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Busca um Pokémon pelo nome, ignorando maiúsculas e minúsculas
Node* findPokemon(Node* head, const char* name) {
    Node* temp = head;
    char nameLower[50];
    char tempNameLower[50];

    strcpy(nameLower, name);
    for (int i = 0; nameLower[i]; i++) {
        nameLower[i] = tolower(nameLower[i]);
    }

    while (temp != NULL) {
        strcpy(tempNameLower, temp->data.name);
        for (int i = 0; tempNameLower[i]; i++) {
            tempNameLower[i] = tolower(tempNameLower[i]);
        }
        if (strcmp(tempNameLower, nameLower) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Imprime as informações de um Pokémon
void printPokemon(Pokemon p) {
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Type 1: %s\n", p.type1);
    printf("Type 2: %s\n", p.type2);
    printf("Total: %d\n", p.total);
    printf("HP: %d\n", p.hp);
    printf("Attack: %d\n", p.attack);
    printf("Defense: %d\n", p.defense);
    printf("Sp. Atk: %d\n", p.spAtk);
    printf("Sp. Def: %d\n", p.spDef);
    printf("Speed: %d\n", p.speed);
    printf("Generation: %d\n", p.generation);
    printf("Legendary: %s\n", p.legendary ? "True" : "False");
}

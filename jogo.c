// jogo.c
#include <stdio.h>
#include <string.h>
#include "jogo.h"

void jogarRodada(Fila* jogador1, Fila* jogador2, const char* atributoEscolhido) {
    Carta cartaJogador1 = desenfileirar(jogador1);
    Carta cartaJogador2 = desenfileirar(jogador2);

    int valor1, valor2;
    if (strcmp(atributoEscolhido, "hp") == 0) {
        valor1 = cartaJogador1.hp;
        valor2 = cartaJogador2.hp;
    } else if (strcmp(atributoEscolhido, "ataque") == 0) {
        valor1 = cartaJogador1.ataque;
        valor2 = cartaJogador2.ataque;
    } else if (strcmp(atributoEscolhido, "defesa") == 0) {
        valor1 = cartaJogador1.defesa;
        valor2 = cartaJogador2.defesa;
    } else if (strcmp(atributoEscolhido, "ataque_especial") == 0) {
        valor1 = cartaJogador1.ataque_especial;
        valor2 = cartaJogador2.ataque_especial;
    } else if (strcmp(atributoEscolhido, "defesa_especial") == 0) {
        valor1 = cartaJogador1.defesa_especial;
        valor2 = cartaJogador2.defesa_especial;
    }

    if (valor1 > valor2) {
        enfileirar(jogador1, cartaJogador1);
        enfileirar(jogador1, cartaJogador2);
    } else if (valor2 > valor1) {
        enfileirar(jogador2, cartaJogador1);
        enfileirar(jogador2, cartaJogador2);
    } else {
        // Implementação da lógica de empate
        if (!filaVazia(jogador1) && !filaVazia(jogador2)) {
            Carta novaCartaJogador1 = desenfileirar(jogador1);
            Carta novaCartaJogador2 = desenfileirar(jogador2);

            int novoValor1, novoValor2;
            if (strcmp(atributoEscolhido, "hp") == 0) {
                novoValor1 = novaCartaJogador1.hp;
                novoValor2 = novaCartaJogador2.hp;
            } else if (strcmp(atributoEscolhido, "ataque") == 0) {
                novoValor1 = novaCartaJogador1.ataque;
                novoValor2 = novaCartaJogador2.ataque;
            } else if (strcmp(atributoEscolhido, "defesa") == 0) {
                novoValor1 = novaCartaJogador1.defesa;
                novoValor2 = novaCartaJogador2.defesa;
            } else if (strcmp(atributoEscolhido, "ataque_especial") == 0) {
                novoValor1 = novaCartaJogador1.ataque_especial;
                novoValor2 = novaCartaJogador2.ataque_especial;
            } else if (strcmp(atributoEscolhido, "defesa_especial") == 0) {
                novoValor1 = novaCartaJogador1.defesa_especial;
                novoValor2 = novaCartaJogador2.defesa_especial;
            }

            if (novoValor1 > novoValor2) {
                enfileirar(jogador1, cartaJogador1);
                enfileirar(jogador1, cartaJogador2);
                enfileirar(jogador1, novaCartaJogador1);
                enfileirar(jogador1, novaCartaJogador2);
            } else if (novoValor2 > novoValor1) {
                enfileirar(jogador2, cartaJogador1);
                enfileirar(jogador2, cartaJogador2);
                enfileirar(jogador2, novaCartaJogador1);
                enfileirar(jogador2, novaCartaJogador2);
            } else {
                // Se empatar novamente, devolve as cartas às filas originais
                enfileirar(jogador1, cartaJogador1);
                enfileirar(jogador1, novaCartaJogador1);
                enfileirar(jogador2, cartaJogador2);
                enfileirar(jogador2, novaCartaJogador2);
            }
        } else {
            // Se um dos jogadores não tiver cartas para continuar, devolve as cartas
            enfileirar(jogador1, cartaJogador1);
            enfileirar(jogador2, cartaJogador2);
        }
    }
}

int jogoTerminado(Fila* jogador1, Fila* jogador2) {
    return filaVazia(jogador1) || filaVazia(jogador2);
}

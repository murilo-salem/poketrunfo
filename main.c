#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "baralho.h"
#include "jogo.h"
#include "fila.h"
#include "pokemon.h"

// Importação da funão da Pokedex.
void loadPokemonData(const char* filename, Node** head) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    char line[1024];
    fgets(line, sizeof(line), file); // Lê a linha de cabeçalho

    while (fgets(line, sizeof(line), file)) {
        Pokemon p;
        char legendary[10];

        sscanf(line, "%d,%49[^,],%19[^,],%19[^,],%d,%d,%d,%d,%d,%d,%d,%d,%9s",
               &p.id, p.name, p.type1, p.type2, &p.total, &p.hp, &p.attack,
               &p.defense, &p.spAtk, &p.spDef, &p.speed, &p.generation, legendary);
        p.legendary = strcmp(legendary, "True") == 0;

        insertEnd(head, p);
    }

    fclose(file);
}

// Importação da função do Pikachu dançando.
void Pikachu_Dancando();

int main(){

    // Menu bonitinho.
    printf("[---------------------------------------------------------------------]\n"); 
    printf("             * > # > ! > BEM VINDO AO POKEVERSO < ! < # < * \n\n"); 

    printf("                       [1] - Jogar Poketrunfo\n"); 
    printf("                       [2] - Ver sua Pokedex\n"); 
    printf("                       [3] - Trivia (Extra)\n"); 
    printf("                       [4] - Dancing Pikachu (Extra)\n"); 
    printf("                       [5] - Sair\n");  

    printf("                                           /\n");
    printf("                        _,.------....___,.' ',.-.\n");
    printf("                     ,-'          _,.--\"        |\n");
    printf("                   ,'         _.-'              .\n");
    printf("                  /   ,     ,'                   `\n");
    printf("                 .   /     /                     ``.\n");
    printf("                 |  |     .                       \\.\\\n");
    printf("       ____      |___._.  |       __               \\ `.\n");
    printf("     .'    `---\"\"       ``\"-.--\"'`  \\               .  \\\n");
    printf("    .  ,            __               `              |   .\n");
    printf("    `,'         ,-\"'  .               \\             |    L\n");
    printf("   ,'          '    _.'                -._          /    |\n");
    printf("  ,`-.    ,\".   `--'                      >.      ,'     |\n");
    printf(" . .'\\'   `-'       __    ,  ,-.         /  `.__.-      ,'\n");
    printf(" ||:, .           ,'  ;  /  / \\ `        `.    .      .'/\n");
    printf(" j|:D  \\          `--'  ' ,'_  . .         `.__, \\   , /\n");
    printf("/ L:_  |                 .  \"' :_;                `.'.'\n");
    printf(".    \"\"'                  \"\"\"\"\"'                    V\n");
    printf(" `.                                 .    `.   _,..  `\n");
    printf("   `,_   .    .                _,-'/    .. `,'   __  `\n");
    printf("    ) \\`._        ___....----\"'  ,'   .'  \\ |   '  \\  .\n");
    printf("   /   `. \"`-.--\"'         _,' ,'     `---' |    `./  |\n");
    printf("  .   _  `\"\"'--.._____..--\"   ,             '         |\n");
    printf("  | .\" `. `-.                /-.           /          ,\n");
    printf("  | `._.'    `,_            ;  /         ,'          .\n");
    printf(" .'          /| `-.        . ,'         ,           ,\n");
    printf(" '-.__ __ _,','    '`-..___;-...__   ,.'\\ ____.___.'\n");
    printf(" `\"^--'..'   '-`-^-'\"--    `-^-'`.''\"\"\"\"\"`.,^.`.--' mh\n");
    printf("\n");
    printf("\n");

    printf("[---------------------------------------------------------------------]\n");

    int EscolhaMenu;
    scanf("%d", &EscolhaMenu);

    system("cls");

    switch (EscolhaMenu){
    case 1:
        int QuantidadeDeCartas;
            printf("Insira o número de cartas: (Deve ser um número par para ambos jogadores terem o mesmo número de cartas!)\n");
            scanf("%d", &QuantidadeDeCartas);

            // Verifica se o número de cartas é válido
            if (QuantidadeDeCartas < 2 || QuantidadeDeCartas % 2 != 0) {
                printf("Erro: o número de cartas deve ser par e maior ou igual a 2.\n");
                return 1;
            }

            int numCartas = QuantidadeDeCartas; // Utiliza diretamente o valor lido

            srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

            Fila* baralho = criarFila();
            Fila* jogador1 = criarFila();
            Fila* jogador2 = criarFila();

            inicializarBaralho(baralho);
            embaralharBaralho(baralho);
            distribuirCartas(baralho, jogador1, jogador2, numCartas);

            while (!jogoTerminado(jogador1, jogador2)) {
                char atributoEscolhido[20];
                printf("Escolha um atributo (hp, ataque, defesa, ataque_especial, defesa_especial): ");
                scanf("%s", atributoEscolhido);

                jogarRodada(jogador1, jogador2, atributoEscolhido);
            }

            if (filaVazia(jogador1)) {
                printf("Jogador 2 venceu!\n");
            } else {
                printf("Jogador 1 venceu!\n");
            }

            liberarFila(baralho);
            liberarFila(jogador1);
            liberarFila(jogador2);

        break;
    
    case 2:

        Node* head = NULL;
        loadPokemonData("C:\\Users\\muril\\Documents\\Trabalho_Final_AeD\\Poketrunfo\\Pokemon.csv", &head);

        char searchName[50];
        printf("Digite o nome do Pokemon para buscar: ");
        scanf("%49s", searchName);

        system("cls");

        Node* found = findPokemon(head, searchName);
        if (found) {
            printPokemon(found->data);
        } else {
            printf("Pokemon nao encontrado!\n");
        }

        break;

    case 4:
        Pikachu_Dancando();        
        break;

    case 5:
        exit(0);
        break;  

    default:
        break;
    }

    return 0;
}
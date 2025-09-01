#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ESTADOS 6

// Definindo a estrutura de uma carta (estado)
typedef struct {
    char nome[30];
    float pib;            // em bilhões de R$
    float populacao;      // em milhões
    float area;           // em mil km²
    int pontos_turisticos; // quantidade
} Estado;

// Função para mostrar uma carta
void mostrarEstado(Estado e) {
    printf("Estado: %s\n", e.nome);
    printf("  1. PIB (bilhões R$): %.2f\n", e.pib);
    printf("  2. População (milhões): %.2f\n", e.populacao);
    printf("  3. Área (mil km²): %.2f\n", e.area);
    printf("  4. Pontos turísticos: %d\n", e.pontos_turisticos);
}

int main() {
    srand(time(NULL));

    // Baralho com alguns estados brasileiros (valores fictícios para demonstração)
    Estado estados[NUM_ESTADOS] = {
        {"São Paulo", 2600.0, 46.0, 248.2, 30},
        {"Rio de Janeiro", 830.0, 17.5, 43.8, 25},
        {"Bahia", 310.0, 14.9, 564.7, 20},
        {"Minas Gerais", 700.0, 21.0, 586.5, 15},
        {"Amazonas", 110.0, 4.2, 1570.7, 12},
        {"Paraná", 450.0, 11.4, 199.3, 18}
    };

    // Sorteia cartas para jogador e computador
    int idxJogador = rand() % NUM_ESTADOS;
    int idxComputador;
    do {
        idxComputador = rand() % NUM_ESTADOS;
    } while (idxComputador == idxJogador);

    Estado cartaJogador = estados[idxJogador];
    Estado cartaComputador = estados[idxComputador];

    // Mostra carta do jogador
    printf("=== SUA CARTA ===\n");
    mostrarEstado(cartaJogador);

    // Escolha do atributo
    int escolha;
    printf("\nEscolha um atributo para disputar:\n");
    printf("1 - PIB\n2 - População\n3 - Área\n4 - Pontos turísticos\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &escolha);

    // Valores a serem comparados
    float valorJogador = 0.0, valorComputador = 0.0;

    // Definindo qual atributo será comparado
    switch (escolha) {
        case 1:
            valorJogador = cartaJogador.pib;
            valorComputador = cartaComputador.pib;
            break;
        case 2:
            valorJogador = cartaJogador.populacao;
            valorComputador = cartaComputador.populacao;
            break;
        case 3:
            valorJogador = cartaJogador.area;
            valorComputador = cartaComputador.area;
            break;
        case 4:
            valorJogador = (float)cartaJogador.pontos_turisticos;
            valorComputador = (float)cartaComputador.pontos_turisticos;
            break;
        default:
            printf("Atributo inválido.\n");
            return 1;
    }

    // Mostrar carta do computador
    printf("\n=== CARTA DO COMPUTADOR ===\n");
    mostrarEstado(cartaComputador);

    // Resultado
    printf("\n=== RESULTADO ===\n");
    if (valorJogador > valorComputador) {
        printf("Você venceu esta rodada!\n");
    } else if (valorJogador < valorComputador) {
        printf("Você perdeu esta rodada.\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
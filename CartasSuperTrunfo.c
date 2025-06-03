#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.

int main() {
    // Definição das variáveis para armazenar os dados das duas cartas

    // Carta 1 - Minas Gerais
    char estado1 = 'A';                      // Letra representando o estado
    char codigo1[4] = "A01";                 // Código da carta
    char nomeCidade1[50] = "Belo Horizonte"; // Nome da cidade
    int populacao1 = 2523000;                // População estimada
    float area1 = 331.4;                     // Área em km²
    float pib1 = 88.5;                       // PIB em bilhões de reais
    int pontosTuristicos1 = 20;              // Quantidade de pontos turísticos

    // Carta 2 - São Paulo
    char estado2 = 'B';
    char codigo2[4] = "B02";
    char nomeCidade2[50] = "São Paulo";
    int populacao2 = 12325000;
    float area2 = 1521.11;
    float pib2 = 699.28;
    int pontosTuristicos2 = 50;

    // Exibição dos dados da Carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);

    // Exibição dos dados da Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);

    return 0; // Fim do programa
}

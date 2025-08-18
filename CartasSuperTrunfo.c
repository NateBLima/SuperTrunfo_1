#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Cadastro das Cartas com Cálculos
// Agora o programa calcula Densidade Populacional e PIB per Capita.

int main() {
    // --- Carta 1: Minas Gerais / Belo Horizonte ---
    char estado1 = 'A';
    char codigo1[4] = "A01";
    char nomeCidade1[50] = "Belo Horizonte";
    int populacao1 = 2523000;
    float area1 = 331.4;
    float pib1 = 88.5; // PIB em bilhões
    int pontosTuristicos1 = 20;

    // Cálculos da Carta 1
    float densidade1 = populacao1 / area1;          // habitantes por km²
    float pibPerCapita1 = (pib1 * 1000000000) / populacao1; // PIB total convertido p/ reais dividido pela população

    // --- Carta 2: São Paulo ---
    char estado2 = 'B';
    char codigo2[4] = "B02";
    char nomeCidade2[50] = "São Paulo";
    int populacao2 = 12325000;
    float area2 = 1521.11;
    float pib2 = 699.28; // PIB em bilhões
    int pontosTuristicos2 = 50;

    // Cálculos da Carta 2
    float densidade2 = populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // --- Exibição dos dados da Carta 1 ---
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    // --- Exibição dos dados da Carta 2 ---
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    return 0; // fim do programa
}

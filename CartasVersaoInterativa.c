#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.

int main() {
    // Definição das variáveis para armazenar os dados das duas cartas

    // Carta 1
    char estado1;                       // Estado representado por uma letra de A a H
    char codigo1[4];                    // Código da carta, ex: A01
    char nomeCidade1[50];              // Nome da cidade
    int populacao1;                    // População da cidade
    float area1;                       // Área da cidade em km²
    float pib1;                        // PIB da cidade em bilhões de reais
    int pontosTuristicos1;            // Número de pontos turísticos da cidade

    // Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");

    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado1); // Lê um caractere com espaço antes para consumir qualquer enter anterior

    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1); // Lê a string (código)

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1); // Lê a string até a quebra de linha (permite nomes com espaços)

    printf("População: ");
    scanf("%d", &populacao1); // Lê um número inteiro

    printf("Área (em km²): ");
    scanf("%f", &area1); // Lê um número com ponto flutuante

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1); // Lê um número com ponto flutuante

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1); // Lê um número inteiro

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");

    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

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

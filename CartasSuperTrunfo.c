#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[20];          // Estado da cidade
    char codigo[5];           // Código da carta (ex: A01, B02)
    char nomeCidade[50];      // Nome da cidade
    int populacao;            // População da cidade
    float area;               // Área em km²
    float pib;                // PIB em bilhões
    int numPontosTuristicos;  // Quantidade de pontos turísticos
    float densidade;          // População / Área
    float pibPerCapita;       // PIB / População
};

int main() {
    // Declaração das duas cartas
    struct Carta carta1;
    struct Carta carta2;

    // Cadastro da primeira carta (preenchido manualmente)
    strcpy(carta1.estado, "Minas Gerais");
    strcpy(carta1.codigo, "MG01");
    strcpy(carta1.nomeCidade, "Belo Horizonte");
    carta1.populacao = 2500000;
    carta1.area = 331.4;
    carta1.pib = 100000.0;
    carta1.numPontosTuristicos = 15;
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    // Cadastro da segunda carta
    strcpy(carta2.estado, "São Paulo");
    strcpy(carta2.codigo, "SP01");
    strcpy(carta2.nomeCidade, "São Paulo");
    carta2.populacao = 12300000;
    carta2.area = 1521.1;
    carta2.pib = 700000.0;
    carta2.numPontosTuristicos = 30;
    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Exibir as cartas cadastradas
    printf("=== CARTA 1 ===\n");
    printf("%s - %s\n", carta1.estado, carta1.codigo);
    printf("Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.numPontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade);
    printf("PIB per Capita: %.2f\n\n", carta1.pibPerCapita);

    printf("=== CARTA 2 ===\n");
    printf("%s - %s\n", carta2.estado, carta2.codigo);
    printf("Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.numPontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade);
    printf("PIB per Capita: %.2f\n\n", carta2.pibPerCapita);

    // -----------------------------
    // Escolha do atributo para comparação
    // (aqui você troca para 'populacao', 'area', 'pib', 'densidade', 'pibPerCapita')
    // -----------------------------
    printf("=== COMPARACAO ===\n");
    printf("Atributo escolhido: Populacao\n\n");

    // Comparação pelo atributo POPULAÇÃO
    if (carta1.populacao > carta2.populacao) {
        printf("Carta 1 venceu! (%s - %d habitantes)\n", carta1.nomeCidade, carta1.populacao);
        printf("Carta 2 perdeu. (%s - %d habitantes)\n", carta2.nomeCidade, carta2.populacao);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Carta 2 venceu! (%s - %d habitantes)\n", carta2.nomeCidade, carta2.populacao);
        printf("Carta 1 perdeu. (%s - %d habitantes)\n", carta1.nomeCidade, carta1.populacao);
    } else {
        printf("Empate! Ambas as cartas tem %d habitantes.\n", carta1.populacao);
    }

    return 0;
}

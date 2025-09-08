#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[50];          // Nome do estado
    char codigo[5];           // Código da carta
    char cidade[50];          // Nome da cidade
    int populacao;            // População
    float area;               // Área em km²
    float pib;                // PIB em bilhões
    int numPontosTuristicos;  // Número de pontos turísticos
    float densidade;          // Densidade populacional (calculada)
    float pibPerCapita;       // PIB per capita (calculado)
} Carta;

int main() {
    // Definição das duas cartas fixas
    Carta carta1 = {"Minas Gerais", "A01", "Belo Horizonte", 2500000, 330.9, 120.5, 15};
    Carta carta2 = {"São Paulo", "B02", "São Paulo", 12300000, 1521.0, 699.3, 25};

    // Cálculo de densidade populacional e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int opcao;

    // Menu interativo para escolher atributo de comparação
    printf("=== Super Trunfo - Comparacao de Cartas ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de pontos turisticos\n");
    printf("5 - Densidade demografica\n");
    printf("6 - PIB per capita\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\nComparando %s (Carta 1) e %s (Carta 2):\n\n", carta1.estado, carta2.estado);

    // Switch para decidir qual atributo será comparado
    switch (opcao) {
        case 1: // População
            printf("Atributo: Populacao\n");
            printf("%s: %d\n", carta1.cidade, carta1.populacao);
            printf("%s: %d\n", carta2.cidade, carta2.populacao);

            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.cidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Area\n");
            printf("%s: %.2f km²\n", carta1.cidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.cidade, carta2.area);

            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.cidade);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.cidade, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.cidade, carta2.pib);

            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.cidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d\n", carta1.cidade, carta1.numPontosTuristicos);
            printf("%s: %d\n", carta2.cidade, carta2.numPontosTuristicos);

            if (carta1.numPontosTuristicos > carta2.numPontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.cidade);
            } else if (carta2.numPontosTuristicos > carta1.numPontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade demográfica (inverte a regra)
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.2f hab/km²\n", carta1.cidade, carta1.densidade);
            printf("%s: %.2f hab/km²\n", carta2.cidade, carta2.densidade);

            if (carta1.densidade < carta2.densidade) {
                printf("Resultado: %s venceu!\n", carta1.cidade);
            } else if (carta2.densidade < carta1.densidade) {
                printf("Resultado: %s venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 6: // PIB per capita
            printf("Atributo: PIB per capita\n");
            printf("%s: %.6f\n", carta1.cidade, carta1.pibPerCapita);
            printf("%s: %.6f\n", carta2.cidade, carta2.pibPerCapita);

            if (carta1.pibPerCapita > carta2.pibPerCapita) {
                printf("Resultado: %s venceu!\n", carta1.cidade);
            } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
                printf("Resultado: %s venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default: // Opção inválida
            printf("Opcao invalida! Tente novamente.\n");
            break;
    }

    return 0;
}

#include <stdio.h>

/*
  Desafio Super Trunfo - Países
  Tema 3 - Batalha de Cartas (nível mestre)

  O programa:
    1) Lê os dados de duas cartas (interativo).
    2) Calcula Densidade Populacional e PIB per Capita.
    3) Calcula o "Super Poder" somando:
       - população
       - área
       - PIB (convertido de bilhões para reais)
       - nº de pontos turísticos
       - PIB per capita (em reais)
       - inverso da densidade (1/densidade) -> menor densidade => maior termo
    4) Compara atributo a atributo e mostra qual cidade venceu (ou empate).
*/

int main() {
    /* -----------------------------
       Declaração das variáveis
       -----------------------------
       Observações de tipos:
       - populacao: unsigned long int (cabe número grande, sem sinal).
       - area, pib e demais cálculos: float (suficiente para duas casas decimais e somas).
    */

    // Carta 1
    char estado1;             // Letra A..H
    char codigo1[4];          // Ex: A01 (3 chars + '\0')
    char nomeCidade1[50];     // Nome com espaços
    unsigned long int populacao1;
    float area1;              // km²
    float pib1;               // bilhões de reais
    int pontosTuristicos1;

    // Derivados da carta 1
    float densidade1;         // hab/km²
    float pibPerCapita1;      // reais
    float superPoder1;        // métrica composta do jogo

    // Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;               // bilhões de reais
    int pontosTuristicos2;

    // Derivados da carta 2
    float densidade2;
    float pibPerCapita2;
    float superPoder2;

    /* -----------------------------
       Entrada de dados (Carta 1)
       ----------------------------- */
    printf("Cadastro da Carta 1:\n");

    // Espaço antes de %c consome newline pendente do buffer
    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado1);

    // %s lê até espaço; suficiente para código curto (A01)
    printf("Código da Carta (ex: A01): ");
    scanf("%3s", codigo1); // %3s evita overflow (3 + '\0')

    // " %[^\n]" lê até a quebra de linha => permite espaços no nome
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    // %lu para unsigned long int
    printf("População: ");
    scanf("%lu", &populacao1);

    // %f para float
    printf("Área (em km²): ");
    scanf("%f", &area1);

    // PIB em bilhões (ex.: 699.28)
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    /* -----------------------------
       Cálculos (Carta 1)
       -----------------------------
       - Casts explícitos garantem que a divisão use float.
       - PIB é convertido para reais (bilhões * 1e9) para alinhar com o per capita.
    */
    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1;
    superPoder1 = (float)populacao1
                + area1
                + (pib1 * 1000000000.0f)
                + (float)pontosTuristicos1
                + pibPerCapita1
                + (1.0f / densidade1);

    /* -----------------------------
       Entrada de dados (Carta 2)
       ----------------------------- */
    printf("\nCadastro da Carta 2:\n");

    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    /* -----------------------------
       Cálculos (Carta 2)
       ----------------------------- */
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    superPoder2 = (float)populacao2
                + area2
                + (pib2 * 1000000000.0f)
                + (float)pontosTuristicos2
                + pibPerCapita2
                + (1.0f / densidade2);

    /* -----------------------------
       Exibição dos dados
       -----------------------------
       - Duas casas decimais para floats.
       - Mostramos tudo antes da batalha.
    */
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    /* -----------------------------
       Batalha: Comparações
       -----------------------------
       Regras:
       - População, Área, PIB, Pontos, PIB per Capita, Super Poder: MAIOR vence.
       - Densidade Populacional: MENOR vence.
       Em caso de valores iguais: EMPATE.
    */
    printf("\n=== Resultados da Batalha ===\n");

    // População (maior vence)
    if (populacao1 == populacao2) {
        printf("População: Empate\n");
    } else if (populacao1 > populacao2) {
        printf("População: %s venceu (Carta 1)\n", nomeCidade1);
    } else {
        printf("População: %s venceu (Carta 2)\n", nomeCidade2);
    }

    // Área (maior vence)
    if (area1 == area2) {
        printf("Área: Empate\n");
    } else if (area1 > area2) {
        printf("Área: %s venceu (Carta 1)\n", nomeCidade1);
    } else {
        printf("Área: %s venceu (Carta 2)\n", nomeCidade2);
    }

    // PIB (maior vence) — lembrando: entrada em bilhões; comparação direta mantém unidade igual para ambas
    if (pib1 == pib2) {
        printf("PIB: Empate\n");
    } else if (pib1 > pib2) {
        printf("PIB: %s venceu (Carta 1)\n", nomeCidade1);
    } else {
        printf("PIB: %s venceu (Carta 2)\n", nomeCidade2);
    }

    // Pontos Turísticos (maior vence)
    if (pontosTuristicos1 == pontosTuristicos2) {
        printf("Pontos Turísticos: Empate\n");
    } else if (pontosTuristicos1 > pontosTuristicos2) {
        printf("Pontos Turísticos: %s venceu (Carta 1)\n", nomeCidade1);
    } else {
        printf("Pontos Turísticos: %s venceu (Carta 2)\n", nomeCidade2);
    }

    // PIB per Capita (maior vence)
    if (pibPerCapita1 == pibPerCapita2) {
        printf("PIB per Capita: Empate\n");
    } else if (pibPerCapita1 > pibPerCapita2) {
        printf("PIB per Capita: %s venceu (Carta 1)\n", nomeCidade1);
    } else {
        printf("PIB per Capita: %s venceu (Carta 2)\n", nomeCidade2);
    }

    // Densidade Populacional (menor vence)
    if (densidade1 == densidade2) {
        printf("Densidade Populacional: Empate\n");
    } else if (densidade1 < densidade2) {
        printf("Densidade Populacional: %s venceu (Carta 1)\n", nomeCidade1);
    } else {
        printf("Densidade Populacional: %s venceu (Carta 2)\n", nomeCidade2);
    }

    // Super Poder (maior vence)
    if (superPoder1 == superPoder2) {
        printf("Super Poder: Empate\n");
    } else if (superPoder1 > superPoder2) {
        printf("Super Poder: %s venceu (Carta 1)\n", nomeCidade1);
    } else {
        printf("Super Poder: %s venceu (Carta 2)\n", nomeCidade2);
    }

    /* Fim. Sem loops, só decisões claras. Conversões de tipo feitas onde importa.
       Dica prática: se área for 0, densidade explode; aqui assumimos entrada válida.
       Quer blindagem? Aí entra validação extra (não pedida no desafio).
    */

    return 0;
}

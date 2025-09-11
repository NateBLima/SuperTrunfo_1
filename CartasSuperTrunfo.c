#include <stdio.h>
#include <string.h>
#include <math.h>

/*
  Super Trunfo - Desafio Final
  - Menu dinâmico (segundo atributo não repete o primeiro).
  - Comparações individuais (regra: maior vence; densidade -> menor vence).
  - Soma dos atributos (para densidade usei 1/densidade na soma, para manter a regra "menor melhor").
  - Tratamento de empates com EPS para floats.
*/

typedef struct {
    char estado[50];
    char codigo[6];
    char cidade[50];
    int populacao;
    float area;               // km²
    float pib;                // em bilhões de reais
    int numPontosTuristicos;
    float densidade;          // calculada: populacao / area
    float pibPerCapita;       // calculada: (pib * 1e9) / populacao (em reais)
} Carta;

const float EPS = 1e-6f;

/* Retorna o nome do atributo para exibição */
const char *nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB (bilhoes)";
        case 4: return "Numero de pontos turisticos";
        case 5: return "Densidade demografica";
        case 6: return "PIB per capita (reais)";
        default: return "Opcao invalida";
    }
}

/* Função que devolve o valor (float) do atributo pedido para a carta */
float getValor(int opcao, Carta c) {
    switch (opcao) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;                     // em bilhoes (mesma unidade para as duas cartas)
        case 4: return (float)c.numPontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.pibPerCapita;            // em reais
        default: return 0.0f;
    }
}

/* Imprime o valor formatado conforme o tipo do atributo */
void imprimirValorFormatado(int opcao, Carta c) {
    switch (opcao) {
        case 1: printf("%s: %d\n", c.cidade, c.populacao); break;
        case 2: printf("%s: %.2f km²\n", c.cidade, c.area); break;
        case 3: printf("%s: %.2f bilhoes\n", c.cidade, c.pib); break;
        case 4: printf("%s: %d\n", c.cidade, c.numPontosTuristicos); break;
        case 5: printf("%s: %.2f hab/km²\n", c.cidade, c.densidade); break;
        case 6: printf("%s: R$ %.2f\n", c.cidade, c.pibPerCapita); break;
        default: printf("%s: (opcao invalida)\n", c.cidade); break;
    }
}

int main() {
    /* --- Cartas pré-cadastradas --- */
    Carta carta1 = {"Minas Gerais", "A01", "Belo Horizonte", 2500000, 330.9f, 120.5f, 15};
    Carta carta2 = {"São Paulo",     "B02", "São Paulo",      12300000, 1521.0f, 699.3f, 25};

    /* --- Cálculos iniciais --- */
    carta1.densidade = (float)carta1.populacao / carta1.area;
    carta2.densidade = (float)carta2.populacao / carta2.area;

    /* PIB per capita em reais: pib em bilhões * 1e9 / populacao */
    carta1.pibPerCapita = (carta1.pib * 1e9f) / (float)carta1.populacao;
    carta2.pibPerCapita = (carta2.pib * 1e9f) / (float)carta2.populacao;

    int opcao1 = 0, opcao2 = 0;

    /* --- Menu para escolher primeiro atributo --- */
    do {
        printf("=== Super Trunfo - Escolha de Atributos ===\n");
        printf("1 - Populacao\n");
        printf("2 - Area\n");
        printf("3 - PIB (bilhoes)\n");
        printf("4 - Numero de pontos turisticos\n");
        printf("5 - Densidade demografica\n");
        printf("6 - PIB per capita\n");
        printf("Escolha o PRIMEIRO atributo (1-6): ");
        if (scanf("%d", &opcao1) != 1) { // leitura inválida
            printf("Entrada invalida. Reinicie e digite um numero.\n");
            return 1;
        }
        if (opcao1 < 1 || opcao1 > 6) {
            printf("Opcao invalida. Tente novamente.\n\n");
        }
    } while (opcao1 < 1 || opcao1 > 6);

    /* --- Menu dinâmico para escolher segundo atributo (diferente) --- */
    do {
        printf("\nEscolha o SEGUNDO atributo (diferente do %s):\n", nomeAtributo(opcao1));
        for (int i = 1; i <= 6; i++) {
            if (i == opcao1) continue; // esconde opção já escolhida
            printf("%d - %s\n", i, nomeAtributo(i));
        }
        printf("Escolha o SEGUNDO atributo (1-6, diferente do primeiro): ");
        if (scanf("%d", &opcao2) != 1) {
            printf("Entrada invalida. Reinicie e digite um numero.\n");
            return 1;
        }
        if (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1) {
            printf("Opcao invalida ou repetida. Tente novamente.\n\n");
        }
    } while (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1);

    /* --- Pegar os valores selecionados para cada carta --- */
    float v1_c1 = getValor(opcao1, carta1);
    float v1_c2 = getValor(opcao1, carta2);
    float v2_c1 = getValor(opcao2, carta1);
    float v2_c2 = getValor(opcao2, carta2);

    /* --- Exibir os atributos e valores --- */
    printf("\nComparando: %s (Carta 1) VS %s (Carta 2)\n", carta1.cidade, carta2.cidade);
    printf("Atributo 1: %s\n", nomeAtributo(opcao1));
    imprimirValorFormatado(opcao1, carta1);
    imprimirValorFormatado(opcao1, carta2);

    printf("\nAtributo 2: %s\n", nomeAtributo(opcao2));
    imprimirValorFormatado(opcao2, carta1);
    imprimirValorFormatado(opcao2, carta2);

    /* --- Decidir vencedor do atributo 1 --- */
    int win1_attr1 = 0, win2_attr1 = 0;
    if (opcao1 == 5) {
        /* densidade: menor vence */
        if (fabsf(v1_c1 - v1_c2) < EPS) { /* empate */ }
        else if (v1_c1 < v1_c2) win1_attr1 = 1;
        else win2_attr1 = 1;
    } else {
        /* maior vence */
        if (fabsf(v1_c1 - v1_c2) < EPS) { /* empate */ }
        else if (v1_c1 > v1_c2) win1_attr1 = 1;
        else win2_attr1 = 1;
    }

    if (win1_attr1) printf("\nVencedor do atributo 1: %s\n", carta1.cidade);
    else if (win2_attr1) printf("\nVencedor do atributo 1: %s\n", carta2.cidade);
    else printf("\nVencedor do atributo 1: Empate!\n");

    /* --- Decidir vencedor do atributo 2 --- */
    int win1_attr2 = 0, win2_attr2 = 0;
    if (opcao2 == 5) {
        if (fabsf(v2_c1 - v2_c2) < EPS) { }
        else if (v2_c1 < v2_c2) win1_attr2 = 1;
        else win2_attr2 = 1;
    } else {
        if (fabsf(v2_c1 - v2_c2) < EPS) { }
        else if (v2_c1 > v2_c2) win1_attr2 = 1;
        else win2_attr2 = 1;
    }

    if (win1_attr2) printf("Vencedor do atributo 2: %s\n", carta1.cidade);
    else if (win2_attr2) printf("Vencedor do atributo 2: %s\n", carta2.cidade);
    else printf("Vencedor do atributo 2: Empate!\n");

    /* --- Soma dos atributos (para somar, usei inverso para densidade) --- */
    float contrib1_a1 = (opcao1 == 5) ? ( (fabsf(v1_c1) > EPS) ? (1.0f / v1_c1) : 0.0f ) : v1_c1;
    float contrib2_a1 = (opcao1 == 5) ? ( (fabsf(v1_c2) > EPS) ? (1.0f / v1_c2) : 0.0f ) : v1_c2;

    float contrib1_a2 = (opcao2 == 5) ? ( (fabsf(v2_c1) > EPS) ? (1.0f / v2_c1) : 0.0f ) : v2_c1;
    float contrib2_a2 = (opcao2 == 5) ? ( (fabsf(v2_c2) > EPS) ? (1.0f / v2_c2) : 0.0f ) : v2_c2;

    float somaCarta1 = contrib1_a1 + contrib1_a2;
    float somaCarta2 = contrib2_a1 + contrib2_a2;

    /* --- Exibir somas e decidir vencedor final --- */
    printf("\n--- Soma dos atributos (nota: densidade usa 1/densidade na soma) ---\n");
    printf("%s - Soma: %.6f\n", carta1.cidade, somaCarta1);
    printf("%s - Soma: %.6f\n", carta2.cidade, somaCarta2);

    if (fabsf(somaCarta1 - somaCarta2) < EPS) {
        printf("\nResultado Final: Empate!\n");
    } else if (somaCarta1 > somaCarta2) {
        printf("\nResultado Final: %s venceu a rodada!\n", carta1.cidade);
    } else {
        printf("\nResultado Final: %s venceu a rodada!\n", carta2.cidade);
    }

    return 0;
}

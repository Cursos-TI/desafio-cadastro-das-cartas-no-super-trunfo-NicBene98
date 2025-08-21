#include <stdio.h>

/* ===== Funções pedidas ===== */
float calcularDensidade(unsigned long populacao, float area_km2) {
    return (float)populacao / area_km2;                 // hab/km²
}

double calcularPibPerCapita(float pib_bilhoes, unsigned long populacao) {
    return (double)pib_bilhoes * 1e9 / (double)populacao; // R$ por habitante
}

/* Super Poder = pop + area + PIB(bi) + pontos + PIB per capita + (1/densidade) */
double calcularSuperPoder(unsigned long populacao, float area_km2,
                          float pib_bilhoes, int pontosTuristicos) {
    float dens = calcularDensidade(populacao, area_km2);
    double pib_pc = calcularPibPerCapita(pib_bilhoes, populacao);
    return (double)populacao + (double)area_km2 + (double)pib_bilhoes
           + (double)pontosTuristicos + pib_pc + (1.0 / (double)dens);
}
/* ======================================== */

int main(void) {
    /* -------- Dados da Carta 1 -------- */
    char Estado1;                  // 1 letra (A–H)
    char Codigo1[4];               // ex: A01
    char nomeCidade1[50];
    unsigned long populacao1;      
    float area1;
    float pib1;                   
    int  pontoTuristicos1;

    /* -------- Dados da Carta 2 -------- */
    char Estado2;                  // 1 letra (A–H)
    char Codigo2[4];
    char nomeCidade2[50];
    unsigned long populacao2;     
    float area2;
    float pib2;
    int  pontoTuristico2;

    /* ===== Leitura da Carta 1 ===== */
    printf("Cadastro da Carta 1:\n");

    char ufBuf1[3];
    printf("Estado (A-H): ");
    scanf(" %2s", ufBuf1);
    Estado1 = ufBuf1[0];

    printf("Codigo da Carta (EX:A01):");
    scanf(" %3s", Codigo1);
    getchar(); // consome o ENTER

    printf("Nome da Cidade:");
    scanf(" %49[^\n]", nomeCidade1);
    getchar(); // consome o ENTER

    printf("Populacao:");
    scanf(" %lu", &populacao1);

    printf("Area (em km2) ");
    scanf(" %f", &area1);

    printf("PIB (em bilhoes de reais):");
    scanf(" %f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf(" %d", &pontoTuristicos1);

    /* ===== Leitura da Carta 2 ===== */
    printf("\nCadastro da Carta 2:\n");

    char ufBuf2[3];
    printf("Estado (A-H): ");
    scanf(" %2s", ufBuf2);
    Estado2 = ufBuf2[0];

    printf("Codigo da Carta (EX:A01):");
    scanf(" %3s", Codigo2);
    getchar();

    printf("Nome da Cidade:");
    scanf(" %49[^\n]", nomeCidade2);
    getchar();

    printf("Populacao:");
    scanf(" %lu", &populacao2);

    printf("Area (em km2) ");
    scanf(" %f", &area2);

    printf("PIB (em bilhoes de reais):");
    scanf(" %f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf(" %d", &pontoTuristico2);

    /* ===== Impressão manual  + cálculos ===== */
    float dens1 = calcularDensidade(populacao1, area1);
    float dens2 = calcularDensidade(populacao2, area2);
    double pibpc1 = calcularPibPerCapita(pib1, populacao1);
    double pibpc2 = calcularPibPerCapita(pib2, populacao2);
    double super1 = calcularSuperPoder(populacao1, area1, pib1, pontoTuristicos1);
    double super2 = calcularSuperPoder(populacao2, area2, pib2, pontoTuristico2);

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", Estado1);
    printf("Codigo: %s\n", Codigo1);
    printf("Nome Da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontoTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n", dens1);
    printf("PIB per Capita: %.2f reais\n", pibpc1);
    printf("Super Poder: %.2f\n", super1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", Estado2);
    printf("Codigo: %s\n", Codigo2);
    printf("Nome Da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontoTuristico2);
    printf("Densidade Populacional: %.2f hab/km2\n", dens2);
    printf("PIB per Capita: %.2f reais\n", pibpc2);
    printf("Super Poder: %.2f\n", super2);

    /* ===== Comparação atributo a atributo  =====
       Regra: para Densidade Populacional vence o MENOR; para os demais, vence o MAIOR.
       Resultado: 1 = Carta 1 venceu; 0 = Carta 2 venceu.                                */
    int vPop   = (populacao1  > populacao2);
    int vArea  = (area1       > area2);
    int vPib   = (pib1        > pib2);
    int vPontos= (pontoTuristicos1 > pontoTuristico2);
    int vDens  = (dens1       < dens2);        // menor densidade vence
    int vPibPc = (pibpc1      > pibpc2);
    int vSuper = (super1      > super2);

    const char *gWinner[2] = {"Carta 2 venceu (0)", "Carta 1 venceu (1)"};

    printf("\nComparacao de Cartas:\n");
    printf("Populacao: %s\n",            gWinner[vPop]);
    printf("Area: %s\n",                  gWinner[vArea]);
    printf("PIB: %s\n",                   gWinner[vPib]);
    printf("Pontos Turisticos: %s\n",     gWinner[vPontos]);
    printf("Densidade Populacional: %s\n",gWinner[vDens]);
    printf("PIB per Capita: %s\n",        gWinner[vPibPc]);
    printf("Super Poder: %s\n",           gWinner[vSuper]);

    return 0;
}

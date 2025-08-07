#include <stdio.h>

int main (){
//Dados Carta 1
    char Estado1;
    char Codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontoTuristicos1;

    //Dados carta 2
    char Estado2;
    char Codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontoTuristico2;

    //Leitura dos dados da Carta 1 
    printf ("Cadastro da Carta 1:\n");

    printf ("Estado (A-H): " );
    scanf  ("   %c", &Estado1);
    getchar(); //limpar o enter

    printf  ("Codigo da Carta (EX:A01):");
    scanf   (" %s", Codigo1);
    getchar (); //limpar o enter

    printf  ("Nome da Cidade:");
    scanf   ("  %[^\n]", nomeCidade1);
    getchar();

    printf  ("Populacao:");
    scanf   ("  %d", &populacao1);
    getchar();

    printf  ("Area (em Km²) ");
    scanf   ("  %f", &area1);
    getchar();

    printf ("PIB (em bilhoes de reais):");
    scanf  ("   %f", &pib1);
    getchar();

    printf ("Numero de Pontos Turisticos : " );
    scanf  ("   %d", &pontoTuristicos1);
    getchar();

    // Dados Da Carta 2
    printf ("Cadastro da Carta 2: \n");
    printf ("Estado (A-H): " );
    scanf  ("   %c", &Estado2);
    getchar();

    printf  ("Codigo da Carta (EX:A01):");
    scanf   ("  %s", Codigo2);
    getchar();

    printf  ("Nome da Cidade:");
    scanf   ("  %[^\n]", nomeCidade2);
    getchar();

    printf  ("Populacao:");
    scanf   ("  %d", &populacao2);
    getchar();

    printf  ("Area (em Km²) ");
    scanf   ("  %f", &area2);
    getchar();

    printf ("PIB (em bilhoes de reais):");
    scanf  ("   %f", &pib2);
    getchar();

    printf ("Numero de Pontos Turisticos : " );
    scanf  ("   %d", &pontoTuristico2);
    getchar();

    //Impressão dos Dados Cadastrados
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", Estado1);
    printf("Codigo: %s\n", Codigo1);
    printf("Nome Da Cidade: %s\n", nomeCidade1);
    printf("Populaçao: %d\n", populacao1);
    printf("Area: %2.f km²\n", area1);
    printf("PIB: %2.f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontoTuristicos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", Estado2);
    printf("Codigo: %s\n", Codigo2);
    printf("Nome Da Cidade: %s\n", nomeCidade2);
    printf("Populaçao: %d\n", populacao2);
    printf("Area: %2.f km²\n", area2);
    printf("PIB: %2.f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontoTuristico2);
    
    





    return 0;
}
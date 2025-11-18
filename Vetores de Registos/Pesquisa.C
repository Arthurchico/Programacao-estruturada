#include <stdio.h>
#include <string.h>

#define ESTADOS 26


typedef struct {
    char nome[50];
    int veiculos;
    int acidentes;
} Estado;


void lerDados(Estado cad[]);
void maiorMenorAcidentes(Estado cad[], int *pMaior, int *pMenor);
float percentualAcidentes(Estado cad[], int i);
float mediaAcidentes(Estado cad[]);
void acimaDaMedia(Estado cad[], float media);


void lerDados(Estado cad[]) {
    for(int i = 0; i < ESTADOS; i++) {
        printf("\n--- Estado %d ---\n", i+1);

        printf("Nome do estado: ");
        fflush(stdin);
        fgets(cad[i].nome, 50, stdin);
        cad[i].nome[strcspn(cad[i].nome, "\n")] = '\0'; // remover quebra de linha
        
        printf("Numero de veiculos (2007): ");
        scanf("%d", &cad[i].veiculos);

        printf("Numero de acidentes (2007): ");
        scanf("%d", &cad[i].acidentes);

        fflush(stdin);
    }
}


void maiorMenorAcidentes(Estado cad[], int *pMaior, int *pMenor) {
    *pMaior = 0;
    *pMenor = 0;

    for(int i = 1; i < ESTADOS; i++) {
        if(cad[i].acidentes > cad[*pMaior].acidentes)
            *pMaior = i;

        if(cad[i].acidentes < cad[*pMenor].acidentes)
            *pMenor = i;
    }
}


float percentualAcidentes(Estado cad[], int i) {
    if(cad[i].veiculos == 0) return 0;
    return ( (float)cad[i].acidentes / cad[i].veiculos ) * 100.0;
}


float mediaAcidentes(Estado cad[]) {
    int soma = 0;
    for(int i = 0; i < ESTADOS; i++)
        soma += cad[i].acidentes;

    return (float)soma / ESTADOS;
}


void acimaDaMedia(Estado cad[], float media) {
    printf("\nEstados acima da média de acidentes (%.2f):\n", media);

    for(int i = 0; i < ESTADOS; i++) {
        if(cad[i].acidentes > media)
            printf(" - %s: %d acidentes\n", cad[i].nome, cad[i].acidentes);
    }
}


int main() {
    Estado cadastro[ESTADOS];
    int iMaior, iMenor;
    float media;


    lerDados(cadastro);


    maiorMenorAcidentes(cadastro, &iMaior, &iMenor);

    printf("\n--- Maior número de acidentes ---\n");
    printf("Estado: %s\nAcidentes: %d\n", cadastro[iMaior].nome, cadastro[iMaior].acidentes);

    printf("\n--- Menor número de acidentes ---\n");
    printf("Estado: %s\nAcidentes: %d\n", cadastro[iMenor].nome, cadastro[iMenor].acidentes);


    printf("\n--- Percentual de veiculos envolvidos em acidentes ---\n");
    for(int i = 0; i < ESTADOS; i++) {
        printf("%s: %.2f%%\n", cadastro[i].nome, percentualAcidentes(cadastro, i));
    }

    media = mediaAcidentes(cadastro);
    printf("\nMedia de acidentes no pais: %.2f\n", media);

    acimaDaMedia(cadastro, media);

    return 0;
}

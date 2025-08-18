#include <stdio.h>

int main() {
    float peso, altura, imc;

    printf("Digite o seu peso (em kg): ");
    scanf("%f", &peso);

    printf("Digite a sua altura (em metros, ex: 1.75): ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("\nSeu IMC e: %.2f\n", imc);

    printf("Classificacao: ");
    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc >= 18.5 && imc <= 24.9) {
        printf("Peso normal\n");
    } else if (imc >= 25.0 && imc <= 29.9) {
        printf("Sobrepeso\n");
    } else if (imc >= 30.0 && imc <= 34.9) {
        printf("Obesidade grau I\n");
    } else if (imc >= 35.0 && imc <= 39.9) {
        printf("Obesidade grau II\n");
    } else {
        printf("Obesidade grau III (morbida)\n");
    }

    return 0;
}
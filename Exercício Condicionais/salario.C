#include <stdio.h>

int main() {
    double salario, imposto, percentual;

    printf("Digite o seu salário (CLT) em R$: ");
    scanf("%lf", &salario);

    if (salario <= 2112.00) {
        imposto = 0.0;
        percentual = 0.0;
    } else if (salario <= 2826.65) {
        imposto = (salario * 0.075) - 158.40;
        percentual = 7.5;
    } else if (salario <= 3751.05) {
        imposto = (salario * 0.15) - 370.40;
        percentual = 15.0;
    } else if (salario <= 4664.68) {
        imposto = (salario * 0.225) - 651.73;
        percentual = 22.5;
    } else {
        imposto = (salario * 0.275) - 884.96;
        percentual = 27.5;
    }

    printf("\n--- Resultado ---\n");
    printf("Salário: R$ %.2f\n", salario);
    printf("Percentual de Imposto de Renda: %.1f%%\n", percentual);
    printf("Valor do Imposto Retido na Fonte: R$ %.2f\n", imposto);

    return 0;
}
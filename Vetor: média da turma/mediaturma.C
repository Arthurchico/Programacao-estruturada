#include <stdio.h>

int main() {
    float nota1[30], nota2[30], media[30];
    float soma = 0, media_turma;
    int i;

    for (i = 0; i < 30; i++) {
        printf("Digite a primeira nota do aluno %d: ", i+1);
        scanf("%f", &nota1[i]);
        printf("Digite a segunda nota do aluno %d: ", i+1);
        scanf("%f", &nota2[i]);

        media[i] = (nota1[i] * 2 + nota2[i] * 3) / 5.0;

        soma += media[i];
    }
    media_turma = soma / 30.0;

    printf("\nMédia da turma = %.2f\n", media_turma);

    printf("\nAlunos acima da média da turma:\n");
    for (i = 0; i < 30; i++) {
        if (media[i] > media_turma) {
            printf("Aluno %d -> Nota1: %.2f | Nota2: %.2f | Média: %.2f\n",
                   i+1, nota1[i], nota2[i], media[i]);
        }
    }

    return 0;
}

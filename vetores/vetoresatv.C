#include <stdio.h>

#define MAX 50

void imprimirVetor(int v[], int n) {
    if (n == 0) {
        printf("Vetor vazio.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int buscaBinaria(int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (v[meio] == x) return meio;
        if (v[meio] < x) ini = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int inserirOrdenado(int v[], int *n, int capacidade, int valor) {
    if (*n >= capacidade) return 0;

    int i = *n - 1;
    while (i >= 0 && v[i] > valor) {
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = valor;
    (*n)++;
    return 1;
}

int removerElemento(int v[], int *n, int valor) {
    int pos = buscaBinaria(v, *n, valor);
    if (pos == -1) return 0;

    for (int i = pos; i < *n - 1; i++) {
        v[i] = v[i + 1];
    }
    (*n)--;
    return 1;
}

int main() {
    int vetor[MAX];
    int capacidade, tamanho = 0, valor, opcao;

    do {
        printf("Digite a capacidade do vetor (entre 3 e 50): ");
        scanf("%d", &capacidade);
    } while (capacidade < 3 || capacidade > MAX);

    printf("Quantos valores deseja inserir inicialmente? ");
    int qtd;
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        inserirOrdenado(vetor, &tamanho, capacidade, valor);
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Imprimir vetor\n");
        printf("2 - Consultar valor (busca binaria)\n");
        printf("3 - Remover valor\n");
        printf("4 - Inserir valor\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirVetor(vetor, tamanho);
                break;

            case 2: {
                printf("Digite o valor a consultar: ");
                scanf("%d", &valor);
                int pos = buscaBinaria(vetor, tamanho, valor);
                if (pos == -1) printf("Valor nao encontrado.\n");
                else printf("Valor encontrado na posicao %d.\n", pos);
                break;
            }

            case 3: {
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                if (removerElemento(vetor, &tamanho, valor))
                    printf("Valor removido.\n");
                else
                    printf("Valor nao encontrado.\n");
                break;
            }

            case 4: {
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                if (inserirOrdenado(vetor, &tamanho, capacidade, valor))
                    printf("Valor inserido com sucesso.\n");
                else
                    printf("Falha: vetor cheio.\n");
                break;
            }

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}

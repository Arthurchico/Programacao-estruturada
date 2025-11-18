#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int numero;
    char nome[50];
    char cpf[15];
    char telefone[20];
    float saldo;
} Conta;

int buscarConta(Conta cad[], int qtd, int numero);
void cadastrarConta(Conta cad[], int *qtd, int numero);
void consultarSaldo(Conta cad[], int qtd, int numero);
void depositar(Conta cad[], int qtd, int numero);
void sacar(Conta cad[], int qtd, int numero);
void listarContas(Conta cad[], int qtd);

int buscarConta(Conta cad[], int qtd, int numero) {
    if (qtd == 0)
        return -1;

    for (int i = 0; i < qtd; i++)
        if (cad[i].numero == numero)
            return i;

    return -2;
}

void cadastrarConta(Conta cad[], int *qtd, int numero) {
    if (*qtd >= MAX) {
        printf("Cadastro cheio!\n");
        return;
    }

    int pos = buscarConta(cad, *qtd, numero);

    if (pos >= 0) {
        printf("Erro: Numero de conta ja cadastrado!\n");
        return;
    }

    Conta nova;
    nova.numero = numero;

    printf("Nome do cliente: ");
    fflush(stdin);
    fgets(nova.nome, 50, stdin);
    nova.nome[strcspn(nova.nome, "\n")] = '\0';

    printf("CPF: ");
    fgets(nova.cpf, 15, stdin);
    nova.cpf[strcspn(nova.cpf, "\n")] = '\0';

    printf("Telefone: ");
    fgets(nova.telefone, 20, stdin);
    nova.telefone[strcspn(nova.telefone, "\n")] = '\0';

    printf("Saldo inicial: ");
    scanf("%f", &nova.saldo);

    cad[*qtd] = nova;
    (*qtd)++;

    printf("Conta cadastrada com sucesso!\n");
}

void consultarSaldo(Conta cad[], int qtd, int numero) {
    int pos = buscarConta(cad, qtd, numero);

    if (pos >= 0)
        printf("Saldo da conta %d = R$ %.2f\n", numero, cad[pos].saldo);
    else
        printf("Conta nao cadastrada!\n");
}

void depositar(Conta cad[], int qtd, int numero) {
    int pos = buscarConta(cad, qtd, numero);

    if (pos < 0) {
        printf("Conta nao cadastrada!\n");
        return;
    }

    float valor;
    printf("Valor do deposito: ");
    scanf("%f", &valor);

    if (valor < 0) {
        printf("Valor invalido!\n");
        return;
    }

    cad[pos].saldo += valor;
    printf("Deposito realizado com sucesso!\n");
}

void sacar(Conta cad[], int qtd, int numero) {
    int pos = buscarConta(cad, qtd, numero);

    if (pos < 0) {
        printf("Conta nao cadastrada!\n");
        return;
    }

    float valor;
    printf("Valor do saque: ");
    scanf("%f", &valor);

    if (valor < 0) {
        printf("Valor invalido!\n");
        return;
    }

    if (cad[pos].saldo >= valor) {
        cad[pos].saldo -= valor;
        printf("Saque realizado com sucesso!\n");
    } else {
        printf("Saldo insuficiente!\n");
    }
}

void listarContas(Conta cad[], int qtd) {
    if (qtd == 0) {
        printf("Nenhuma conta cadastrada.\n");
        return;
    }

    printf("\n--- LISTA DE CONTAS ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("\nConta: %d\n", cad[i].numero);
        printf("Nome : %s\n", cad[i].nome);
        printf("Telefone: %s\n", cad[i].telefone);
    }
}

int main() {
    Conta corrente[MAX], poupanca[MAX];
    int qtdCorrente = 0, qtdPoupanca = 0;
    int tipo, op, numero;

    while (1) {
        printf("\n--- MENU DO BANCO ---\n");
        printf("1 - Conta Corrente\n");
        printf("2 - Conta Poupanca\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &tipo);

        if (tipo == 0) break;

        Conta *cad = (tipo == 1 ? corrente : poupanca);
        int *qtd = (tipo == 1 ? &qtdCorrente : &qtdPoupanca);

        printf("\n1 - Cadastrar conta\n");
        printf("2 - Consultar saldo\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Listar contas\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Numero da nova conta: ");
                scanf("%d", &numero);
                cadastrarConta(cad, qtd, numero);
                break;

            case 2:
                printf("Numero da conta: ");
                scanf("%d", &numero);
                consultarSaldo(cad, *qtd, numero);
                break;

            case 3:
                printf("Numero da conta: ");
                scanf("%d", &numero);
                depositar(cad, *qtd, numero);
                break;

            case 4:
                printf("Numero da conta: ");
                scanf("%d", &numero);
                sacar(cad, *qtd, numero);
                break;

            case 5:
                listarContas(cad, *qtd);
                break;

            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}
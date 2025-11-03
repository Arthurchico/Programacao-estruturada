#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 40

int main(){

typedef struct{

    int codigo;
    char descricao[100];
    double valor_unitario;
    int quantidade_estoque;
} Produto;

void cadastrar_produto(Produto produtos[], int *qtd_produtos){
    if (*qtd_produtos >= MAX_PRODUTOS){

        printf("Erro: Estoque de produtos cheio/n");
        return;
    }



}

int main()

Produto produtos[MAX_PRODUTOS];

}
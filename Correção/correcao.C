#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 100

struct Categoria {
    int codigo;
    char nome[50];
};

struct Produto {
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria; 
    int preco; 
};

void cadastrarCategoria(struct Categoria v[], int *qtd);
void imprimirCategorias(struct Categoria v[], int qtd);
void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias);
void selectionSortPorDescricao(struct Produto v[], int qtd);
void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x);


static void trim_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') s[len-1] = '\0';
}

static int encontraNomeCategoriaPorCodigo(struct Categoria vc[], int qtdCategorias, int codigo) {
    for (int i = 0; i < qtdCategorias; ++i) {
        if (vc[i].codigo == codigo) return i;
    }
    return -1;
}



void cadastrarCategoria(struct Categoria v[], int *qtd) {
    if (*qtd >= TAM) {
        printf("Não é possível cadastrar: vetor de categorias cheio (capacidade %d).\n", TAM);
        return;
    }

    struct Categoria nova;
    printf("Digite o codigo da nova categoria: ");
    if (scanf("%d", &nova.codigo) != 1) {
    
        int c;
        while ((c = getchar()) != EOF && c != '\n');
        printf("Entrada invalida.\n");
        return;
    }
    
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n');

    
    for (int i = 0; i < *qtd; ++i) {
        if (v[i].codigo == nova.codigo) {
            printf("Codigo ja existe. Cadastro cancelado.\n");
            return;
        }
    }

    printf("Digite o nome da categoria: ");
    if (fgets(nova.nome, sizeof(nova.nome), stdin) == NULL) {
        printf("Erro lendo nome.\n");
        return;
    }
    trim_newline(nova.nome);

    
    v[*qtd] = nova;
    *qtd = *qtd + 1;
    printf("Categoria cadastrada com sucesso.\n");
}

void imprimirCategorias(struct Categoria v[], int qtd) {
    if (qtd <= 0) {
        printf("Nenhuma categoria cadastrada.\n");
        return;
    }
    printf("Lista de categorias:\n");
    for (int i = 0; i < qtd; ++i) {
        printf("Codigo: %d | Nome: %s\n", v[i].codigo, v[i].nome);
    }
}

void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias) {
    if (qtdProdutos <= 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtdProdutos; ++i) {
        int idxCat = encontraNomeCategoriaPorCodigo(vc, qtdCategorias, vp[i].categoria);
        const char *nomeCat = (idxCat >= 0) ? vc[idxCat].nome : "Categoria nao encontrada";

        double precoReal = vp[i].preco / 100.0; 
        printf("----------------------------------------------------\n");
        printf("Codigo: %d\n", vp[i].codigo);
        printf("Titulo: %s\n", vp[i].titulo);
        printf("Descricao: %s\n", vp[i].descricao);
        printf("Categoria: %s\n", nomeCat);
        printf("Preco: R$ %.2f\n", precoReal);
    }
    printf("----------------------------------------------------\n");
}

void selectionSortPorDescricao(struct Produto v[], int qtd) {
    if (qtd <= 1) return;
    for (int i = 0; i < qtd - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < qtd; ++j) {
            if (strcmp(v[j].descricao, v[min_idx].descricao) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            struct Produto tmp = v[i];
            v[i] = v[min_idx];
            v[min_idx] = tmp;
        }
    }
}


void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x) {
    int left = 0, right = qtd - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(x, v[mid].descricao);
        if (cmp == 0) {

            double precoReal = v[mid].preco / 100.0;
            printf("Produto encontrado:\n");
            printf("Codigo: %d\n", v[mid].codigo);
            printf("Titulo: %s\n", v[mid].titulo);
            printf("Descricao: %s\n", v[mid].descricao);
            printf("Categoria (codigo): %d\n", v[mid].categoria);
            printf("Preco: R$ %.2f\n", precoReal);
            return;
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("Descricao '%s' nao encontrada entre os produtos.\n", x);
}


int main(void) {
    struct Categoria categorias[TAM];
    int qtdCategorias = 0;

    struct Produto produtos[TAM];
    int qtdProdutos = 0;


    categorias[0].codigo = 10;
    strncpy(categorias[0].nome, "Bebidas", sizeof(categorias[0].nome));
    categorias[1].codigo = 20;
    strncpy(categorias[1].nome, "Lanches", sizeof(categorias[1].nome));
    qtdCategorias = 2;


    produtos[0].codigo = 1;
    strncpy(produtos[0].titulo, "Coca-Cola 2L", sizeof(produtos[0].titulo));
    strncpy(produtos[0].descricao, "Refrigerante cola", sizeof(produtos[0].descricao));
    produtos[0].categoria = 10;
    produtos[0].preco = 895;

    produtos[1].codigo = 2;
    strncpy(produtos[1].titulo, "Pão de Queijo", sizeof(produtos[1].titulo));
    strncpy(produtos[1].descricao, "Pao de queijo fresco", sizeof(produtos[1].descricao));
    produtos[1].categoria = 20;
    produtos[1].preco = 450;

    produtos[2].codigo = 3;
    strncpy(produtos[2].titulo, "Suco de Laranja", sizeof(produtos[2].titulo));
    strncpy(produtos[2].descricao, "Suco natural laranja", sizeof(produtos[2].descricao));
    produtos[2].categoria = 10;
    produtos[2].preco = 599;

    qtdProdutos = 3;

    printf("Categorias iniciais:\n");
    imprimirCategorias(categorias, qtdCategorias);

    printf("\nProdutos antes da ordenacao:\n");
    imprimirProdutos(produtos, qtdProdutos, categorias, qtdCategorias);

    printf("\nOrdenando produtos por descricao...\n");
    selectionSortPorDescricao(produtos, qtdProdutos);

    printf("\nProdutos apos ordenacao:\n");
    imprimirProdutos(produtos, qtdProdutos, categorias, qtdCategorias);


    char busca[256];
    printf("\nDigite a descricao exata a buscar (ex: 'Suco natural laranja'):\n");
    if (fgets(busca, sizeof(busca), stdin)) {
        trim_newline(busca);
        buscaBinariaPorDescricao(produtos, qtdProdutos, busca);
    }

    return 0;
}

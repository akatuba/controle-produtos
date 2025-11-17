#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define TAM 20

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

// --------- FUNÇÃO PARA LER ARQUIVO ---------
void lerArquivo(Produto produtos[], int *n) {
    FILE *f = fopen("produtos.txt", "r");

    if (!f) {
        printf("Erro ao abrir arquivo produtos.txt\n");
        return;
    }

    int i = 0;
    while (i < TAM && fscanf(f, "%d %s %f %d",
           &produtos[i].codigo,
           produtos[i].nome,
           &produtos[i].preco,
           &produtos[i].quantidade) != EOF) {
        i++;
    }

    *n = i;
    fclose(f);
}

// --------- IMPRIMIR PRODUTOS ---------
void imprimirProdutos(Produto produtos[], int n) {
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < n; i++) {
        printf("Código: %d | Nome: %s | Preço: %.2f | Quant.: %d\n",
               produtos[i].codigo,
               produtos[i].nome,
               produtos[i].preco,
               produtos[i].quantidade);
    }
}

// --------- ADICIONAR PRODUTO ---------
void adicionarProduto(Produto produtos[], int *n) {
    if (*n >= MAX) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto novo;

    printf("Código: ");
    scanf("%d", &novo.codigo);

    printf("Nome (sem espaço): ");
    scanf("%s", novo.nome);

    printf("Preço: ");
    scanf("%f", &novo.preco);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    produtos[*n] = novo;
    (*n)++;

    printf("Produto adicionado!\n");
}

// --------- BUSCAR POR CÓDIGO ---------
void buscarPorCodigo(Produto produtos[], int n) {
    int cod;
    printf("Digite o código: ");
    scanf("%d", &cod);

    for (int i = 0; i < n; i++) {
        if (produtos[i].codigo == cod) {
            printf("\nEncontrado!\n");
            printf("Nome: %s | Preço: %.2f | Quant.: %d\n",
                   produtos[i].nome,
                   produtos[i].preco,
                   produtos[i].quantidade);
            return;
        }
    }

    printf("Produto não encontrado.\n");
}

// --------- ORDENAR POR PREÇO ---------
void ordenarPorPreco(Produto produtos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (produtos[j].preco > produtos[j + 1].preco) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("\nProdutos ordenados por preço!\n");
    imprimirProdutos(produtos, n);
}

// --------- MENU INTELIGENTE ---------
int lerOpcao() {
    char entrada[10];
    printf("Escolha: ");
    scanf("%s", entrada);

    // Simbolos do PDF do professor
    if (strcmp(entrada, "-.") == 0)
        return -1;

    if (strcmp(entrada, "/.") == 0 || strcmp(entrada, "/") == 0)
        return 2;

    // Tentar converter para número
    char *end;
    int val = strtol(entrada, &end, 10);

    // Se não for número válido
    if (*end != '\0') {
        printf("Entrada inválida! Digite números, -., ou /.\n");
        return 999; // invalida
    }

    return val;
}

// --------- MAIN ---------
int main() {
    Produto produtos[MAX];
    int n = 0;
    int opcao;

    lerArquivo(produtos, &n);

    do {
        printf("\n--- MENU ---\n");
        printf("-. Adicionar produto\n");
        printf("/. Buscar por código\n");
        printf("0. Imprimir produtos\n");
        printf("1. Ordenar por preço\n");
        printf("3. Sair\n");

        opcao = lerOpcao();

        switch (opcao) {
            case -1:
                adicionarProduto(produtos, &n);
                break;
            case 2:
                buscarPorCodigo(produtos, n);
                break;
            case 0:
                imprimirProdutos(produtos, n);
                break;
            case 1:
                ordenarPorPreco(produtos, n);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            case 999:
                // entrada inválida — apenas repete o menu
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 3);

    return 0;
}

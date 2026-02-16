#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// STRUCT ITEM (MOCHILA DO JOGADOR)
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// VARIÁVEIS GLOBAIS
Item mochila[MAX_ITENS];
int totalItens = 0;

// FUNÇÕES
void inserirItem();
void removerItem();
void listarItens();
void buscarItem();

// FUNÇÃO PRINCIPAL
int main() {
    int opcao;

    do {
        printf("\n===== SISTEMA DE MOCHILA DO JOGADOR =====\n");
        printf("1 - Cadastrar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item pelo nome\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

// FUNÇÃO PARA INSERIR ITEM
void inserirItem() {
    if (totalItens == MAX_ITENS) {
        printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    printf("\n--- Cadastro de Item ---\n");

    printf("Nome do item: ");
    scanf("%s", mochila[totalItens].nome);

    printf("Tipo do item (arma, municao, cura): ");
    scanf("%s", mochila[totalItens].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[totalItens].quantidade);

    totalItens++;

    printf("Item cadastrado com sucesso!\n");
    listarItens();
}

// FUNÇÃO PARA REMOVER ITEM
void removerItem() {
    if (totalItens == 0) {
        printf("A mochila esta vazia!\n");
        return;
    }

    char nomeBusca[30];
    int pos = -1;

    printf("\nDigite o nome do item a remover: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Item nao encontrado!\n");
        return;
    }

    for (int i = pos; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    totalItens--;

    printf("Item removido com sucesso!\n");
    listarItens();
}

// FUNÇÃO PARA LISTAR ITENS
void listarItens() {
    if (totalItens == 0) {
        printf("\nA mochila esta vazia.\n");
        return;
    }

    printf("\n--- ITENS NA MOCHILA ---\n");
    for (int i = 0; i < totalItens; i++) {
        printf("Item %d:\n", i + 1);
        printf("  Nome: %s\n", mochila[i].nome);
        printf("  Tipo: %s\n", mochila[i].tipo);
        printf("  Quantidade: %d\n", mochila[i].quantidade);
    }
}

// FUNÇÃO DE BUSCA SEQUENCIAL
void buscarItem() {
    if (totalItens == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    char nomeBusca[30];
    int encontrado = 0;

    printf("\nDigite o nome do item para buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado na mochila.\n");
    }
}

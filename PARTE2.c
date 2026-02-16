#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// STRUCTS
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No {
    Item dados;
    struct No* proximo;
} No;

typedef No* ListaEncadeada;

// VARIÁVEIS GLOBAIS
Item mochila[MAX_ITENS];
int totalItens = 0;

ListaEncadeada mochilaLista = NULL;

// PROTÓTIPOS
void inserirItem();
void removerItem();
void listarItens();
void buscarItemSequencial();

void inserirItemLista();
void removerItemLista();
void listarItensLista();
void buscarItemListaSequencial();

void ordenarVetor();
int buscarBinaria(const char* nome, int* comparacoes);


// FUNÇÃO PRINCIPAL
int main() {
    int opcao;

    do {
        printf("\n===== SISTEMA DE MOCHILA DO JOGADOR =====\n");
        printf("1 - Cadastrar item (Vetor)\n");
        printf("2 - Remover item (Vetor)\n");
        printf("3 - Listar itens (Vetor)\n");
        printf("4 - Buscar item (Sequencial - Vetor)\n");
        printf("5 - Ordenar mochila (Vetor)\n");
        printf("6 - Buscar item (Binaria - Vetor)\n");
        printf("7 - Cadastrar item (Lista Encadeada)\n");
        printf("8 - Remover item (Lista Encadeada)\n");
        printf("9 - Listar itens (Lista Encadeada)\n");
        printf("10 - Buscar item (Sequencial - Lista Encadeada)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItemSequencial(); break;
            case 5: ordenarVetor(); break;
            case 6: {
                char nome[30];
                int comparacoes = 0;
                printf("Nome do item para busca binaria: ");
                scanf("%s", nome);
                buscarBinaria(nome, &comparacoes);
                printf("Comparacoes realizadas (binaria): %d\n", comparacoes);
                break;
            }
            case 7: inserirItemLista(); break;
            case 8: removerItemLista(); break;
            case 9: listarItensLista(); break;
            case 10: buscarItemListaSequencial(); break;
            case 0: printf("Saindo do sistema...\n"); break;
            default: printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

// IMPLEMENTAÇÃO - VETOR
void inserirItem() {
    if (totalItens == MAX_ITENS) {
        printf("Mochila cheia!\n");
        return;
    }

    printf("Nome: ");
    scanf("%s", mochila[totalItens].nome);

    printf("Tipo: ");
    scanf("%s", mochila[totalItens].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[totalItens].quantidade);

    totalItens++;
    printf("Item inserido no vetor.\n");
}

void removerItem() {
    char nome[30];
    printf("Nome do item a remover: ");
    scanf("%s", nome);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            totalItens--;
            printf("Item removido do vetor.\n");
            return;
        }
    }
    printf("Item nao encontrado no vetor.\n");
}

void listarItens() {
    for (int i = 0; i < totalItens; i++) {
        printf("%s (%s) x%d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

void buscarItemSequencial() {
    char nome[30];
    int comparacoes = 0;

    printf("Nome do item: ");
    scanf("%s", nome);

    for (int i = 0; i < totalItens; i++) {
        comparacoes++;
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Encontrado no vetor.\n");
            printf("Comparacoes: %d\n", comparacoes);
            return;
        }
    }
    printf("Nao encontrado no vetor.\n");
    printf("Comparacoes: %d\n", comparacoes);
}

// ORDENAÇÃO + BUSCA BINÁRIA (VETOR)
void ordenarVetor() {
    for (int i = 0; i < totalItens - 1; i++) {
        for (int j = 0; j < totalItens - i - 1; j++) {
            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
                Item temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }
    printf("Mochila (vetor) ordenada por nome.\n");
}

int buscarBinaria(const char* nome, int* comparacoes) {
    int inicio = 0, fim = totalItens - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        (*comparacoes)++;

        int cmp = strcmp(mochila[meio].nome, nome);
        if (cmp == 0) {
            printf("Encontrado na busca binaria.\n");
            return meio;
        } 
        else if (cmp > 0) {
            fim = meio - 1;
        } 
        else {
            inicio = meio + 1;
        }
    }
    printf("Nao encontrado na busca binaria.\n");
    return -1;
}

// IMPLEMENTAÇÃO - LISTA ENCADEADA
void inserirItemLista() {
    No* novo = (No*) malloc(sizeof(No));

    printf("Nome: ");
    scanf("%s", novo->dados.nome);

    printf("Tipo: ");
    scanf("%s", novo->dados.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    novo->proximo = mochilaLista;
    mochilaLista = novo;

    printf("Item inserido na lista encadeada.\n");
}

void removerItemLista() {
    char nome[30];
    printf("Nome do item a remover: ");
    scanf("%s", nome);

    No* atual = mochilaLista;
    No* anterior = NULL;

    while (atual != NULL && strcmp(atual->dados.nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Item nao encontrado na lista.\n");
        return;
    }

    if (anterior == NULL) {
        mochilaLista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Item removido da lista encadeada.\n");
}

void listarItensLista() {
    No* temp = mochilaLista;
    while (temp != NULL) {
        printf("%s (%s) x%d\n", temp->dados.nome, temp->dados.tipo, temp->dados.quantidade);
        temp = temp->proximo;
    }
}

void buscarItemListaSequencial() {
    char nome[30];
    int comparacoes = 0;

    printf("Nome do item: ");
    scanf("%s", nome);

    No* temp = mochilaLista;
    while (temp != NULL) {
        comparacoes++;
        if (strcmp(temp->dados.nome, nome) == 0) {
            printf("Encontrado na lista encadeada.\n");
            printf("Comparacoes: %d\n", comparacoes);
            return;
        }
        temp = temp->proximo;
    }

    printf("Nao encontrado na lista encadeada.\n");
    printf("Comparacoes: %d\n", comparacoes);
}

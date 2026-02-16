#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPONENTES 20

typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

Componente torre[MAX_COMPONENTES];
int total = 0;

// PROTÓTIPOS
void cadastrarComponentes();
void listarComponentes();

void bubbleSortNome(long *comparacoes, double *tempo);
void insertionSortTipo(long *comparacoes, double *tempo);
void selectionSortPrioridade(long *comparacoes, double *tempo);

int buscaBinariaNome(char *chave, long *comparacoes);

// FUNÇÃO PRINCIPAL
int main() {
    int op;
    char chave[30];
    long comparacoes;
    double tempo;

    do {
        printf("\n===== TORRE DE RESGATE - DESAFIO FINAL =====\n");
        printf("1 - Cadastrar componentes\n");
        printf("2 - Listar componentes\n");
        printf("3 - Ordenar por NOME (Bubble Sort)\n");
        printf("4 - Ordenar por TIPO (Insertion Sort)\n");
        printf("5 - Ordenar por PRIORIDADE (Selection Sort)\n");
        printf("6 - Buscar componente-chave (Binária - por nome)\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                cadastrarComponentes();
                break;

            case 2:
                listarComponentes();
                break;

            case 3:
                bubbleSortNome(&comparacoes, &tempo);
                printf("Comparacoes: %ld\n", comparacoes);
                printf("Tempo: %.6f segundos\n", tempo);
                listarComponentes();
                break;

            case 4:
                insertionSortTipo(&comparacoes, &tempo);
                printf("Comparacoes: %ld\n", comparacoes);
                printf("Tempo: %.6f segundos\n", tempo);
                listarComponentes();
                break;

            case 5:
                selectionSortPrioridade(&comparacoes, &tempo);
                printf("Comparacoes: %ld\n", comparacoes);
                printf("Tempo: %.6f segundos\n", tempo);
                listarComponentes();
                break;

            case 6:
                printf("Nome do componente-chave: ");
                scanf("%s", chave);
                if (buscaBinariaNome(chave, &comparacoes) != -1)
                    printf("Componente-chave encontrado! Torre desbloqueada!\n");
                else
                    printf("Componente-chave NAO encontrado!\n");

                printf("Comparacoes na busca: %ld\n", comparacoes);
                break;

            case 0:
                printf("Evacuacao concluida. Fim de jogo.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 0);

    return 0;
}

// ================== FUNÇÕES ==================

void cadastrarComponentes() {
    if (total >= MAX_COMPONENTES) {
        printf("Limite maximo atingido!\n");
        return;
    }

    printf("Nome: ");
    scanf("%s", torre[total].nome);

    printf("Tipo: ");
    scanf("%s", torre[total].tipo);

    printf("Prioridade (1-10): ");
    scanf("%d", &torre[total].prioridade);

    total++;
    printf("Componente cadastrado!\n");
}

void listarComponentes() {
    printf("\n=== COMPONENTES DA TORRE ===\n");
    for (int i = 0; i < total; i++) {
        printf("%d. %s | %s | Prioridade: %d\n",
               i + 1,
               torre[i].nome,
               torre[i].tipo,
               torre[i].prioridade);
    }
}

// ORDENAÇÕES

void bubbleSortNome(long *comparacoes, double *tempo) {
    clock_t inicio = clock();
    *comparacoes = 0;

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            (*comparacoes)++;
            if (strcmp(torre[j].nome, torre[j + 1].nome) > 0) {
                Componente tmp = torre[j];
                torre[j] = torre[j + 1];
                torre[j + 1] = tmp;
            }
        }
    }

    clock_t fim = clock();
    *tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void insertionSortTipo(long *comparacoes, double *tempo) {
    clock_t inicio = clock();
    *comparacoes = 0;

    for (int i = 1; i < total; i++) {
        Componente chave = torre[i];
        int j = i - 1;

        while (j >= 0) {
            (*comparacoes)++;
            if (strcmp(torre[j].tipo, chave.tipo) > 0) {
                torre[j + 1] = torre[j];
                j--;
            } else break;
        }
        torre[j + 1] = chave;
    }

    clock_t fim = clock();
    *tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void selectionSortPrioridade(long *comparacoes, double *tempo) {
    clock_t inicio = clock();
    *comparacoes = 0;

    for (int i = 0; i < total - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < total; j++) {
            (*comparacoes)++;
            if (torre[j].prioridade < torre[menor].prioridade) {
                menor = j;
            }
        }
        Componente tmp = torre[i];
        torre[i] = torre[menor];
        torre[menor] = tmp;
    }

    clock_t fim = clock();
    *tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// BUSCA BINÁRIA

int buscaBinariaNome(char *chave, long *comparacoes) {
    int ini = 0, fim = total - 1;
    *comparacoes = 0;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        (*comparacoes)++;

        int cmp = strcmp(torre[meio].nome, chave);

        if (cmp == 0)
            return meio;
        else if (cmp > 0)
            fim = meio - 1;
        else
            ini = meio + 1;
    }
    return -1;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void imprimirLista(const char* titulo, int lista[], int n) {
    printf("    %s: [ ", titulo);
    for (int i = 0; i < n; i++) printf("%d ", lista[i]);
    printf("]\n");
}
void criar_lista_ordenada(int lista[], int n) { for (int i = 0; i < n; i++) lista[i] = i; }
void criar_lista_reversa(int lista[], int n) { for (int i = 0; i < n; i++) lista[i] = n - 1 - i; }
void criar_lista_aleatoria(int lista[], int n) { for (int i = 0; i < n; i++) lista[i] = rand() % n; }
void criar_lista_duplicatas(int lista[], int n) { for (int i = 0; i < n; i++) lista[i] = rand() % (n / 5 + 1); }

// (Contamos "movimentos" em vez de trocas)
void insertion_sort(int lista[], int n, long long* comparacoes, long long* movimentos) {
    int i, chave, j;
    *comparacoes = 0;
    *movimentos = 0;

    for (i = 1; i < n; i++) {
        chave = lista[i];
        j = i - 1;
        
        while (j >= 0) {
            (*comparacoes)++;
            if (lista[j] > chave) {
                lista[j + 1] = lista[j]; // Movimento (Shift)
                (*movimentos)++;
                j = j - 1;
            } else {
                break; // Encontrou o local
            }
        }
        lista[j + 1] = chave; // Insere a chave
        (*movimentos)++; // Conta a inserção final
    }
}

// --- Funções de Tarefa ---

void executar_demo_aovivo(int n_demo) {
    printf("\n--- DEMONSTRAÇÃO AO VIVO (N=%d) ---\n", n_demo);
    int demo_ordenado[10]   = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int demo_reverso[10]    = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int demo_aleatorio[10]  = {5, 1, 8, 3, 9, 0, 4, 7, 2, 6};
    int demo_duplicatas[10] = {2, 1, 5, 1, 5, 2, 1, 5, 2, 1};
    long long comps, movs; 

    printf("\nCenário 1: Lista Ordenada\n");
    imprimirLista("Antes", demo_ordenado, n_demo);
    insertion_sort(demo_ordenado, n_demo, &comps, &movs);
    imprimirLista("Depois", demo_ordenado, n_demo);

    printf("\nCenário 2: Lista Reversa\n");
    imprimirLista("Antes", demo_reverso, n_demo);
    insertion_sort(demo_reverso, n_demo, &comps, &movs);
    imprimirLista("Depois", demo_reverso, n_demo);

    printf("\nCenário 3: Lista Aleatória\n");
    imprimirLista("Antes", demo_aleatorio, n_demo);
    insertion_sort(demo_aleatorio, n_demo, &comps, &movs);
    imprimirLista("Depois", demo_aleatorio, n_demo);

    printf("\nCenário 4: Lista com Duplicatas\n");
    imprimirLista("Antes", demo_duplicatas, n_demo);
    insertion_sort(demo_duplicatas, n_demo, &comps, &movs);
    imprimirLista("Depois", demo_duplicatas, n_demo);
}

void executar_mini_experimento(int n_exp) {
    printf("\n--- MINI-EXPERIMENTO (N=%d) ---\n", n_exp);
    long long comps, movs;

    int* lista = (int*)malloc(n_exp * sizeof(int));
    
    criar_lista_ordenada(lista, n_exp);
    insertion_sort(lista, n_exp, &comps, &movs);
    printf("  Cenário Ordenado:   %12lld comparações, %12lld movimentos\n", comps, movs);

    criar_lista_reversa(lista, n_exp);
    insertion_sort(lista, n_exp, &comps, &movs);
    printf("  Cenário Reverso:    %12lld comparações, %12lld movimentos\n", comps, movs);
    
    criar_lista_aleatoria(lista, n_exp);
    insertion_sort(lista, n_exp, &comps, &movs);
    printf("  Cenário Aleatório:  %12lld comparações, %12lld movimentos\n", comps, movs);
    
    criar_lista_duplicatas(lista, n_exp);
    insertion_sort(lista, n_exp, &comps, &movs);
    printf("  Cenário Duplicatas: %12lld comparações, %12lld movimentos\n", comps, movs);
    
    free(lista);
}


int main() {
    srand(time(NULL));
    int escolha = -1;
    
    while (escolha != 0) {
        printf("\n--------------------------------------\n");
        printf("   ALGORITMO: INSERTION SORT\n");
        printf("-----------------------------------------\n");
        printf("Escolha uma opção:\n");
        printf("  1 - Executar Demonstração ao Vivo (N=10)\n");
        printf("  2 - Executar Mini-Experimento (N=1000)\n");
        printf("  0 - Sair\n");
        printf("Opção: ");
        
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                executar_demo_aovivo(10);
                break;
            case 2:
                executar_mini_experimento(1000);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}

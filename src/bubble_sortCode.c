#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- Funções Auxiliares ---
void trocar(int* a, int* b) {
    int temp = *a; *a = *b; *b = temp;
}
void imprimirLista(const char* titulo, int lista[], int n) {
    printf("    %s: [ ", titulo);
    for (int i = 0; i < n; i++) printf("%d ", lista[i]);
    printf("]\n");
}
void criar_lista_ordenada(int lista[], int n) { for (int i = 0; i < n; i++) lista[i] = i; }
void criar_lista_reversa(int lista[], int n) { for (int i = 0; i < n; i++) lista[i] = n - 1 - i; }
void criar_lista_aleatoria(int lista[], int n) { for (int i = 0; i < n; i++) lista[i] = rand() % n; }
void criar_lista_duplicatas(int lista[], int n) { for (int i = 0; i < n; i++) lista[i] = rand() % (n / 5 + 1); }

// --- Algoritmo: Bubble Sort (Instrumentado) ---
void bubble_sort(int lista[], int n, long long* comparacoes, long long* trocas) {
    int i, j;
    int houve_troca;
    *comparacoes = 0;
    *trocas = 0;
    
    for (i = 0; i < n - 1; i++) {
        houve_troca = 0;
        for (j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (lista[j] > lista[j + 1]) {
                trocar(&lista[j], &lista[j + 1]);
                (*trocas)++;
                houve_troca = 1;
            }
        }
        if (houve_troca == 0) break;
    }
}

// --- Funções de Tarefa (Exigidas pelo Trabalho) ---

void executar_demo_aovivo(int n_demo) {
    printf("\n--- DEMONSTRAÇÃO AO VIVO (N=%d) ---\n", n_demo);
    int demo_ordenado[10]   = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int demo_reverso[10]    = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int demo_aleatorio[10]  = {5, 1, 8, 3, 9, 0, 4, 7, 2, 6};
    int demo_duplicatas[10] = {2, 1, 5, 1, 5, 2, 1, 5, 2, 1};
    long long comps, trocs; // Contadores (não exibidos na demo)

    printf("\nCenário 1: Lista Ordenada\n");
    imprimirLista("Antes", demo_ordenado, n_demo);
    bubble_sort(demo_ordenado, n_demo, &comps, &trocs);
    imprimirLista("Depois", demo_ordenado, n_demo);

    printf("\nCenário 2: Lista Reversa\n");
    imprimirLista("Antes", demo_reverso, n_demo);
    bubble_sort(demo_reverso, n_demo, &comps, &trocs);
    imprimirLista("Depois", demo_reverso, n_demo);

    printf("\nCenário 3: Lista Aleatória\n");
    imprimirLista("Antes", demo_aleatorio, n_demo);
    bubble_sort(demo_aleatorio, n_demo, &comps, &trocs);
    imprimirLista("Depois", demo_aleatorio, n_demo);

    printf("\nCenário 4: Lista com Duplicatas\n");
    imprimirLista("Antes", demo_duplicatas, n_demo);
    bubble_sort(demo_duplicatas, n_demo, &comps, &trocs);
    imprimirLista("Depois", demo_duplicatas, n_demo);
}

void executar_mini_experimento(int n_exp) {
    printf("\n--- MINI-EXPERIMENTO (N=%d) ---\n", n_exp);
    long long comps, trocs;

    int* lista = (int*)malloc(n_exp * sizeof(int));
    
    criar_lista_ordenada(lista, n_exp);
    bubble_sort(lista, n_exp, &comps, &trocs);
    printf("  Cenário Ordenado:   %12lld comparações, %12lld trocas\n", comps, trocs);

    criar_lista_reversa(lista, n_exp);
    bubble_sort(lista, n_exp, &comps, &trocs);
    printf("  Cenário Reverso:    %12lld comparações, %12lld trocas\n", comps, trocs);
    
    criar_lista_aleatoria(lista, n_exp);
    bubble_sort(lista, n_exp, &comps, &trocs);
    printf("  Cenário Aleatório:  %12lld comparações, %12lld trocas\n", comps, trocs);
    
    criar_lista_duplicatas(lista, n_exp);
    bubble_sort(lista, n_exp, &comps, &trocs);
    printf("  Cenário Duplicatas: %12lld comparações, %12lld trocas\n", comps, trocs);
    
    free(lista);
}


int main() {
    srand(time(NULL));
    int escolha = -1;
    
    while (escolha != 0) {
        printf("---------------------------------\n");
        printf("   ALGORITMO: BUBBLE SORT\n");
        printf("---------------------------------\n");
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
                executar_mini_experimento(1000); // (n=100l)
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

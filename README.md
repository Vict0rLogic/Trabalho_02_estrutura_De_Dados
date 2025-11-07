# Trabalho_02_estrutura_De_Dados 
Este repositório contém os códigos de demonstração para o seminário de Estrutura de Dados I, conforme as especificações do Trabalho passado pelo professor.

## Descrição

O repositório está "particionado" em **5 programas C independentes**, um para cada algoritmo solicitado. Esta abordagem foi usada pela sua simplicidade, permitindo que cada algoritmo seja compilado e executado individualmente.

* `bubble_sortCode.c`
* `selection_sort_Code.c`
* `insertion_sort_Code.c`
* `quick_sort_Code.c`
* `merge_sort_Code.c`

Cada ficheiro `.c` é um programa autónomo que cumpre **todos** os requisitos de código do trabalho:
1.  **Demonstração ao Vivo:** Ordena e imprime uma lista de N=10 nos 4 cenários (ordenado, reverso, aleatório, duplicados).
2.  **Mini-Experimento:** Executa e calcula os resultados para N=1000 nos mesmos 4 cenários.
3.  **Instrumentação:** O código está instrumentado para contar e exibir o número exato de **comparações** e **trocas/movimentos**.

## Como Compilar e Executar (Usando Dev C++)

1.  Abra o Dev C++.
2.  Crie um novo "Arquivo Fonte" (`Ctrl+N`).
3.  Copie e cole o conteúdo de **um** dos 5 arquivos `.c` (por exemplo, `bubble_sort_completo.c`).
4.  Salve o arquivo como um "C source file" (ex: `bubble.c`).
5.  Pressione **F11** (ou vá em `Executar` -> `Compilar e Executar`).
6.  O programa rodará no console, exibindo a Demonstração (N=10) e a tabela do Mini-Experimento (N=1000).
7.  Repita o processo para os outros 4 algoritmos.

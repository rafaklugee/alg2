#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"
// MERGESORT - OK
// QUICKSORT - OK
// HEAPSORT - OK

// MERGESORTSR - FAZER
// QUICKSORTSR - OK
// HEAPSORTSR - OK
int main() {
    char nome[MAX_CHAR];
    int numComp;
    int escolha;

    // Inserir o tamanho do vetor que se quer testar:
    int64_t tamVetor = 100000;                            
    int* vetor = (int*)malloc(tamVetor * sizeof(int));    


    if (vetor == NULL) {
        printf("Erro ao alocar memória!");
        return 1;
    }

    // Gerando vetor randômico
    //srand(time(NULL));
    //for (size_t i = 0; i < tamVetor; i++)
    //    vetor[i] = rand() % 100;

    // Gerando vetor inteiramente decrescente
    for (size_t i = 0; i < tamVetor; i++)
        vetor[i] = tamVetor - i;

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    printf ("Voce esta testando um vetor de %ld posicoes!\n", tamVetor);

        menu();
        scanf ("%d", &escolha);
    
        switch(escolha) {
            case 0:
            // Saindo do programa
            printf ("\nVoce optou por sair do programa.\n");
            free(vetor);
            return 0;

            case 1:
            // Fazendo testes para o MergeSort Recursivo
            numComp = mergeSort (vetor, tamVetor);
            printf ("\nMergeSort Recursivo");
            printf ("\nO numero de comparacoes foi de: %d\n", numComp);
            break;
            // Fim do MergeSort Recursivo

            case 2:
            // Fazendo testes para o QuickSort Recursivo
            numComp = quickSort (vetor, tamVetor);
            printf ("\nQuickSort Recursivo");
            printf ("\nO numero de comparacoes foi de: %d\n", numComp);
            break;
            // Fim do QuickSort Recursivo

            case 3:
            // Fazendo testes para o HeapSort Recursivo
            numComp = heapSort (vetor, tamVetor);
            printf ("\nHeapSort Recursivo");
            printf ("\nO numero de comparacoes foi de: %d\n", numComp);
            break;
            // Fim do HeapSort Recursivo

            case 4:
            // Fazendo testes para o MergeSort Sem Recursao
            numComp = mergeSortSR (vetor, tamVetor);
            printf ("\nMergeSort Sem Recursao");
            printf ("\nO numero de comparacoes foi de: %d\n", numComp);
            break;
            // Fim do MergeSort Sem Recursao

            case 5:
            // Fazendo testes para o QuickSort Sem Recursao
            numComp = quickSortSR (vetor, tamVetor);
            printf ("\nQuickSort Sem Recursao");
            printf ("\nO numero de comparacoes foi de: %d\n", numComp);
            break;
            // Fim do QuickSort Sem Recursao

            case 6:
            // Fazendo testes para o HeapSort Sem Recursao
            numComp = heapSortSR (vetor, tamVetor);
            printf ("\nHeapSort Sem Recursao");
            printf ("\nO numero de comparacoes foi de: %d\n", numComp);
            break;
            // Fim do HeapSort Sem Recursao

            default:
                printf ("\nEscolha inválida!\n");
                break;
        }
            //mostravetor (vetor, tamVetor);
            //printf ("\n");

    free (vetor);
    return 0;
}

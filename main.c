#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"
// TROCAR OS INT POR UINT64_T - QUICKSORT
int main() {
    char nome[MAX_CHAR];
    int numComp;
    int escolha;

    // Inserir o tamanho do vetor que se quer testar:
    int64_t tamVetor = 100000;
    int* vetor = (int*)malloc(tamVetor * sizeof(int));

    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    for (size_t i = 0; i < tamVetor; i++)
       vetor[i] = tamVetor - i; // Estou testando vetores inteiramente decrescentes!

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    menu();
    scanf ("%d", &escolha);

    switch(escolha) {
        case 0:
        // Saindo do programa
        printf ("\nVoce optou por sair do programa.\n");
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
    }

    //numComp = mergeSort(vetor, 3);
    //printf("NumComp: %d\n", numComp);
    //numComp = quickSort(vetor, 3);
    //printf("NumComp: %d\n", numComp);
    //numComp = heapSort(vetor, 3);
    //printf("NumComp: %d\n", numComp);
    //numComp = mergeSortSR(vetor, 3);
    //printf("NumComp: %d\n", numComp);
    //numComp = quickSortSR(vetor, 3);
    //printf("NumComp: %d\n", numComp);
    //numComp = heapSortSR(vetor, 3);
    //printf("NumComp: %d\n", numComp);

    // Se deseja mostrar o vetor ordenado, descomentar
    //mostravetor (vetor, tamVetor);
    //printf ("\n");

    free(vetor);

    return 0;
}

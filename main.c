#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"
// FAZER HEAPSORTSR // ARRUMAR MERGE SEM RECURSAO // ARRUMAR COMPARACOES DO QUICKSORTSR
int main() {
    char nome[MAX_CHAR];
    int numComp;
    int escolha;

    // Inserir o tamanho do vetor que se quer testar:
    int64_t tamVetor = 10;                            
    int* vetor = (int*)malloc(tamVetor * sizeof(int));    


    if (vetor == NULL) {
        printf("Erro ao alocar memória!");
        return 1;
    }

    // Gerando vetor randômico
    srand(time(NULL));
    for (size_t i = 0; i < tamVetor; i++)
        vetor[i] = rand() % 100;

    // Gerando vetor inteiramente decrescente
    //for (size_t i = 0; i < tamVetor; i++)
    //    vetor[i] = tamVetor - i;

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    printf ("Voce esta testando um vetor de %li posicoes!\n", tamVetor);
    do {
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
                continue;
        }
            mostravetor (vetor, tamVetor);
            printf ("\n");

    } while (escolha != 0);

    //numComp = mergeSortSR(vetor, 3);
    //printf("NumComp: %d\n", numComp);

    free (vetor);
    return 0;
}

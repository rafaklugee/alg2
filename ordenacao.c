#include "ordenacao.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Rafael Ribeiro Kluge", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20244439; }

uint64_t merge (int vetor[], int inicio, int meio, int fim, uint64_t *numcomp) {
    int i, j, inicio1 = inicio, inicio2 = meio + 1, fim1 = meio, fim2 = fim; 
    int tamaux = (fim - inicio) + 1;
    int *vaux = malloc (tamaux * sizeof(int));
    uint64_t numcompmerge = 0;
    if (vaux != NULL) {
        for (i = 0; i < tamaux; i++) {
            numcompmerge++;
            if (inicio1 <= fim1 && inicio2 <= fim2) {
                if (vetor[inicio1] < vetor[inicio2]) {
                    vaux[i] = vetor[inicio1];
                    inicio1++;
                }
                else {
                    vaux[i] = vetor[inicio2];
                    inicio2++;
                }
            }
            else {
                if (inicio1 <= meio) {
                    vaux[i] = vetor[inicio1];
                    inicio1++;
                }
                else {
                    vaux[i] = vetor[inicio2];
                    inicio2++;
                }
            }
        }
        (*numcomp) += numcompmerge;
        for (j = 0; j < tamaux; j++) {
            vetor[inicio] = vaux[j];
            inicio++;
        }
    }
    free (vaux);
    return numcompmerge;
}

uint64_t auxiliarmergesort (int vetor[], int inicio, int fim, uint64_t *numcomp) {
    int meio;
    uint64_t numcompaux = 0;
    if (inicio < fim) {
        meio = (inicio + fim)/2;
        numcompaux += auxiliarmergesort (vetor, inicio, meio, numcomp);
        numcompaux += auxiliarmergesort (vetor, meio + 1, fim, numcomp);
        numcompaux += merge (vetor, inicio, meio, fim, numcomp);
    }
    return numcompaux;
}

uint64_t mergeSort(int vetor[], size_t tam) {
    uint64_t numcomp = 0;
    return auxiliarmergesort (vetor, 0, tam - 1, &numcomp);
}

uint64_t particionar (int vetor[], int inicio, int fim) {
    int i;
    int x = vetor[fim];
    int m = inicio;
        for (i = inicio; i <= fim - 1; i++) {
            if (vetor[i] <= x) {
                troca (vetor, m, i);
                m++;
            }
        }
    troca (vetor, m, fim);
    return m;
}

uint64_t quickSortAux (int vetor[], int inicio, int fim) {
    uint64_t numcompaux = 0;
    if (inicio >= fim)
        return numcompaux;
    int m = particionar (vetor, inicio, fim);
    numcompaux++;
    numcompaux += quickSortAux (vetor, inicio, m-1);
    numcompaux += quickSortAux (vetor, m+1, fim);

    return numcompaux;
}

uint64_t quickSort(int vetor[], size_t tam) {
    if (tam > 0)
        return quickSortAux (vetor, 0, tam - 1);
    return 0;
}

uint64_t max_heapify (int vetor[], int i, size_t tam) {
    int maior = i;
    int numcomp = 0;

    size_t esquerda = 2*i+1;
    size_t direita = 2*i+2;

    if ((esquerda <= tam) && (vetor[esquerda] > vetor[maior])) {
        maior = esquerda;
        numcomp++;
    }

    if ((direita <= tam) && (vetor[direita] > vetor[maior])) {
        maior = direita;
        numcomp++;
    }

    if (maior != i) {
        troca (vetor, i, maior);
        max_heapify (vetor, maior, tam);
    }
    return numcomp;
}

uint64_t construir_max_heap (int vetor[], size_t tam) {
    int i;
    int numcomp = 0;
    for (i = tam/2 - 1; i >= 0; i--)
        numcomp += max_heapify (vetor, i, tam - 1);
    return numcomp;
}

uint64_t heapSort(int vetor[], size_t tam) {
    int i;
    int numcomp = 0;
    numcomp += construir_max_heap (vetor, tam);
    for (i = tam - 1; i > 0; i--) {
        troca (vetor, 0, i);
        numcomp += max_heapify (vetor, 0, i-1);
    }
    return numcomp;
}
/*
uint64_t mergeSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t quickSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t heapSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}
*/

void menu () {
    printf ("(1) MergeSort Recursivo\n");
    printf ("(2) QuickSort Recursivo\n");
    printf ("(3) HeapSort Recursivo\n");
    printf ("(4) MergeSort Sem Recursao\n");
    printf ("(5) QuickSort Sem Recursao\n");
    printf ("(6) HeapSort Sem Recursao\n");
    printf ("(0) Sair do programa\n");
    printf ("Escolha uma opcao: ");
}

void mostravetor (int vetor[], size_t tam) {
    int i;
    printf ("O vetor eh:\t");
    for (i = 0; i < tam; i++) {
        printf ("%d\t", vetor[i]);
    }
}

void troca (int vetor[], size_t i, size_t m) {
    size_t temp;
    temp = vetor[i];
    vetor[i] = vetor[m];
    vetor[m] = temp;
}
#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#define MAX_CHAR 50

void getNome(char nome[]);

uint32_t getGRR();

uint64_t mergeSort(int vetor[], size_t tam);

uint64_t quickSort(int vetor[], size_t tam);

uint64_t heapSort(int vetor[], size_t tam);

uint64_t mergeSortSR(int vetor[], size_t tam);

uint64_t quickSortSR(int vetor[], size_t tam);

uint64_t heapSortSR(int vetor[], size_t tam);


// Funções Auxiliares
void menu ();

void mostravetor (int vetor[], size_t tam);

void troca (int vetor[], size_t i, size_t m);

uint64_t auxiliarmergesort (int vetor[], int inicio, int fim, uint64_t *numcomp);

uint64_t merge (int vetor[], int inicio, int meio, int fim, uint64_t *numcomp);

uint64_t particionar (int vetor[], int inicio, int fim, uint64_t *numcomppart);

uint64_t quickSortAux (int vetor[], int inicio, int fim, uint64_t *numcompaux);

uint64_t max_heapify (int vetor[], int i, size_t tam, uint64_t *numcompheapify);

uint64_t construir_max_heap (int vetor[], size_t tam, uint64_t *numcompcons);

uint64_t max_heapifySR (int vetor[], int i, size_t tam, uint64_t *numcompheapify);

uint64_t quickSortAuxSR (int vetor[], int inicio, int fim, uint64_t *numcompquickSR);

uint64_t construir_max_heapSR (int vetor[], size_t tam, uint64_t *numcompcons);

#endif
#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#define MAX_CHAR 50

// a função getNome deve colocar o seu nome no vetor
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR();

// Cada uma das funções deve ordenar o vetor passado como parâmetro

// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

uint64_t mergeSort(int vetor[], size_t tam);

uint64_t quickSort(int vetor[], size_t tam);

uint64_t heapSort(int vetor[], size_t tam);
/*
// As funções que terminam em SR são "Sem Recursão"
uint64_t mergeSortSR(int vetor[], size_t tam);uint64_t contruir_max_heap (int vetor[], size_t tam)

uint64_t quickSortSR(int vetor[], size_t tam);

uint64_t heapSortSR(int vetor[], size_t tam);
*/

// Funções Auxiliares
void menu ();

void mostravetor (int vetor[], size_t tam);

void troca (int vetor[], size_t i, size_t m);

uint64_t auxiliarmergesort (int vetor[], int inicio, int fim, uint64_t *numcomp);

uint64_t merge (int vetor[], int inicio, int meio, int fim, uint64_t *numcomp);

uint64_t particionar (int vetor[], int inicio, int fim);

uint64_t quickSortAux (int vetor[], int inicio, int fim);

uint64_t max_heapify (int vetor[], int i, size_t tam);

uint64_t construir_max_heap (int vetor[], size_t tam);

#endif  // ORDENACAO_H_
#include "ordenacao.h"
#include "pilha.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

void getNome(char nome[]) {
    strncpy(nome, "Rafael Ribeiro Kluge", MAX_CHAR);
    nome[MAX_CHAR - 1] = '\0';
}

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

uint64_t mergeSort (int vetor[], size_t tam) {
    uint64_t numcomp = 0;
    auxiliarmergesort (vetor, 0, tam - 1, &numcomp);
    return numcomp;
}

uint64_t mergeSortSR (int vetor[], size_t tam) {
    uint64_t numcompaux = 0;
    int l;

    for (l = 1; l < tam; l = 2 * l) {
        int i;
        for (i = 0; i < tam - l; i += 2 * l) {
            int esquerda = i;
            int meio = i + l - 1;
            int direita;
            if (i + 2 * l - 1 < tam)
                direita = i + 2 * l - 1;
            else
                direita = tam - 1;

            merge(vetor, esquerda, meio, direita, &numcompaux);
        }
    }

    return numcompaux;
}


uint64_t particionar (int vetor[], int inicio, int fim, uint64_t *numcomppart) {
    size_t i;
    int x = vetor[fim];
    size_t m = inicio;
        for (i = inicio; i < fim; i++) {
            (*numcomppart)++;
            if (vetor[i] <= x) {
                troca (vetor, m, i);
                m++;
            }
        }
    troca (vetor, m, fim);
    return m;
}

uint64_t quickSortAux (int vetor[], int inicio, int fim, uint64_t *numcompaux) {
    if (inicio >= fim)
        return (*numcompaux);
    size_t m = particionar (vetor, inicio, fim, numcompaux);
    quickSortAux (vetor, inicio, m-1, numcompaux);
    quickSortAux (vetor, m+1, fim, numcompaux);

    return (*numcompaux);
}

uint64_t quickSort(int vetor[], size_t tam) {
    uint64_t numcompquick = 0;
        return quickSortAux (vetor, 0, tam - 1, &numcompquick);
}

uint64_t max_heapify (int vetor[], int i, size_t tam, uint64_t *numcompheapify) {
    int maior = i;

    size_t esquerda = 2*i+1;
    size_t direita = 2*i+2;

    if (esquerda <= tam) {
        (*numcompheapify)++;
        if (vetor[esquerda] > vetor[maior])
        maior = esquerda;
    }
    
    if (direita <= tam) {
        (*numcompheapify)++;
        if (vetor[direita] > vetor[maior])
        maior = direita;
    }

    if (maior != i) {
        troca (vetor, i, maior);
        max_heapify (vetor, maior, tam, numcompheapify);
    }
    return (*numcompheapify);
}

uint64_t max_heapifySR (int vetor[], int i, size_t tam, uint64_t *numcompheapify) {
    int maior = i;

    size_t esquerda;
    size_t direita;

    while (1) {
        esquerda = 2*i+1;
        direita = 2*i+2;
        
        if (esquerda <= tam) {
            (*numcompheapify)++;
            if (vetor[esquerda] > vetor[maior])
            maior = esquerda;
        }
        
        if (direita <= tam) {
            (*numcompheapify)++;
            if (vetor[direita] > vetor[maior])
            maior = direita;
        }

        if (maior != i) {
            troca (vetor, i, maior);
            i = maior;
        }
        else
            break;
    }
    return (*numcompheapify);
}

uint64_t heapSortSR (int vetor[], size_t tam) {
    int i;
    uint64_t numcompheap = 0;
    construir_max_heapSR (vetor, tam, &numcompheap);
    for (i = tam - 1; i > 0; i--) {
        troca (vetor, 0, i);
        max_heapifySR (vetor, 0, i-1, &numcompheap);
    }
    return numcompheap;
}

uint64_t construir_max_heap (int vetor[], size_t tam, uint64_t *numcompcons) {
    int i;
    for (i = tam/2 - 1; i >= 0; i--)
        max_heapify (vetor, i, tam - 1, numcompcons);
    return (*numcompcons);
}

uint64_t construir_max_heapSR (int vetor[], size_t tam, uint64_t *numcompcons) {
    int i;
    for (i = tam/2 - 1; i >= 0; i--)
        max_heapifySR (vetor, i, tam - 1, numcompcons);
    return (*numcompcons);
}

uint64_t heapSort(int vetor[], size_t tam) {
    int i;
    uint64_t numcompheap = 0;
    construir_max_heap (vetor, tam, &numcompheap);
    for (i = tam - 1; i > 0; i--) {
        troca (vetor, 0, i);
        max_heapify (vetor, 0, i-1, &numcompheap);
    }
    return numcompheap;
}

uint64_t quickSortAuxSR (int vetor[], int inicio, int fim, uint64_t *numcompquickSR) {
    size_t m;
    TPilha *p = malloc(sizeof(TPilha));
    pilha_inicio(p);

    if (p == NULL) {
        printf ("\nErro ao alocar memória!");
        return 0;
    }

    empilhar (p, inicio);
    empilhar (p, fim);
    while (!pilha_vazia(p)) {
        fim = desempilhar (p);
        inicio = desempilhar (p);
        if (inicio < fim) {
            m = particionar (vetor, inicio, fim, numcompquickSR);
            empilhar (p, inicio);
            empilhar (p, m - 1);
            empilhar (p, m + 1);
            empilhar (p, fim);
        }
    }

    free(p);
    return (*numcompquickSR);
}

uint64_t quickSortSR(int vetor[], size_t tam) {
    uint64_t numcompquickSR = 0;
        quickSortAuxSR (vetor, 0, tam - 1, &numcompquickSR);
    return numcompquickSR;
}

void menu () {
    printf ("\nDas ordenacoes:\n");
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
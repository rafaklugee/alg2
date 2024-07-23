#ifndef PILHA_H_
#define PILHA_H_

#include <stddef.h>
#include <stdint.h>

#define MAXTAM 1048576

typedef struct {
    size_t item[MAXTAM];
    size_t topo;
} TPilha;

void pilha_inicio (TPilha *p);

uint64_t pilha_vazia (TPilha *p);

uint64_t pilha_cheia (TPilha *p);

void empilhar (TPilha *p, size_t x);

uint64_t desempilhar (TPilha *p);

#endif
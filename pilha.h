#ifndef PILHA_H_
#define PILHA_H_

#define MAXTAM 1048576

typedef struct {
    int item[MAXTAM];
    int topo;
} TPilha;

void pilha_inicio (TPilha *p);

int pilha_vazia (TPilha *p);

int pilha_cheia (TPilha *p);

void empilhar (TPilha *p, int x);

int desempilhar (TPilha *p);

#endif
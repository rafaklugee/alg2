#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

void pilha_inicio (TPilha *p) {
    p->topo = -1;
}

uint64_t pilha_vazia (TPilha *p) {
    if (p->topo == -1)
        return 1;
    else
        return 0;
}

uint64_t pilha_cheia (TPilha *p) {
    if (p->topo == MAXTAM - 1)
        return 1;
    else
        return 0;
}

void empilhar (TPilha *p, size_t x) {
    if (pilha_cheia(p)) {
        printf ("Pilha cheia!\n");
    }
    else {
        p->topo++;
        p->item[p->topo] = x;
    }
}

uint64_t desempilhar (TPilha *p) {
    size_t aux;
    if (pilha_vazia(p)) {
        printf ("Pilha vazia!\n");
        return 0;
    }
    else {
        aux = p->item[p->topo];
        p->topo--;
        return aux;
    }
}
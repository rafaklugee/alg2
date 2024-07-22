#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void pilha_inicio (TPilha *p) {
    p->topo = -1;
}

int pilha_vazia (TPilha *p) {
    if (p->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia (TPilha *p) {
    if (p->topo == MAXTAM - 1)
        return 1;
    else
        return 0;
}

void empilhar (TPilha *p, int x) {
    if (pilha_cheia(p)) {
        printf ("Pilha cheia!\n");
    }
    else {
        p->topo++;
        p->item[p->topo] = x;
    }
}

int desempilhar (TPilha *p) {
    int aux;
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
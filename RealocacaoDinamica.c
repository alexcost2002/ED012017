#include <stdlib.h>
#include <stdio.h>

struct no {
    int dado;
    struct no *prox;
}; typedef struct no tno;
struct pilha {
    tno *topo;
}; typedef struct pilha tpilha;
void iniciapilha(tpilha *p);
int pilhavazia(tpilha p);
void empilha (tpilha *p, int dado);
int desempilha (tpilha *p);


void iniciapilha(tpilha *p){
    p->topo=NULL;
}
int pilhavazia(tpilha p) {
    return p.topo==NULL;
}
void empilha (tpilha *p, int va) {
    tno *aux;
    aux=(tno*)malloc(sizeof(tno));
    if (!aux) exit(1);
    aux->dado = va;
    aux->prox = NULL;
    if(pilhavazia(*p)) p->topo = aux;
    else {
        aux->prox = p->topo;
        p->topo = aux;
    }
}
int desempilha (tpilha *p) {
    tno *aux;
    int va;
    if (!pilhavazia(*p))  {
        aux=p->topo;
        va=p->topo->dado;
        p->topo=aux->prox;
        free(aux);
        return va;
    }
    else return -1;
}

int main () {
    tpilha a, *p=&a;
    int i, num, n;
    iniciapilha(p);
    for (i=0; i<10; i++) empilha(p, i);
    for (i=0; i<10; i++) printf("\t%d\n",desempilha(p));
    return 0;
}
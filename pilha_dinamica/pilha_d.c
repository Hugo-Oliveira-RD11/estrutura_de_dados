#include "pilha_d.h"
#include <stdio.h>
#include <stdlib.h>

Pilha* build(){
    Pilha *p = criar();
    return p;
}

int delete_pilha(Pilha *p){
    if (p == NULL) return -1;

    return deletar(p);
}

int push(Pilha *p, int var){
    if (p == NULL) return -1;
    Pilha *nova = (Pilha *) malloc(sizeof(Pilha));
    *p->proximo = *nova;
    return 1;
}

int pop(Pilha *p){
    if (p== NULL) return -1;
    int num = p->number;
    *p = *p->proximo; // faltou o free
    return num;
}

int IsFull(Pilha* P){
    return -1;
}
int IsEmpty(Pilha* p){
    if(p == NULL) return 1;
    return -1;
}
void printAll(Pilha *p){
    Pilha *aux = p;
    int i=0;
    while(aux->proximo != NULL){
        aux = aux->proximo;
        printf("number [%d] = %d\n",i,aux->number);
        i++;
    }
}

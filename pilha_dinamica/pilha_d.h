#ifndef PILHA_D_H_
#define PILHA_D_H_
#include "../Lista_dinamica/lista_d.h"

typedef Lista Pilha ;

Pilha* build();
int delete_pilha(Pilha* P);
int push(Pilha* P, int var);
int pop(Pilha* P);
int IsFull(Pilha* P);
int IsEmpty(Pilha* P);
void printAll(Pilha *p);
#endif // PILHA_D_H_

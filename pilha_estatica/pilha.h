#ifndef PILHA_H_
#define PILHA_H_

#define MAX 100
typedef int TypeItem;

typedef struct pilha Pilha;

struct pilha {
  int top;
  TypeItem itens[MAX];
};

Pilha* build();
int delete_pilha(Pilha* P);
int push(Pilha* P, TypeItem var);
int pop(Pilha* P);
int IsFull(Pilha* P);
int IsEmpty(Pilha* P);
int PrintFirst(Pilha* P);

#endif // PILHA_H_

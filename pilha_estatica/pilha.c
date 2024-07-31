#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Pilha* build() {
  Pilha *temp;
  temp = (Pilha*)malloc(sizeof(struct pilha)); // implement verification
  temp->top = 0;
  return temp;
}
 int delete_pilha(Pilha* P){
  if(P == NULL) return -1;
  free(P);
  return 1;
}

int push(Pilha* P, TypeItem var){
  if(P == NULL) return -1;
  if(IsFull(P) == 1)  return -1;
  P->itens[P->top] = var;
  P->top++;
  return 1;
}
int pop(Pilha* P){
  if(P == NULL) return -1;
  if(IsEmpty(P) == 1){
    return -1;
  }
  P->top--;
    return 1;
}
int IsEmpty(Pilha* P){
  if(P == NULL) return -1;
  if(P->top == 0)
    return 1;
  else
    return 0;
}

int IsFull(Pilha* P){
  if(P == NULL) return -1;
  if(P->top == MAX)
    return 1;
  else
    return 0;
}

int PrintFirst(Pilha* P){
  if(P == NULL) return -1;
  if(IsEmpty(P) == 1)
    return -1;
  return P->itens[P->top-1];
}

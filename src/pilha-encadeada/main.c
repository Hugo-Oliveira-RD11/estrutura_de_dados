#include "main.h"
#include <stdlib.h>
#define null NULL

struct No {
  int dado;
  struct No *next;
};

typedef struct No no;

no *newNo() {
  no *node = (no *) malloc(sizeof(no));
  (*node).next = null;
  node->dado = 0;
  return node;
}

stack* create() {
  stack *sk = (stack *) malloc(sizeof(stack));
  (*sk)->next = null;
  (*sk)->dado = 0;
 return sk; 
}
void dell(stack *pilha) {
  stack *paux = pilha;
  stack *aux = paux;
  while ((*aux)->next != null) {
    paux = aux;
    *aux = (*aux)->next;
    free(paux);
  }
  free(aux);
  free(paux);
}

int isFull(stack *pilha) {
  return 0;
}
int isNull(stack *pilha) {
  return ((*pilha) == null);
}
int length(stack *pilha) {
  int i = 0;
  no *aux = *pilha;
  while ((*aux).next != null) {
    aux = (*aux).next;
    i++;
  }
  return i;
}

int Pop(stack *pilha) {
  if(isNull(pilha))
    return 0;

  int i = (*pilha)->dado;
  no *node = *pilha;
  *pilha = (*pilha)->next;

  free(node);
  return i;
}

int Push(stack *pilha, int dado) {

  no *node = newNo();
  node->dado = dado;
  node->next = *pilha;
  *pilha = node;
  return 0;
}
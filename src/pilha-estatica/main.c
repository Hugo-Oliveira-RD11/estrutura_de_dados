#include "main.h"
#include <stdlib.h>
#define MAX 100

struct Pilha {
  int total;
  int dados[MAX];
};

typedef struct Pilha* stack;

stack* newPh() {
 stack *test = (stack *) malloc(sizeof(stack));
 (*test)->total = 0;
 return test;
}

stack *create() {
  stack *ph = newPh();

  return ph;
}
void dell(stack *ph) {
  free(ph);
}

int isFull(stack *pilha) {
  return ((*pilha)->total == MAX);
}

int isNull(stack *pilha) {
  return ((*pilha)->total == 0);
}
int length(stack *pilha) {
  return (*pilha)->total;
}

int Pop(stack *pilha) {
  if (isNull(pilha))
    return 0;
  int i = (*pilha)->dados[(*pilha)->total];
  (*pilha)->total--;
  return i;
}

int Push(stack *pilha, int dado) {
  if (isFull(pilha))
    return 0;

  (*pilha)->total++;
  (*pilha)->dados[(*pilha)->total++] = dado;

  return 1;
}
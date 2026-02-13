#include "main.h"
#include <stdlib.h>
#define MAX 100

struct queue {
  int first;
  int last;
  int qdt;
  int dados[MAX];
};



Fila *create() {
  Fila *fila = (Fila *) malloc(sizeof(Fila));
  fila->first = 0;
  fila->last = 0;
  fila->qdt = 0;
  return fila;
}
void dell(Fila *fila) {
  free(fila);
}

int isFull(Fila *fila) {
  return (fila->qdt == MAX);
}
int isNull(Fila *fila) {
  return (fila->qdt == 0);
}
int length(Fila *fila) {
  return fila->qdt;
}

int dequeue(Fila *fila) {
  if(isNull(fila))
    return 0;
  int i = fila->dados[fila->first];
  fila->first = (fila->first++) % MAX;
  fila->qdt--;

  return i;
}

int enqueue(Fila *fila, int dado) {
  if(isFull(fila))
    return 0;

  fila->last = (fila->last++) % MAX;
  fila->dados[fila->last] = dado;
  fila->qdt++;

  return 1;
}
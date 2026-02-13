#include "main.h"
#include <stdlib.h>
#define null NULL

struct No {
  int dado;
  struct No *next;
};

typedef struct No no;

no *newNoValue(int dado) {
  no *node = (no *) malloc(sizeof(no));
  (*node).next = null;
  node->dado = dado;
  return node;
}

no *newNo() {
  no *node = (no *) malloc(sizeof(no));
  (*node).next = null;
  node->dado = 0;
  return node;
}

queue *create() {
  queue *fila = (queue *) malloc(sizeof(queue));
  (*fila)->dado = 0;
  (*fila)->next = null;

  return fila;
}

void dell(queue *fila) {
  no *aux = *fila;
  no *paux;
  while (aux->next != null) {
    paux = aux;
    aux = aux->next;
    free(paux);
  }
  free(aux);
  free(fila);
}

int isFull(queue *fila) {
  return 0;
}

int isNull(queue *fila) {
  return ((*fila) != null);
}

int length(queue *fila) {
  no *aux = *fila;
  int i = 0;
  while (aux->next != null) {
    aux = aux->next;
    i++;
  }

  return i;
}

int dequeue(queue *fila) {
  if(isNull(fila))
    return 0;

  no *aux = *fila;
  int i = aux->dado;
  (*fila) = (*fila)->next;

  free(aux);
  return i;
}

int enqueue(queue *fila, int dado) {
  if(fila == null)
    return 0;
  no *node = newNoValue(dado);
  no *aux = *fila;

  while (aux->next != null) {
    aux = aux->next;
  }

  aux->next = node;
  return 1;
}
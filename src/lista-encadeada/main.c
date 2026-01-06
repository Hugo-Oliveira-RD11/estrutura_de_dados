#include "main.h"
#include <stdlib.h>

struct No {
  int dado;
  struct No *next;
};
typedef struct No no;

Lista* create() {
  Lista *li = (Lista*) malloc(sizeof(Lista));

  (*li)->next = NULL;

  return li;
}

void dell(Lista *li) {
  if (!isNull(li))
    return;

  no* aux;

  while ((*li) != NULL) {
    aux = *li;
    *li = (*li)->next;
    free(aux);
  }  
  free(li);
}

int size(Lista *li) {
  if (!isNull(li))
    return 0;

  int total = 0;
  no *aux = *li;

  while (aux != NULL) {
    *aux = *aux->next;
    total++;
  }
  return total;
}

int isFull(Lista *li) {
  return 0;
}

int isNull(Lista *li) {
  return (*li == NULL);
}

int insert_begin(Lista *li, int dado) {
  if (li == NULL)
    return 0;

  no *new = (no*) malloc(sizeof(no));

  new->dado = dado;
  new->next = (*li);

  *li = new;

  return 1;
}

int insert_middle(Lista *li, int dado, int position) {
  if (li == NULL)
    return 0;
  int i=0;
  no *aux = *li;

  while (i < position) {
    aux = aux->next;
    i++;
  };
  
  no *new = (no*) malloc(sizeof(no));

  new->dado = dado;
  new->next = aux->next;

  aux->next = new;

  return 1;
}

int insert_final(Lista *li, int dado) {
  if (li == NULL)
    return 0;

  no *aux = *li;
  while (aux->next != NULL) {
    aux = aux->next;
  };
  
  no *new = (no*) malloc(sizeof(no));

  new->dado = dado;
  new->next = aux->next;

  aux->next = new;

  return 1;
}

int remove_begin(Lista *li) {
  if (li == NULL || isNull(li))
    return 0;

  no *aux = *li;
  *li = (*li)->next;

  free(aux);

  return 1;
}

int remove_middle(Lista *li, int position) {
  if (li == NULL || isNull(li))
    return 0;

  int i = 0;
  no  *paux = *li, *aux = paux->next;

  while (i < position || li != NULL) {
    paux = aux;
    aux = aux->next;
    i++;
  }

  if (i != position)
    return 0;

  paux->next = aux->next;

  free(aux);

  return 1;
}

int remove_final(Lista *li) {
  if (li == NULL || isNull(li))
    return 0;

  no  *paux = *li, *aux = paux->next;

  while (aux->next != NULL) {
    paux = aux;
    aux = aux->next;
  }
  paux->next = aux->next;

  free(aux);

  return 1;
}
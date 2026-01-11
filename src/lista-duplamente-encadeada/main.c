#include "main.h"
#include <stdlib.h>


struct No {
  int dado;
  struct No *next;
  struct No *prev;
};

typedef struct No no;

List *create() {
  List *li = (List*) malloc(sizeof(List));

  (*li)->next = NULL;
  (*li)->prev = NULL;

  return li;
}

void dell(List *li) {
  if(isNull(li))
    return;
  no *aux = *li;

  while ((*li) != NULL) {
    aux = *li;
    *li = (*li)->next;
    free(aux);
  }
  free(li);
}

int size(List *li) {
  int i = 0;
  no *aux = *li;

  while (aux != NULL) {
    aux = aux->next;
    i++;
  }
  return i;
}

int isFull(List *li) {
  return 0;
}

int isNull(List *li) {
  return ((*li) == NULL) ;
}

no *newNo() { // para nao precisar declarar tudo nulo
  no *new = (no*) malloc(sizeof(no));

  new->prev = NULL;
  new->next = NULL;

  return new;
}

int insert_begin(List *li, int dado) {
  if (li == NULL)
    return 0;

  no *new = newNo();

  new->dado = dado;
  new->next = (*li);
  (*li)->prev = new;

  *li = new;
  return 1;
}
int insert_middle(List *li, int dado, int position) {
  if (li == NULL)
    return 0;

  no *new = newNo();
  new->dado = dado;

  int i=0;
  no *aux = *li, *paux;
  while (aux != NULL || i < position) {
    paux = aux;
    aux = aux->next;
    i++;
  }
  if(aux == NULL || i != position)
    return 0;

  new->prev = aux->prev;
  new->next = aux;
  aux->prev = new;
  paux->next = new;

  return 1;
}
int insert_final(List *li, int dado) {
  if( li == NULL )
    return 0;

  no *aux = *li;
  while (aux->next != NULL) {
    aux = aux->next;
  }

  no *new = newNo();
  aux->next = new;
  new->prev = aux;

  return 0;
}

int remove_begin(List *li);
int remove_middle(List *li, int position);
int remove_item(List* li, int dado);
int remove_final(List *li);
#include "main.h"
#include "stdio.h"
#include <stdlib.h>

// devolve 0 caso seja erro
int _isExist(List *li) {
  return (li != NULL);
}

List *create() {
  List *li = (List *) malloc(sizeof(List));
  li->qtd = 0;
  return li;
}

void dell(List *li) {
  free(li);
}

int isNull(List *li) {
  if (!_isExist(li))
    return 0;

  return (li->qtd == 0);
}

int isFull(List *li) {
  if (!_isExist(li))
    return 0;

  return (li->qtd == MAX);
}

int size(List *li) {
  if (!_isExist(li))
    return 0;

  return li->qtd;
}

int insert_final(List *li, int dado) {
  if (!_isExist(li) || isFull(li))
    return 0;

  li->dado[li->qtd] = dado;
  li->qtd++;
  return 1;
}

int insert_begin(List* li, int dado){
  if (!_isExist(li) || isFull(li))
    return 0;

  for (int i = (li->qtd - 1); i >= 0; i--) {
    li->dado[i+1] = li->dado[i];
  }

  li->dado[0] = dado;
  li->qtd++;
  return 1;
}

int insert_middle(List* li, int dado, int position){
  if (!_isExist(li) || isFull(li))
    return 0;

  if (position == 0) {
    insert_begin(li, dado);
  }

  if (position >= li->qtd) {
    insert_final(li, dado);
  }

  for (int i = (li->qtd - 1); i >= position; i--) {
    li->dado[i+1] = li->dado[i];
  }

  li->dado[position] = dado;
  li->qtd++;
  return 1;
}

int remove_final(List* li){
  if (!_isExist(li) || isNull(li))
    return 0;

  li->qtd--;
  return 1;
}

int remove_begin(List* li){
  if (!_isExist(li) || isNull(li))
    return 0;

  for (int i = 0; i != li->qtd; i++) {
    li->dado[i] = li->dado[i+1];
  }

  li->qtd--;

  return 1;
}

int remove_middle(List *li, int position) {
  if (!_isExist(li) || isNull(li))
    return 0;

  if (position == 0) {
    remove_begin(li);
  }

  if (position >= li->qtd) {
    remove_final(li);
  }


  for (int i = 0; i != position; i++) {
    li->dado[i] = li->dado[i+1];
  }

  li->qtd--;

  return 1;
  
}

int remove_item(List *li, int dado) {
  if (!_isExist(li) || isNull(li))
    return 0;
  int position = 0;

  for (int i = 0; i != li->qtd; i++) {
    if (li->dado[i] == dado) {
      position = i;
    } 
  }

  for (int i = position; i < li->qtd; i++) {
    li->dado[i] = li->dado[i+1];
  }

  li->qtd--;

  return 1;
  
}

// subtrai a position pois e posicao "humana" e nao computacionalmente
int search_position(List *li, int position, int* dado_return) {
  if (!_isExist(li) || isNull(li) || li->qtd <= position || position <= 0)
    return 0;

  *dado_return = li->dado[position-1];
  return 1;
}
int search(List *li, int dado, int* dado_return){
  if (!_isExist(li) || isNull(li))
    return 0;

  for (int i = 0; i < li->qtd; i++) {
    if (li->dado[i] == dado) {
      *dado_return = li->dado[i];
      return 1;
    }
  }
  
  return 0;
}
#include "pilha.h"
#include <stdio.h>
void Imprimir(Pilha* p){
      printf("valor na posicao [%d] = %d\n",p->top,PrintFirst(p));
}

int main() {
  int x;
  Pilha *nada = build();

  x = pop(nada);
  Imprimir(nada);
  x = pop(nada);
  Imprimir(nada);

  x = push(nada, 201);
  Imprimir(nada);
}

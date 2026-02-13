#ifndef MAIN_H_
#define MAIN_H_

typedef struct No* stack;
/* struct Pilha { */
/*   int total; */
/*   int dados[MAX]; */
/* }; */

stack* create();
void dell(stack *pilha);

int isFull(stack *pilha);
int isNull(stack *pilha);
int length(stack *pilha);

int Pop(stack *pilha);
int Push(stack *pilha, int dado);


#endif // MAIN_H_
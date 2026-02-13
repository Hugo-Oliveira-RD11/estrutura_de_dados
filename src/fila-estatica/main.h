#ifndef MAIN_H_
#define MAIN_H_

typedef struct queue Fila;

Fila* create();
void dell(Fila *fila);

int isFull(Fila *fila);
int isNull(Fila *fila);
int length(Fila *fila);

int dequeue(Fila *fila);
int enqueue(Fila *fila, int dado);

#endif // MAIN_H_
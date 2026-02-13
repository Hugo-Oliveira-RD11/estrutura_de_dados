#ifndef MAIN_H_
#define MAIN_H_

typedef struct No* queue;

queue* create();
void dell(queue *fila);

int isFull(queue *fila);
int isNull(queue *fila);
int length(queue *fila);

int dequeue(queue *fila);
int enqueue(queue *fila, int dado);


#endif // MAIN_H_
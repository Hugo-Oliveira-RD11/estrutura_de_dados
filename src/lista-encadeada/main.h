#ifndef MAIN_H_
#define MAIN_H_

typedef struct No* Lista;

Lista* create();
void dell(Lista *li);

int size(Lista *li);
int isFull(Lista *li);
int isNull(Lista *li);

int insert_begin(Lista *li, int dado);
int insert_middle(Lista *li,int dado, int position);
int insert_final(Lista *li, int dado);


int remove_begin(Lista *li);
int remove_middle(Lista *li, int position);
int remove_final(Lista *li);
#endif // MAIN_H_
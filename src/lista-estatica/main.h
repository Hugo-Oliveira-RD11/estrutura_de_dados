#ifndef MAIN_H_
#define MAIN_H_

#define MAX 100

typedef struct list List;

struct list {
  int qtd;
  int dado[MAX];
};

List* create();
void dell(List* li);

int isNull(List* li);
int isFull(List* li);
int size(List* li);

int insert_final(List* li, int dado);
int insert_begin(List* li, int dado);
int insert_middle(List* li, int dado, int position);

int remove_final(List* li);
int remove_begin(List* li);
int remove_item(List* li, int dado);
int remove_middle(List* li, int position);

int search_position(List *li, int position, int* dado_return);
int search(List *li, int dado, int* dado_return);
#endif // MAIN_H_
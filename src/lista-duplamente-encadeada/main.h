#ifndef MAIN_H_
#define MAIN_H_
typedef struct No* List;

List* create();
void dell(List *li);

int size(List *li);
int isFull(List *li);
int isNull(List *li);

int insert_begin(List *li, int dado);
int insert_middle(List *li,int dado, int position);
int insert_final(List *li, int dado);

int remove_begin(List *li);
int remove_middle(List *li, int position);
int remove_item(List* li, int dado);
int remove_final(List *li);

int search_position(List *li, int position, int* dado_return);
int search(List *li, int dado, int* dado_return);
#endif // MAIN_H_
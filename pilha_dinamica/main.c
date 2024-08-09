#include "pilha_d.h"
#include "stdio.h"

int main(){
    Pilha *p = build();
    for (int i = 0; i<10; i++) {
        printf("ver %d\n",push(p, i));
    }
    printAll(p);

    pop(p);

    printAll(p);
}

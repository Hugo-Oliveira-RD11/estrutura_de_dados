#include "lista_e.h"
#include <stdio.h>
#include <stdlib.h>

Lista* criar(){
    Lista *L;
    L = (Lista *) malloc(sizeof(Lista));
    if(L != NULL)
        L->qtd=0;
    return L;
}
int deletar(Lista* L){
    if (L == NULL) {
        return -1;
    }
    free(L);
    return 1;
}
int Tamanho(Lista* L){
    return L->qtd;
}

int IsExist(Lista* L){
    if(L == NULL)
        return -1;
    return 1;
}
int IsFull(Lista* L){
    if (IsExist(L)== 1)
        return -1;
    if(L->qtd == MAX)
        return 1;
    return -1;
}
int IsEmpty(Lista* L){
    if (IsExist(L)== 1)
        return -1;
    if(L->qtd == 0)
        return 1;
    return -1;
}

int inserir_final(Lista* L, TypeItem var){
    if(IsExist(L)==-1) return -1;
    if(IsFull(L) == 1) return -1;
    L->item[L->qtd] = var;
    L->qtd++;
    return 1;
}

int inserir_inicio(Lista* L, TypeItem var){
    if(IsExist(L)==-1) return -1;
    if(IsFull(L) == 1) return -1;
    if (IsEmpty(L) ==1) {
        L->item[L->qtd] = var;
        L->qtd++;
        return 1;
    }
    int i=0;
    for (i=L->qtd-1; i>0; i++) {
        L->item[i] = L->item[L->qtd];
    }
    L->item[i] = var;
    L->qtd++;
    return 1;
}
int inserir_ordenado(Lista *L, TypeItem var){
    if(IsExist(L)==-1) return -1;
    if(IsFull(L) == 1) return -1;
    int i=0;
    while (i<L->qtd-1 && var>L->item[i]) i++; // ele testar se for maior, caso não seja mais, ele quebra o laço e não conta mais pois achou um elemento maior que ele
    return inserir_meio(L, i, var);
 }

int inserir_meio(Lista* L,int position, TypeItem var){
    if(IsExist(L)==-1) return -1;
    if(IsFull(L) == 1) return -1;
    if (IsEmpty(L) == 1) {
        L->item[L->qtd] = var;
        L->qtd++;
        return 1;
    }
    if(position >= L->qtd || position >=MAX){
        return inserir_final(L, var);
    }
    if(position == 1){
        return inserir_inicio(L, var);
    }
    int i=0;
    for (i = L->qtd-1; i>position; i--) {
        L->item[i+1] = L->item[i];
    }
    L->item[position] = var;
    L->qtd++;
    return 1;
}


int remover_final(Lista* L){
    if (IsExist(L) == -1) return -1;
    if (IsEmpty(L) == 1) return -1;
    L->qtd--;
    return 1;
}

int remover_inicio(Lista *L){
    if (IsExist(L) == -1) return -1;
    if (IsEmpty(L) == 1) return -1;
    for (int i=1; i<L->qtd; i++)
        L->item[i-1] = L->item[i];

    L->qtd--;
    return 1;
}

int remover_meioP(Lista* L,int position){
    if (IsExist(L) == -1) return -1;
    if (IsEmpty(L) == 1) return -1;
    if(position>=MAX)
        return remover_final(L);
    if(position==0)
        return remover_inicio(L);

    int i=0;
    for (i=position; i<L->qtd; i++)
        L->item[i] = L->item[i+1];


    L->qtd--;
    return 1;
}
int remover_meioI(Lista* L,TypeItem var){
    if (IsExist(L) == -1) return -1;
    if (IsEmpty(L) == 1) return -1;
    int i=0;
    while(i<L->qtd && var != L->item[i])i++;

    if (i == L->qtd)
        return -1;

    return remover_meioP(L, i);
}

int consulta_P(Lista* L,int position){
    if (IsExist(L) == -1) return -1;
    if (IsEmpty(L) == 1) return -1;
    if(position>=MAX || position >= L->qtd)
        return -1;

    return L->item[position--];
}
int consulta_I(Lista* L, TypeItem var){
    if (IsExist(L) == -1) return -1;
    if (IsEmpty(L) == 1) return -1;
    int i=0;
    while(i<L->qtd && var != L->item[i])i++;
    if(i == L->qtd)
        return -1;
    return L->item[i];
}

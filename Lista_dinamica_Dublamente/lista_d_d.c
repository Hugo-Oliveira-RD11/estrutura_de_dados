#include "lista_d_d.h"
#include <stdlib.h>
#include <stdio.h>


Lista* criar(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li == NULL) return NULL;

    li->proximo = NULL;
    li->anterior = NULL;
    li->number = 0;
    return li;
}
int deletar(Lista *li){
    Lista *aux = li;

    while(li->proximo != NULL){
        aux = li;
        li = li->proximo;
        free(aux);
    }
    free(li);
    return 1;
}
int inserir_Inicio(Lista *li, int var){
    if(li == NULL) return -1;
    Lista *no = (Lista*)malloc(sizeof(Lista));
    no->number = var;

    no->anterior = NULL;
    li->anterior = no;
    no->proximo = li;
    li = no;

    return 1;
}
int inserir_Ordenada(Lista *li, int var){
    if(li == NULL) return -1;
    Lista *no = (Lista*)malloc(sizeof(Lista));

    no->number = var;
    Lista *aux = li;
    Lista *paux = li;

    while(aux->proximo != NULL && no->number > aux->number){
        paux = aux;
        aux = aux->proximo;
    }
    no->proximo = aux;
    no->anterior = paux;
    paux->proximo = no;
    aux->anterior = no;
    return 1;
}
int inserir_Position(Lista *li, int var, int position){
    if(li == NULL) return -1;
    if(position == 1 || position < 1) return inserir_Inicio(li, var);
    Lista *no = (Lista*)malloc(sizeof(Lista));
    no->number = var;
    Lista *aux = li;
    Lista *paux = aux;

    int i=0;
    while(aux->proximo != NULL && i < position){
        i++;
        paux = aux;
        aux = aux->proximo;
    }
    if(i != position)return -1;

    no->proximo = aux;
    no->anterior = paux;
    paux->proximo = no;
    aux->anterior = no;
    return 1;

}
int inserir_Final(Lista* li, int var){
    if(li == NULL) return -1;
    Lista *no = (Lista*)malloc(sizeof(Lista));
    Lista *aux = li;
    no->number = var;
    no->proximo = NULL;

    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    no->anterior = aux;

    return 1;
}

int remover_Inicio(Lista *li){
    if (li == NULL ) return -1;
    Lista *del = li;
    if(del->anterior != NULL) return -1;

    li = li->proximo;
    free(del);
    return 1;
}
int remover_Final(Lista *li){
    if (li == NULL ) return -1;
    Lista *del = li;
    while(del->proximo != NULL)
        del = del->proximo;

    free(del);
    return 1;
}
int remover_Position(Lista *li, int position){
    if (li == NULL ) return -1;
    Lista *aux = li;
    int i=0;
    while (aux->proximo != NULL && i<position) {
        aux = aux->proximo;
        i++;
    }
    if(i != position) return -1;

    free(aux);
    return 1;
}
int remover_Item(Lista *li, int var){
    if (li == NULL ) return -1;
    Lista *aux = li;
    while (aux->proximo != NULL && var!=aux->number) {
        aux=aux->proximo;
    }
    if(aux->number != var) return -1;

    free(aux);
    return 1;
}

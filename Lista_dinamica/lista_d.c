#include "lista_d.h"
#include <stdlib.h>

Lista* criar(){
    Lista *l;
    l = malloc(sizeof(Lista));
    l->proximo = NULL;
    return l;
}

int deletar(Lista *li){
    Lista *aux = li;
    Lista *paux = li;

    while(aux != NULL){
        paux = aux;
        aux = aux->proximo;
        free(paux);
    }
    free(aux);
    return 1;
}

int tamanho(Lista *no){
    if(IsEmpyt(no) == -1) return -1;

    int tam=0;

    Lista *myNo = no;
    while( myNo != NULL ){
        *myNo = *myNo->proximo;
        tam++;
    }
    return tam;
}
int IsEmpyt(Lista *li){
    if(li == NULL) return 1;
    return -1;
}

int inserir_Inicio(Lista* li, int var){ // aprender sobre ponteiro
                                    // testar os ponteiros!
    if(li == NULL) return -1;

    Lista *myNo = (Lista *) malloc(sizeof(Lista));

    myNo->number = var;
    myNo->proximo = li;
    li->proximo = myNo; //acho que da erro aqui

    return 1;
}

int inserir_Final(Lista* li, int var){
    if(li == NULL) return -1;

    Lista *no = (Lista *) malloc(sizeof(Lista));
    no->number = var;
    no->proximo = NULL;

    if(li->proximo == NULL){

    }

    Lista *aux = li;
    while (aux->proximo) {
        aux = aux->proximo;
    }
    aux->proximo = no;

    free(aux);
    return 1;
}

int inserir_Ordenada(Lista *li, int var){
    Lista *no = (Lista *) malloc(sizeof(Lista));
    no->number = var;

    if(li->proximo == NULL) return inserir_Inicio(li, var);

    Lista *aux = li;
    Lista *paux = aux;
    while(aux->number < no->number && aux->proximo != NULL){
        paux = aux;
        aux = aux->proximo;
    }
    if(aux == li) return inserir_Inicio(li, var);

    no->proximo = paux->proximo;
    paux->proximo = no;
    return 1;
}

int inserir_Position(Lista *li, int var, int position){
    int i=0;

    Lista *no = (Lista *) malloc(sizeof(Lista));
    no->number = var;

    Lista *aux = li;
    Lista *paux = aux;

    if (position == 1) return inserir_Inicio(li, var);

    if(position < 0) return -1;

    while(aux->proximo != NULL && i<position){
        paux = aux;
        aux = aux->proximo;
        i++;
    }
    if(aux->proximo == NULL) return inserir_Final(li, var);

    no->proximo = paux->proximo;
    paux->proximo = no;

    return 1;
}
int remover_Inicio(Lista *li){
    if(li == NULL) return -1;

    Lista *no = li;
    li = no->proximo;
    free(no);

    return 1;
}
int remover_Final(Lista *li){
    if(li == NULL) return -1;
    Lista *aux = li;
    Lista *paux = li;

    while (aux->proximo != NULL) {
        paux = aux;
        aux = aux->proximo;
    }

    paux->proximo = NULL;
    free(aux);
    return 1;
}
int remover_Position(Lista *li, int position){
    int i=0;
    Lista *aux = li;
    Lista *paux = li;

    while (aux->proximo != NULL && i<position) {
        paux = aux;
        aux = aux->proximo;
        i++;
    }
    if(aux->proximo == NULL){
    paux->proximo = NULL;
    free(aux);
    }

    paux->proximo = aux->proximo;
    free(aux);

    return 1;
}
int remover_Item(Lista *li, int var){
    if(li == NULL) return -1;
    Lista *aux = li;
    Lista *paux = li;

    while(aux->proximo != NULL && var != aux->number){
        paux = aux;
        aux = aux->proximo;
    }
    if(var == aux->number ){
        paux->proximo = NULL;
        if( aux->proximo != NULL)
            paux->proximo = aux->proximo;
    }
    free(aux);
    return 1;
}

int consulta_Position(Lista* li, int position){ // tem como fazer o retorno por ponteiro ao em vez de retorno pela função
    if(li == NULL || position <= 0 ) return -1;
    int i=1;
    Lista *aux = li;

    while(aux->proximo != NULL && i<position) {
        aux = aux->proximo;
        i++;
     }
    if(i != position) return -1;

    return aux->number;
}
int consulta_Item(Lista *li,int var){
    if(li == NULL) return -1;
    Lista *aux = li;

    while(aux->proximo != NULL && aux->number != var) {
        aux = aux->proximo;
     }
    if(aux->number != var) return -1;

    return aux->number;
}

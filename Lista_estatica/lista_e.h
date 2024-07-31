#ifndef LISTA_E_H_
#define LISTA_E_H_

#define MAX 100
typedef int TypeItem;

typedef struct lista_e{
    int qtd;
    TypeItem item[MAX];
}Lista;

Lista* criar();
int deletar(Lista* L);
int inserir_final(Lista* L, TypeItem var);
int inserir_inicio(Lista* L, TypeItem var);
int inserir_meio(Lista* L,int position, TypeItem var);
int inserir_ordenado(Lista* L, TypeItem var);
int remover_final(Lista* L);
int remover_inicio(Lista* L);
int remover_meioP(Lista* L,int position);
int remover_meioI(Lista* L,TypeItem var);
int IsFull(Lista* L);
int IsEmpty(Lista* L);
int Tamanho(Lista* L);
int consulta_P(Lista* L,int position);
int consulta_I(Lista* L, TypeItem var);


#endif // LISTA_E_H_

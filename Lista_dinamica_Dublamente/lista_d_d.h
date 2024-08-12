#ifndef LISTA_D_D_H_
#define LISTA_D_D_H_


typedef struct no{
    struct no *anterior;
    int number;
    struct no *proximo;
}Lista;

Lista* criar();
int deletar(Lista *li);
int inserir_Inicio(Lista *li, int var);
int inserir_Ordenada(Lista *li, int var);
int inserir_Position(Lista *li, int var, int position);
int inserir_Final(Lista* li, int var);
int remover_Inicio(Lista *li);
int remover_Final(Lista *li);
int remover_Position(Lista *li, int position);
int remover_Item(Lista *li, int var);
int consulta_Item(Lista *li,int var);
int consulta_Position(Lista *li,int position);
int tamanho(Lista *Lista);
int IsEmpyt(Lista *Lista);


#endif // LISTA_D_D_H_
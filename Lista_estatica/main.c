#include "stdio.h"
#include "stdlib.h"
#include "lista_e.h"

#define MAXTEST 21
void All(Lista *L){
    for (int i=0; i<L->qtd; i++) {
    printf("L[%d]=%d\n",i,consulta_P(L, i));
    }
    printf("\n\n");
}
void limpa_tela() {
#ifdef __unix__
    system("clear");
#else
    system("cls");
#endif
    printf("\n======= teste de lista estatica ==========\n");
}
int main(){
limpa_tela();
    Lista *L = criar();

    for (int i=1; i<MAXTEST; i++) {
        inserir_final(L, i);
    }

    All(L);
    remover_meioP(L, 3);
    printf("\n\n========== remove o elemento na posicao[3] ==========\n\n");
    All(L);
    printf("\n\n========== remove o item 15 ==========\n\n");
    remover_meioI(L, 15);
    All(L);
    printf("\n\n========== remove o elemento na posicao[8] ==========\n\n");
    remover_meioP(L, 8);
    All(L);

    printf("\n\n========== inserindo o numero 41 elemento na posicao[3] sem apagar os outro elementos ==========\n\n");
    inserir_meio(L,3,41);
    All(L);

    printf("\n\n========== inserindo o numero 256 elemento no final sem apagar os outro elementos ==========\n\n");
    inserir_final(L,255);
    All(L);


    Lista *Li = criar();
    for (int i=0;i<MAXTEST;i++) {
        Li->item[i] = rand();
    }
    All(Li);

}

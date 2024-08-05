#include "stdio.h"
#include <stdlib.h>
#include "lista_d.h"

void PrintLista(Lista *li){
    int i=1,k=0,ver=0;
    while (ver != -1){
        ver = consulta_Position(li, i);
        printf("vetor[%d],posicao %d = %d\n",k,i,ver);
        i++;
        k++;
    }
}

int main(){
    Lista *minha = criar();
    int number=0;

    for (int i=1,k=11; i<10;k++, i++) {
        number= k;
        inserir_Final(minha, number);
    }

    PrintLista(minha);

    for (int i=10; i<20; i++) {
        inserir_Ordenada(minha, rand()/100000000);
    }

    PrintLista(minha);

    return 1;
}

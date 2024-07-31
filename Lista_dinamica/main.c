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

    for (int i=0; i<10; i++) {
        number= (rand()/1000000);
        inserir_Final(minha, number);
        consulta_Position(minha, i);
    }
    PrintLista(minha);


    return 1;
}

#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash{
    int qtd, Table_SIZE;
    struct data **itens; // -> o truque aqui e o ponteiro de ponteiro!
};

//tenha preferencia de criar com numeros primos!
Hash* criar(int MAX){
    Hash *hs = (Hash*) malloc((sizeof(Hash)));
    if(hs ==NULL){
        return NULL;
    }
    hs->qtd=0;
    hs->Table_SIZE = MAX;

    hs->itens = (Data**) malloc(hs->Table_SIZE * sizeof(Data*));
    if (hs->itens == NULL) {
        free(hs);
        return NULL;
    }

    for(int i = 0; i<hs->Table_SIZE; i++)
        hs->itens[i] = NULL;
    return hs;
}

int deletar(Hash *hs){
    if(hs == NULL)
        return 0;
    for (int i =0; i<hs->Table_SIZE; i++) {
        if(hs->itens[i] != NULL){
            free(hs->itens[i]);
        }
    }
    free(hs->itens);
    free(hs);
    return 1;
}

int chaveDivisao(int chave, int MAX){ // função 1 de calcular hash
    return (chave & 0x7FFFFFFF) % MAX; // tem um bitmask, da qual, tira o sinal negativo, garantindo que todo numero seja, obviamente, positivo
}

int chaveMultiplicacao(int chave, int MAX){ // função 2 de calcular hash
    float A = 0.546784126116546; // tem que ser 0< A < 1
    float valor = chave *A;
    valor = valor - (int) valor;
    return (int) (MAX * valor);
}

/*
** 0001
** 0111
** 1001
*/
int chaveDobra(int chave, int MAX){ // função 2 de calcular hash
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (MAX-1);
    return (parte1 ^ parte2);
}

int valorString(char *str){// função 2 de calcular hash
    int i, valor=7;
    int tam = strlen(str);
    for(int i=0; i< tam;i++){
        valor = 31 * valor + (int) str[i];
    }
    return valor;
}

int insere_SemColisao(Hash *hs, Data dados){
    if(hs == NULL || hs->qtd == hs->Table_SIZE)
        return 0;
    int key = dados.key;
    int posicao = chaveDobra(key, hs->Table_SIZE);
     Data *novo = (Data*) malloc(sizeof(Data));
     if(novo == NULL)
         return 0;
     *novo = dados;
     hs->itens[posicao] = novo;
     hs->qtd++;
    return 1;
}

int busca_SemColisao(Hash *hs, Data* retorno,int key){
    if(hs == NULL || hs->qtd == hs->Table_SIZE)
        return 0;
    int posicao = chaveDobra(key, hs->Table_SIZE);
    if(hs->itens[posicao]== NULL)
        return 0;
    *retorno = *(hs->itens[posicao]);
    return 1;
}

int duploHash(int H1,int chave, int i, int MAX){
    int H2 = chaveDivisao(chave,  MAX)+1;
    return ((H1+ i * H2) & 0x7FFFFFFF) % MAX;
}
int procuraQuadratica(int pos, int i, int MAX){
    pos = pos +2*i+ 5*i*i; // função quadratica
    return (pos  & 0x7FFFFFFF)% MAX; //tambem poderia colocar uma bitmask
}
int procuraLinear(int pos, int i, int MAX){
    return ((pos + i) & 0x7FFFFFFF)% MAX; //tambem poderia colocar uma bitmask
}

//não garanto que trocando as funçoes,com keys igual os hashs não se repitão
int insere_SemColisao_escolhe(Hash *hs, Data dados, int op){
    if(hs == NULL || hs->qtd == hs->Table_SIZE)
        return 0;
    int key = dados.key;
    /*aqui viria, a sua escolha, somente uma função de geração de hash,
     * para não ter o problema de key igual gerar hash diferente
     *!!não iriei usar o valorString pois não tenho nem um dado de string */
    int posicao = -1;
     switch (op) {
         case 1:
             posicao = chaveDivisao(key, hs->Table_SIZE);
             break;
         case 2:
             posicao = chaveMultiplicacao(key, hs->Table_SIZE);
             break;
         case 3:
             posicao = chaveDobra(key, hs->Table_SIZE);
             break;
        default:
            break;
     }
     Data *novo = (Data*) malloc(sizeof(Data));
     if(novo == NULL)
         return 0;
     *novo = dados;
     hs->itens[posicao] = novo;
     hs->qtd++;
    return 1;
}
// [ 0 null null 0  ]
//não garanto que trocando as funçoes,com keys igual os hashs não se repitão
int busca_SemColisao_escolhe(Hash *hs, Data* retorno, int dado, int op){
    if(hs == NULL )
        return 0;
    int posicao = -1;
     switch (op) {
         case 1:
             posicao = chaveDivisao(dado, hs->Table_SIZE);
             *retorno = *(hs->itens[posicao]);
             return 1;
             break;
         case 2:
             posicao = chaveMultiplicacao(dado, hs->Table_SIZE);
             *retorno = *(hs->itens[posicao]);
             return 1;
             break;
         case 3:
             posicao = chaveDobra(dado, hs->Table_SIZE);
             *retorno = *(hs->itens[posicao]);
             return 1;
             break;
        default:
            break;
     }
    return 0;
}
int busca(Hash *hs, Data *retorno,int key){
    if(hs == NULL)
        return 0;
    int pos,newPos;
    pos= chaveDobra(key, hs->Table_SIZE);
    for(int i=0;i < hs->Table_SIZE;i++){
        newPos = procuraQuadratica(pos,i,hs->Table_SIZE);
        if(hs->itens[newPos] == NULL)
            return 0;
        if(hs->itens[newPos]->key == key){
            *retorno = *(hs->itens[newPos]);
            return 1;
        }
    }

    return 0;
}

int insere(Hash *hs, Data dados){
    int chave = dados.key;
    int pos,newPos;
    pos= chaveDobra(chave, hs->Table_SIZE);
    for(int i=0;i< hs->Table_SIZE;i++){
        newPos = procuraQuadratica(pos,i,hs->Table_SIZE);
        if(hs->itens[newPos] == NULL){
            Data *novo = (Data *) malloc(sizeof(Data));
            if(novo == NULL)
                return 0;
            *novo = dados;
            hs->itens[newPos] = novo;
            hs->qtd++;
            return 1;
        }
    }
    return 0;
}
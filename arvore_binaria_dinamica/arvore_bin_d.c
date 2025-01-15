#include "arvore_bin_d.h"
#include <stdlib.h>


TreeBin* Criar(){
    TreeBin* tree = (TreeBin *) malloc(sizeof(TreeBin));
    if (tree == NULL) {
        tree = NULL;
    }
    return tree;
}

void liberar_no(TreeBin *no){
    if(no == NULL){
        return;
    }
    liberar_no(no->left);
    liberar_no(no->right);
    free(no);
    no = NULL;
}

void destruir(TreeBin *raiz){
    if(raiz== NULL){
        return ;
    }
    liberar_no(raiz);
    free(raiz);
}
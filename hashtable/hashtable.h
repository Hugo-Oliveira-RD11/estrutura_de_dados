#ifndef HASHTABLE_H_
#define HASHTABLE_H_


typedef struct data{
  int key; // so pra ter algo um pouco mais complexo
  int dados;
}Data;

typedef struct hash Hash;

Hash* criar(int MAX);
int deletar(Hash *hs);

int valorString(char *str);

int insere_SemColisao(Hash *hs, Data dados);
int busca_SemColisao(Hash *hs, Data* retorno, int key);

int insere_SemColisao_escolhe(Hash *hs, Data dados, int op);
int busca_SemColisao_escolhe(Hash *hs, Data* retorno, int dado, int op);

int insere(Hash *hs, Data dados);
int busca(Hash *hs, Data* retorno, int key);

int insere_escolhe(Hash *hs, Data* dados);
int busca_escolhe(Hash *hs, Data* retorno, int dado);
#endif // HASHTABLE_H_

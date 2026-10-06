#include <stdio.h>
#include <stdlib.h>
#include "arvore_seq.h"


struct no vno[NUMNO]; //vetor

/* Cria a arvore com um unico no (raiz) */
void cria_arv(int x) {
    int p;
    
    vno[0].info = x;
    vno[0].used = TRUE;
  
    /* restantes pos ficam vazias */
    for (p = 1; p < NUMNO; p++)
        vno[p].used = FALSE;
}

/* Insere filho esquerdo */
void setesq(int p, int x) {
    int q;
    q = 2 * p + 1;// calculo do indice do indice do filho esquerdo 

    if (q >= NUMNO) {
        printf("Erro: estouro do vetor\n");// se o indice do filho esquerdo calculado for maior q o tamanho do vetor
        exit(1);
    }
    else if (vno[q].used) {
        printf("Erro: insercao incorreta\n");// caso a pos ja estiver ocupada(true)
        exit(1);
    }
    else {
        vno[q].info = x;
        vno[q].used = TRUE;
    }
}

/* Insere filho direito */
void setdir(int p, int x) {
    int q;
    q = 2 * p + 2;

    if (q >= NUMNO) {
        printf("Erro: estouro do vetor\n");
        exit(1);
    }
    else if (vno[q].used) {
        printf("Erro: insercao incorreta\n");
        exit(1);
    }
    else {
        vno[q].info = x;
        vno[q].used = TRUE;
    }
}


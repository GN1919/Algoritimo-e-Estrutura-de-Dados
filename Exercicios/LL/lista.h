#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int id;
    char nome[30];
} Registo;


struct no {
    int info_int;        // Para inteiros 
    char info_char;      // Para caracteres 
    Registo info_reg;    // Para registos 
    struct no *prox;     
};

typedef struct no *NO;   //No é ponteiro pra struct no


struct lista {
    NO cab;  //nocabeca e um "NO "(ponteiro pra struct no ) o q vai nos pemitir usar a struct no apartir do nocabeca          
};

typedef struct lista *LISTA;

/* Protótipos das funções do TDA  */
NO getno();
void inicializar(LISTA *L);
void inserir_inicio(LISTA L, int x);
void inserir_fim(LISTA L, int x);
void inserir_posicao_k(LISTA L, int x, int k);
void remover_inicio(LISTA L, int *px);
void remover_fim(LISTA L, int *px);
void remover_posicao_k(LISTA L, int k, int *px);
void pesquisa(LISTA L, int x);

#endif

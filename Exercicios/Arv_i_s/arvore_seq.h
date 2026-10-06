#ifndef arvore_seq_h
#define arvore_seq_h

#define NUMNO 500
#define TRUE 1
#define FALSE 0

/* estrutura do no */
struct no {
    int info;   // valor do no
    int used;   // indica se a pos esta ocupada
};


extern struct no vno[NUMNO];// evita multiplas inclusoes


void cria_arv(int x);
void setesq(int p, int x);
void setdir(int p, int x);

#endif


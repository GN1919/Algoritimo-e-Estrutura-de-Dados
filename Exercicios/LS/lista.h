#ifndef lista_h
#define lista_h
#define Max 10


typedef struct {
 int v[Max];
 int tamanho;
}lista;

void imprimir(lista *l);
void inicializar(lista *l);
int inseriri(lista *l,int valor);
int inserirkpos(lista *l,int valor,int pos);
int buscarporpos(lista *l,int pos);
int removerinicio(lista *l);
int removerfim(lista *l);
int buscarindiceporvalor(lista *l,int valorprocurado);
#endif




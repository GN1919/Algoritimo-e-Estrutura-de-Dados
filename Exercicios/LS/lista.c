#include "lista.h"
#include <stdio.h>

void inicializar(lista *l){
l->tamanho=0;
}

int inserirkpos(lista *l,int valor,int pos){

 if(l->tamanho==Max || pos<0 || pos>l->tamanho) return 0;
 int i;
 for(i=l->tamanho;i>pos;i--){  //tamanho e a pos livre 
    l->v[i]=l->v[i-1];
 }
 
     l->v[pos]=valor;
     l->tamanho++;   
     return 1;

}

void imprimir(lista *l){
	int i;
    for(i=0;i<l->tamanho;i++){
        printf("%d",l->v[i]);
          printf("\n");
    }
  
}


int inseriri(lista *l,int valor){
if(l->tamanho==Max) return 0;

int i;
for(i=l->tamanho;i>0;i--){
l->v[i]=l->v[i-1];
}
l->v[0]=valor;
l->tamanho++;

return 1;

}
 


int buscarporpos(lista *l,int pos){
if(pos<0 || pos>l->tamanho) {
return 0;	
}
  return l->v[pos];

} 

int buscarindiceporvalor(lista *l,int valorprocurado){
 int i;
 for(i=0;i<l->tamanho;i++){
  if(l->v[i]==valorprocurado){
  	 return i;
  }	
 		
 }
return -1;
  
}


int removerinicio(lista *l){
if(l->tamanho==0) return 0;	

int i;
for(i=0;i<l->tamanho-1;i++){
	l->v[i]=l->v[i+1];
}
l->tamanho--;	
return 1;	
	
}

int removerfim(lista *l){
if(l->tamanho==0) return 0;	

l->tamanho--;	
return 1;	
	
}

int removerkpos(lista *l,int pos){
if(l->tamanho==0 || pos<0 || pos>=l->tamanho) return 0;	
int i;
for(i=pos;i<l->tamanho-1;i++){
	l->v[i]=l->v[i+1];
}	
l->tamanho--;
return 1;	
	
	
}







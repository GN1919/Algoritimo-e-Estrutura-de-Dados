#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "avaliador.h"

int tamanho(char *expressao) {
    int tam = 0;
    char *c = expressao;
    while(*c) {
        if(!isspace(*c)) tam++;
        c++;
    }
    return tam;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s \"expressao\"\n", argv[0]);
        return 1;
    }

    char *expressao = argv[1];
    int s = tamanho(expressao);
    Token tokens[s];
    int i = 0, j = 0;

    while(expressao[i] != '\0') {
        if(!isspace(expressao[i]) && isdigit(expressao[i])) {
            Token novo;
            novo.value = expressao[i];
            novo.type = NUMERO;
            novo.peso = 0;
            tokens[j++] = novo;
        } else if(!isspace(expressao[i]) && strchr("+-*/^", expressao[i])) {
            Token novo;
            novo.value = expressao[i];
            novo.type = OPERADOR;
            switch(expressao[i]) {
                case '+':
                case '-':
                    novo.peso = 1;
                    break;
                case '*':
                case '/':
                    novo.peso = 2;
                    break;
                case '^':
                    novo.peso = 3;
                    break;
            }
            tokens[j++] = novo;
        } else if (!isspace(expressao[i]) && strchr("()", expressao[i])) {
            Token novo;
            novo.value = expressao[i];
            novo.type = PARENTESES;
            novo.peso = 0;
            tokens[j++] = novo;
        }
        i++;
    }

    /* Criação e inserção na fila */
    Fila filaTokens;
    initFila(&filaTokens);
    for(i = 0; i < j; i++) {
        inserir(&filaTokens, tokens[i]);
    }

    int erro = 0;
    int resultado = avaliarExpressao(&filaTokens, &erro);

    if (erro) {
        printf("Erro: divisão por zero\n");
    } else {
        printf("Resultado = %d\n", resultado);
    }

    return 0;
}


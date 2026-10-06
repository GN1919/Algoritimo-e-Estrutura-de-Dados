#include "avaliador.h"
#include <ctype.h>

int precedencia(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int aplicarOperador(char op, int a, int b) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': {
            int res = 1;
            for (int i = 0; i < b; i++) res *= a;
            return res;
        }
        default: return 0;
    }
}

int avaliarExpressao(Fila* tokens, int* erroDivZero) {
    Fila saida;
    initFila(&saida);
    Pilha operadores;
    initPilha(&operadores);

    // Converter para posfixa (Shunting Yard)
    while (!vaziaFila(tokens)) {
        Token t = frente(tokens);
        remover(tokens);

        if (t.type == NUMERO) {
            inserir(&saida, t);
        } else if (t.type == PARENTESES && t.value == '(') {
            push(&operadores, t);
        } else if (t.type == PARENTESES && t.value == ')') {
            while (!vaziaPilha(&operadores) && top(&operadores).value != '(') {
                inserir(&saida, top(&operadores));
                pop(&operadores);
            }
            if (!vaziaPilha(&operadores) && top(&operadores).value == '(') {
                pop(&operadores); // descarta o parêntese esquerdo
            }
        } else if (t.type == OPERADOR) {
            while (!vaziaPilha(&operadores)) {
                Token topo = top(&operadores);
                if (topo.type == OPERADOR && precedencia(topo.value) >= precedencia(t.value)) {
                    inserir(&saida, topo);
                    pop(&operadores);
                } else break;
            }
            push(&operadores, t);
        }
    }

    while (!vaziaPilha(&operadores)) {
        inserir(&saida, top(&operadores));
        pop(&operadores);
    }

    // Avaliar expressão pós-fixa
    Pilha_int valores;
    initPilhaInt(&valores);

    while (!vaziaFila(&saida)) {
        Token t = frente(&saida);
        remover(&saida);

        if (t.type == NUMERO) {
            push_int(&valores, t.value - '0');
        } else if (t.type == OPERADOR) {
            int b = top_int(&valores); pop_int(&valores);
            int a = top_int(&valores); pop_int(&valores);

            if (t.value == '/' && b == 0) {
                *erroDivZero = 1;
                return 0;
            }

            int resultado = aplicarOperador(t.value, a, b);
            push_int(&valores, resultado);
        }
    }

    return top_int(&valores);
}


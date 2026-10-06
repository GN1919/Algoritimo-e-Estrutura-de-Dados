#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "avaliador.h"

// Conta tokens ignorando espaços
int tamanho(char *expressao) {
    int tam = 0;
    while (*expressao) {
        if (!isspace(*expressao)) tam++;
        expressao++;
    }
    return tam;
}

// Verifica se a expressão é sintaticamente válida
int expressaoValida(Token tokens[], int n) {
    int parenteses = 0;
    for (int i = 0; i < n; i++) {
        if (tokens[i].type == OPERADOR) {
            // Não pode começar nem terminar com operador
            if (i == 0 || i == n - 1) return 0;

            // Dois operadores seguidos
            if (tokens[i - 1].type == OPERADOR) return 0;
        }

        // Contar parênteses balanceados
        if (tokens[i].value == '(') parenteses++;
        if (tokens[i].value == ')') parenteses--;

        if (parenteses < 0) return 0; // ) antes de (
    }

    if (parenteses != 0) return 0;

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso correto: %s in.txt out.txt\n", argv[0]);
        return 1;
    }

    FILE *entrada = fopen(argv[1], "r");
    FILE *saida = fopen(argv[2], "w");

    if (!entrada || !saida) {
        printf("Erro ao abrir %s ou %s\n", argv[1], argv[2]);
        return 1;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), entrada)) {
        linha[strcspn(linha, "\n")] = '\0';  // remover quebra de linha

        int s = tamanho(linha);
        Token tokens[s];
        int i = 0, j = 0;

        while (linha[i] != '\0') {
            if (!isspace(linha[i]) && isdigit(linha[i])) {
                Token novo = { linha[i], NUMERO, 0 };
                tokens[j++] = novo;
            } else if (!isspace(linha[i]) && strchr("+-*/^", linha[i])) {
                Token novo;
                novo.value = linha[i];
                novo.type = OPERADOR;
                switch (linha[i]) {
                    case '+': case '-': novo.peso = 1; break;
                    case '*': case '/': novo.peso = 2; break;
                    case '^':           novo.peso = 3; break;
                }
                tokens[j++] = novo;
            } else if (!isspace(linha[i]) && strchr("()", linha[i])) {
                Token novo = { linha[i], PARENTESES, 0 };
                tokens[j++] = novo;
            }
            i++;
        }

        // ? Verificação sintática
        if (!expressaoValida(tokens, j)) {
            fprintf(saida, "Erro: sintaxe invalida\n");
            printf("Erro: sintaxe invalida\n");
            continue;
        }

        Fila filaTokens;
        initFila(&filaTokens);
        for (i = 0; i < j; i++) {
            inserir(&filaTokens, tokens[i]);
        }

        int erro = 0;
        int resultado = avaliarExpressao(&filaTokens, &erro);

        if (erro) {
            fprintf(saida, "Erro: divisao por zero\n");
            printf("Erro: divisao por zero\n");
        } else {
            fprintf(saida, "%d\n", resultado);
            printf("Resultado: %d\n", resultado);
        }
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}


#include <stdio.h>
#include "arvore_seq.h"

int main() {
    int p, q, num;

    /* lê o primeiro número e cria a árvore */
    scanf("%d", &num);
    cria_arv(num);

    /* lê os restantes números */
    while (scanf("%d", &num) != EOF) {
        p = q = 0;

        while (q < NUMNO && vno[q].used && num != vno[p].info) {
            p = q;
            if (num < vno[p].info)
                q = 2 * p + 1;
            else
                q = 2 * p + 2;
        }

        if (num == vno[p].info)
            printf("%d esta repetido\n", num);
        else if (num < vno[p].info)
            setesq(p, num);
        else
            setdir(p, num);
    }

    return 0;
}


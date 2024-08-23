#include <stdio.h>
#include <string.h>

int estado[30];
int sai[30];
int v[30][30];
int tamanho[30];
char res[30][30][30];
int res_tamanho[30];

void bfs(int a) {
    estado[a] = 1;
    for (int i = 0; i < tamanho[a]; i++) {
        int it = v[a][i];
        if (estado[it] == 0) {
            bfs(it);
        }
    }
}

int main() {
    int viz, n;

    while (scanf("%d", &n), n) {
        memset(sai, 0, sizeof(sai));
        memset(tamanho, 0, sizeof(tamanho));
        memset(res_tamanho, 0, sizeof(res_tamanho));

        for (int i = 0; i < 30; i++) {
            // Limpeza dos arrays v e res
            memset(v[i], 0, sizeof(v[i]));
            memset(res[i], 0, sizeof(res[i]));
        }

        for (int i = 1; i <= n; i++) {
            while (scanf("%d", &viz), viz) {
                v[i][tamanho[i]++] = viz;
                sai[i]++;
            }
        }

        int p, t1, t2;
        char a1[30], a2[30], a3[30];

        while (scanf("%d", &p), p) {
            memset(estado, 0, sizeof(estado));
            scanf("%d %d", &t1, &t2);

            bfs(p);

            scanf("%s %s %s", a1, a2, a3);

            for (int i = 1; i <= n; i++) {
                if (estado[i] == 0) {
                    strcpy(res[i][res_tamanho[i]++], a1);
                } else {
                    if (sai[i] < t1) {
                        strcpy(res[i][res_tamanho[i]++], a1);
                    } else if (sai[i] < t2) {
                        strcpy(res[i][res_tamanho[i]++], a2);
                    } else {
                        strcpy(res[i][res_tamanho[i]++], a3);
                    }
                }
            }
        }

        char nome[30];

        for (int i = 1; i <= n; i++) {
            scanf("%s", nome);
            printf("%s: ", nome);

            for (int j = 0; j < res_tamanho[i]; j++) {
                printf("%s ", res[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

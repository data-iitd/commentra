#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_M 1000

int main() {
    int t, m;
    int alocuente[MAX_M];
    int ind = 1;
    char op[10];
    int pos, j, cnt;

    scanf("%d %d", &t, &m);
    memset(alocuente, 0, sizeof(alocuente));

    for (int i = 0; i < t; i++) {
        scanf("%s", op);
        if (strcmp(op, "alloc") == 0) {
            int pos = 0;
            scanf("%d", &pos);
            for (j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    pos--;
                    if (pos == 0) {
                        for (int k = j - pos + 1; k <= j; k++) {
                            alocuente[k] = ind;
                        }
                        printf("%d\n", ind);
                        ind++;
                        break;
                    }
                } else {
                    pos = 0;
                }
            }
            if (j == m) {
                printf("NULL\n");
            }
        } else if (strcmp(op, "erase") == 0) {
            int pos;
            scanf("%d", &pos);
            if (pos <= 0 || pos >= ind || alocuente[pos - 1] == 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            } else {
                for (j = 0; j < m; j++) {
                    if (alocuente[j] == pos) {
                        alocuente[j] = 0;
                        break;
                    }
                }
            }
        } else if (strcmp(op, "defragment") == 0) {
            cnt = 0;
            for (j = 0; j < m; j++) {
                if (alocuente[j] != 0) {
                    alocuente[cnt++] = alocuente[j];
                }
            }
            for (j = cnt; j < m; j++) {
                alocuente[j] = 0;
            }
        }
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, m;
    scanf("%d %d", &t, &m);
    int *alocuente = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        alocuente[i] = 0;
    }
    int ind = 1;
    for (int i = 0; i < t; i++) {
        char op[10];
        scanf("%s", op);
        if (strcmp(op, "alloc") == 0) {
            int size;
            scanf("%d", &size);
            int pos = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    pos++;
                    if (pos == size) {
                        for (int k = j - size + 1; k <= j; k++) {
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
            if (pos!= size) {
                printf("NULL\n");
            }
        }
        if (strcmp(op, "erase") == 0) {
            int num;
            scanf("%d", &num);
            if (num <= 0 || num > m || alocuente[num - 1] == 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            } else {
                alocuente[num - 1] = 0;
            }
        }
        if (strcmp(op, "defragment") == 0) {
            int cnt = 0;
            cnt = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;
                }
            }
            int *temp = (int *)malloc((m - cnt) * sizeof(int));
            int k = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j]!= 0) {
                    temp[k] = alocuente[j];
                    k++;
                }
            }
            for (int j = 0; j < cnt; j++) {
                temp[k] = 0;
                k++;
            }
            for (int j = 0; j < m; j++) {
                alocuente[j] = temp[j];
            }
            free(temp);
        }
    }
    free(alocuente);
    return 0;
}

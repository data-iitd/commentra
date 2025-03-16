#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1000

int main() {
    int t, m;
    int alocuente[MAX_MEMORY];
    memset(alocuente, 0, sizeof(alocuente));

    scanf("%d %d", &t, &m);

    for (int i = 0; i < t; i++) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "alloc") == 0) {
            int pos = 0;
            int size;
            scanf("%d", &size);
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    pos++;
                    if (pos == size) {
                        for (int k = j - size + 1; k <= j; k++) {
                            alocuente[k] = 1;
                        }
                        printf("%d\n", j - size + 1);
                        break;
                    }
                } else {
                    pos = 0;
                }
            }
            if (pos != size) {
                printf("NULL\n");
            }
        } else if (strcmp(op, "erase") == 0) {
            int index;
            scanf("%d", &index);
            if (index < 0 || index >= m || alocuente[index] == 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            } else {
                alocuente[index] = 0;
            }
        } else if (strcmp(op, "defragment") == 0) {
            int j = 0;
            int *new_alocuente = (int *)malloc(m * sizeof(int));
            memset(new_alocuente, 0, m * sizeof(int));
            for (int k = 0; k < m; k++) {
                if (alocuente[k] != 0) {
                    new_alocuente[j++] = alocuente[k];
                }
            }
            memcpy(alocuente, new_alocuente, m * sizeof(int));
            free(new_alocuente);
        }
    }

    return 0;
}

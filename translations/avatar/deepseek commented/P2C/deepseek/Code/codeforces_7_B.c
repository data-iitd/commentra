#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1000

int main() {
    int t, m;
    scanf("%d %d", &t, &m);

    int alocuente[m];
    memset(alocuente, 0, sizeof(alocuente));

    int ind = 1;

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
            if (pos != size) {
                printf("NULL\n");
            }
        } else if (strcmp(op, "erase") == 0) {
            int id;
            scanf("%d", &id);

            int found = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == id) {
                    alocuente[j] = 0;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            }
        } else if (strcmp(op, "defragment") == 0) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;
                }
            }

            int index = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] != 0) {
                    alocuente[index++] = alocuente[j];
                }
            }

            for (int j = index; j < m; j++) {
                alocuente[j] = 0;
            }
        }
    }

    return 0;
}

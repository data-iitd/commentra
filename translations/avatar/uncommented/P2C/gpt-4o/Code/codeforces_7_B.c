#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, m;
    scanf("%d %d", &t, &m);
    
    int *alocuente = (int *)calloc(m, sizeof(int));
    int ind = 1;

    for (int i = 0; i < t; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "alloc") == 0) {
            int size;
            scanf("%d", &size);
            int pos = 0;
            int found = 0;

            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    pos++;
                    if (pos == size) {
                        for (int k = j - size + 1; k <= j; k++) {
                            alocuente[k] = ind;
                        }
                        printf("%d\n", ind);
                        ind++;
                        found = 1;
                        break;
                    }
                } else {
                    pos = 0;
                }
            }

            if (!found) {
                printf("NULL\n");
            }
        }

        if (strcmp(op, "erase") == 0) {
            int id;
            scanf("%d", &id);
            int found = 0;

            if (id <= 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            } else {
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == id) {
                        alocuente[j] = 0;
                        found = 1;
                    }
                }
                if (!found) {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                }
            }
        }

        if (strcmp(op, "defragment") == 0) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;
                }
            }

            int *new_alocuente = (int *)calloc(m, sizeof(int));
            int index = 0;

            for (int j = 0; j < m; j++) {
                if (alocuente[j] != 0) {
                    new_alocuente[index++] = alocuente[j];
                }
            }

            free(alocuente);
            alocuente = new_alocuente;
            // Fill the remaining space with zeros
            for (int j = index; j < m; j++) {
                alocuente[j] = 0;
            }
        }
    }

    free(alocuente);
    return 0;
}

// <END-OF-CODE>

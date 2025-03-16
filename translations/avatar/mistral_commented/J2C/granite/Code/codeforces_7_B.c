

#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, m, n, x, d, i, j, k, len, allocIdx;
    char command[10];
    int *memory;

    scanf("%d %d", &t, &m);
    memory = (int*)malloc(m * sizeof(int));

    for (j = 0; j < t; j++) {
        scanf("%s", command);

        if (strcmp(command, "alloc") == 0) {
            scanf("%d", &n);
            len = 0;
            for (i = 0; i < m; i++) {
                if (memory[i] == 0) {
                    len++;
                } else {
                    len = 0;
                }
                if (len == n) {
                    allocIdx++;
                    for (k = i - n + 1; k <= i; k++) {
                        memory[k] = allocIdx;
                    }
                    printf("%d\n", allocIdx);
                    break;
                }
            }
            if (len!= n) {
                printf("NULL\n");
            }
        } else if (strcmp(command, "erase") == 0) {
            scanf("%d", &x);
            if (x <= 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            } else {
                int hasErased = 0;
                for (i = 0; i < m; i++) {
                    if (memory[i] == x) {
                        memory[i] = 0;
                        hasErased = 1;
                    }
                }
                if (!hasErased) {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                }
            }
        } else if (strcmp(command, "defragment") == 0) {
            d = 0;
            for (i = 0; i < m; i++) {
                if (memory[i] == 0) {
                    d++;
                }
            }
            int newSize = m - d;
            int *newMemory = (int*)malloc(newSize * sizeof(int));
            k = 0;
            for (i = 0; i < m; i++) {
                if (memory[i]!= 0) {
                    newMemory[k] = memory[i];
                    k++;
                }
            }
            free(memory);
            memory = newMemory;
        } else {
            printf("h\n");
        }
    }

    free(memory);
    return 0;
}


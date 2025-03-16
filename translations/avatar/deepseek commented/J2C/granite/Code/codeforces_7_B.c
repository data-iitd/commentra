
#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, m, *memory, allocIdx, i, j, n, len, x, d;
    char command[10];
    scanf("%d %d", &t, &m);
    memory = (int*)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        memory[i] = 0;
    }
    allocIdx = 0;
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
                    for (i = i - n + 1; i <= i; i++) {
                        memory[i] = allocIdx;
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
                if (hasErased == 0) {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                }
            }
        } else if (strcmp(command, "defragment") == 0) {
            d = 0;
            for (i = 0; i < m; i++) {
                if (memory[i] == 0) {
                    d++;
                } else {
                    memory[i - d] = memory[i];
                }
            }
            for (i = m - d; i < m; i++) {
                memory[i] = 0;
            }
        } else {
            printf("h\n");
        }
    }
    free(memory);
    return 0;
}

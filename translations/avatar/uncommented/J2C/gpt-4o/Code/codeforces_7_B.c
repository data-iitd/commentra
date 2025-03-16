#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int t, m;
    scanf("%d %d", &t, &m);
    
    int *memory = (int *)calloc(m, sizeof(int));
    int allocIdx = 0;

    for (int j = 0; j < t; j++) {
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "alloc") == 0) {
            int n;
            scanf("%d", &n);
            int len = 0;
            bool canAlloc = false;
            int startIdx = 0;

            for (int i = 0; i < m; i++) {
                if (memory[i] == 0) {
                    len++;
                } else {
                    len = 0;
                }
                if (len == n) {
                    canAlloc = true;
                    startIdx = i - n + 1;
                    break;
                }
            }

            if (canAlloc) {
                allocIdx++;
                for (int i = startIdx; i < startIdx + n; i++) {
                    memory[i] = allocIdx;
                }
                printf("%d\n", allocIdx);
            } else {
                printf("NULL\n");
            }
        } else if (strcmp(command, "erase") == 0) {
            int x;
            scanf("%d", &x);
            if (x <= 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
                continue;
            }
            bool hasErased = false;
            for (int i = 0; i < m; i++) {
                if (memory[i] == x) {
                    memory[i] = 0;
                    hasErased = true;
                }
            }
            if (!hasErased) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            }
        } else if (strcmp(command, "defragment") == 0) {
            int d = 0;
            for (int i = 0; i < m; i++) {
                if (memory[i] == 0) {
                    d++;
                } else {
                    memory[i - d] = memory[i];
                }
            }
            for (int i = m - d; i < m; i++) {
                memory[i] = 0;
            }
        } else {
            printf("h\n");
        }
    }

    free(memory);
    return 0;
}

// <END-OF-CODE>

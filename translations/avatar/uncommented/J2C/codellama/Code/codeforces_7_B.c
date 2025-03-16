#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_MEMORY 1000000

int main(int argc, char *argv[]) {
    int t, m, n, x, len, allocIdx, i, j;
    int *memory;
    char *command;
    bool canAlloc;
    bool hasErased;

    scanf("%d %d", &t, &m);
    memory = (int *)malloc(sizeof(int) * m);
    allocIdx = 0;
    for (j = 0; j < t; j++) {
        scanf("%s", command);
        switch (command[0]) {
            case 'a':
                scanf("%d", &n);
                len = 0;
                canAlloc = false;
                for (i = 0; i < m; i++) {
                    if (memory[i] == 0)
                        len++;
                    else
                        len = 0;
                    if (len == n) {
                        canAlloc = true;
                        len = i - n + 1;
                        break;
                    }
                }
                if (canAlloc) {
                    allocIdx++;
                    for (i = len; i < len + n; i++)
                        memory[i] = allocIdx;
                    printf("%d\n", allocIdx);
                } else
                    printf("NULL\n");
                break;
            case 'e':
                scanf("%d", &x);
                if (x <= 0) {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                    break;
                }
                hasErased = false;
                for (i = 0; i < m; i++) {
                    if (memory[i] == x) {
                        memory[i] = 0;
                        hasErased = true;
                    }
                }
                if (!hasErased)
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                break;
            case 'd':
                d = 0;
                for (i = 0; i < m; i++) {
                    if (memory[i] == 0)
                        d++;
                    else
                        memory[i - d] = memory[i];
                }
                for (i = m - d; i < m; i++)
                    memory[i] = 0;
                break;
            default:
                printf("h\n");
                break;
        }
    }
    free(memory);
    return 0;
}

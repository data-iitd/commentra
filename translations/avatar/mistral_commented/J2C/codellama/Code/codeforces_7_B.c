
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int t, m, n, len, i, j, x, d, k;
    int *memory;
    char command[10];
    scanf("%d %d", &t, &m);
    memory = (int *)malloc(m * sizeof(int));
    for (j = 0; j < t; j++) {
        scanf("%s", command);
        switch (command[0]) {
            case 'a':
                scanf("%d", &n);
                len = 0;
                for (i = 0; i < m; i++) {
                    if (memory[i] == 0) {
                        len++;
                    } else {
                        len = 0;
                    }
                    if (len == n) {
                        for (k = i - n + 1; k < i; k++) {
                            memory[k] = j + 1;
                        }
                        printf("%d\n", j + 1);
                        break;
                    }
                }
                if (len != n) {
                    printf("NULL\n");
                }
                break;
            case 'e':
                scanf("%d", &x);
                if (x <= 0) {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                    break;
                }
                for (i = 0; i < m; i++) {
                    if (memory[i] == x) {
                        memory[i] = 0;
                        break;
                    }
                }
                if (i == m) {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                }
                break;
            case 'd':
                d = 0;
                for (i = 0; i < m; i++) {
                    if (memory[i] == 0) {
                        d++;
                    }
                }
                newSize = m - d;
                newMemory = (int *)malloc(newSize * sizeof(int));
                k = 0;
                for (i = 0; i < m; i++) {
                    if (memory[i] != 0) {
                        newMemory[k] = memory[i];
                        k++;
                    }
                }
                memory = newMemory;
                break;
            default:
                printf("h\n");
                break;
        }
    }
    free(memory);
    return 0;
}


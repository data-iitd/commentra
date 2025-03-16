#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int t, m, n, len, i, j, x, d, allocIdx;
    char command[10];
    int *memory;
    memory = (int *)malloc(m * sizeof(int));
    scanf("%d %d", &t, &m);
    allocIdx = 0;
    for (j = 0; j < t; j++) {
        scanf("%s", command);
        switch (command[0]) {
            case 'a':
                scanf("%d", &n);
                len = 0;
                for (i = 0; i < m; i++) {
                    if (memory[i] == 0) len++;
                    else len = 0;
                    if (len == n) {
                        allocIdx++;
                        for (i = i - n + 1; i < i - n + 1 + n; i++) memory[i] = allocIdx;
                        printf("%d\n", allocIdx);
                        break;
                    }
                }
                if (len != n) printf("NULL\n");
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
                if (i == m) printf("ILLEGAL_ERASE_ARGUMENT\n");
                break;
            case 'd':
                d = 0;
                for (i = 0; i < m; i++) {
                    if (memory[i] == 0) d++;
                    else memory[i - d] = memory[i];
                }
                for (i = m - d; i < m; i++) memory[i] = 0;
                break;
            default:
                printf("h\n");
                break;
        }
    }
    free(memory);
    return 0;
}

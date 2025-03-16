#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int t, m;
    scanf("%d %d", &t, &m);
    
    int memory[m];
    memset(memory, 0, sizeof(memory));
    
    int allocIdx = 0;
    
    for (int j = 0; j < t; j++) {
        char operation[10];
        scanf("%s", operation);
        
        if (strcmp(operation, "alloc") == 0) {
            int n;
            scanf("%d", &n);
            int len = 0;
            int canAlloc = 0;
            
            for (int i = 0; i < m; i++) {
                if (memory[i] == 0)
                    len++;
                else
                    len = 0;
                
                if (len == n) {
                    canAlloc = 1;
                    len = i - n + 1;
                    break;
                }
            }
            
            if (canAlloc) {
                allocIdx++;
                for (int i = len; i < len + n; i++)
                    memory[i] = allocIdx;
                printf("%d\n", allocIdx);
            } else {
                printf("NULL\n");
            }
        } else if (strcmp(operation, "erase") == 0) {
            int x;
            scanf("%d", &x);
            
            if (x <= 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
                continue;
            }
            
            int hasErased = 0;
            
            for (int i = 0; i < m; i++) {
                if (memory[i] == x) {
                    memory[i] = 0;
                    hasErased = 1;
                }
            }
            
            if (!hasErased) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            }
        } else if (strcmp(operation, "defragment") == 0) {
            int d = 0;
            
            for (int i = 0; i < m; i++) {
                if (memory[i] == 0)
                    d++;
                else
                    memory[i - d] = memory[i];
            }
            
            for (int i = m - d; i < m; i++)
                memory[i] = 0;
        } else {
            printf("h\n");
        }
    }
    
    return 0;
}

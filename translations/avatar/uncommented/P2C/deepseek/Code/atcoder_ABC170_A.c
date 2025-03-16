#include <stdio.h>

int main() {
    int a[100];
    int n = 0;
    char buffer[100];
    
    fgets(buffer, sizeof(buffer), stdin);
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        a[n++] = atoi(token);
        token = strtok(NULL, " ");
    }
    
    for (int e = 0; e < n; e++) {
        if (a[e] == 0) {
            printf("%d\n", e + 1);
            break;
        }
    }
    
    return 0;
}

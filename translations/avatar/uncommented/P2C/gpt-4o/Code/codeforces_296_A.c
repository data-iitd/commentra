#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char **m = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        m[i] = malloc(100 * sizeof(char)); // Assuming max length of each string is 99
        scanf("%s", m[i]);
    }

    int possible = 1; // true
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(m[i], m[j]) == 0) {
                count++;
            }
        }
        if (count >= n / 2 + 1) {
            possible = 0; // false
            break;
        }
    }

    printf("%s\n", possible ? "YES" : "NO");

    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}

// <END-OF-CODE>

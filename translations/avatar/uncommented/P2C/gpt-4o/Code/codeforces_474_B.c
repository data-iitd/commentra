#include <stdio.h>
#include <stdlib.h>

int main() {
    int *L = NULL;
    int size = 0;
    int r = 1;
    char buffer[1024];

    // Read the first input (not used)
    fgets(buffer, sizeof(buffer), stdin);

    // Read the second input
    fgets(buffer, sizeof(buffer), stdin);
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        int count = atoi(token);
        L = realloc(L, (size + count) * sizeof(int));
        for (int i = 0; i < count; i++) {
            L[size++] = r;
        }
        r++;
        token = strtok(NULL, " ");
    }

    // Read the third input (not used)
    fgets(buffer, sizeof(buffer), stdin);

    // Read the fourth input and print the corresponding values from L
    fgets(buffer, sizeof(buffer), stdin);
    token = strtok(buffer, " ");
    while (token != NULL) {
        int index = atoi(token) - 1; // Convert to 0-based index
        printf("%d\n", L[index]);
        token = strtok(NULL, " ");
    }

    // Free allocated memory
    free(L);
    return 0;
}

// <END-OF-CODE>

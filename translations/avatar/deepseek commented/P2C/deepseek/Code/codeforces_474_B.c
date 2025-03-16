#include <stdio.h>
#include <stdlib.h>

int main() {
    int r = 1;
    char input1[100], input2[100];
    int L[1000] = {0}; // Initialize an array to store the results with a large enough size

    // Read the first input
    fgets(input1, sizeof(input1), stdin);

    // Process the first input
    char *token = strtok(input1, " ");
    while (token != NULL) {
        for (int i = 0; i < atoi(token); i++) {
            L[r - 1] = r;
        }
        r++;
        token = strtok(NULL, " ");
    }

    // Read the second input
    fgets(input2, sizeof(input2), stdin);

    // Process the second input
    token = strtok(input2, " ");
    while (token != NULL) {
        int index = atoi(token) - 1;
        printf("%d\n", L[index]);
        token = strtok(NULL, " ");
    }

    return 0;
}

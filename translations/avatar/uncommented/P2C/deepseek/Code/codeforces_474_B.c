#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int L[1000] = {0}; // Assuming the maximum number of unique elements won't exceed 1000
    int r = 1;
    char input[1000];
    char *token;

    // Read the first input line
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    while (token != NULL) {
        int count = atoi(token);
        for (int i = 0; i < count; i++) {
            L[r - 1] = r;
        }
        r++;
        token = strtok(NULL, " ");
    }

    // Read the second input line
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    while (token != NULL) {
        int index = atoi(token) - 1;
        printf("%d\n", L[index]);
        token = strtok(NULL, " ");
    }

    return 0;
}

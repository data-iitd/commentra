#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[1024];
    
    // Read the first line (not used)
    fgets(buffer, sizeof(buffer), stdin);
    
    // Read the second line
    fgets(buffer, sizeof(buffer), stdin);
    
    // Split the line into tokens
    char *token;
    int dn[100]; // Assuming a maximum of 100 integers
    int count = 0;

    token = strtok(buffer, " ");
    while (token != NULL) {
        dn[count++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Calculate the sum of products
    int sum = 0;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            sum += dn[i] * dn[j];
        }
    }

    printf("%d\n", sum);
    return 0;
}
// <END-OF-CODE>

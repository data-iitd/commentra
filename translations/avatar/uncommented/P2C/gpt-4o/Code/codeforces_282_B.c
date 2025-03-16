#include <stdio.h>
#include <stdlib.h>

int main() {
    int firstline;
    scanf("%d", &firstline);
    
    int total = 0;
    char *memory = (char *)malloc(firstline + 1); // Allocate memory for the string
    int index = 0;

    for (int x = 0; x < firstline; x++) {
        int A, G;
        scanf("%d %d", &A, &G);
        
        if (total + A <= 500) {
            total += A;
            memory[index++] = 'A';
        } else {
            total -= G;
            memory[index++] = 'G';
        }
    }
    
    memory[index] = '\0'; // Null-terminate the string
    printf("%s\n", memory);
    
    free(memory); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    char u[100];
    int a, b;
    
    // Read the first line of input, split by spaces, and store in an array of strings
    fgets(str, sizeof(str), stdin);
    
    // Create a StringTokenizer to parse the next line of input as integers
    fgets(str, sizeof(str), stdin);
    char *token = strtok(str, " ");
    a = atoi(token);
    token = strtok(NULL, " ");
    b = atoi(token);
    
    // Read another string from the input
    fgets(u, sizeof(u), stdin);
    
    // Check if the read string is equal to the first element of the array and print accordingly
    if (strcmp(u, str) == 0) {
        printf("%d %d\n", a - 1, b);
    } else {
        printf("%d %d\n", a, b - 1);
    }
    
    return 0;
}

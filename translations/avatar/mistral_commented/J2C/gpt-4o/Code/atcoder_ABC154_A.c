#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Creating a buffer to read the first line of input
    char str[100];
    fgets(str, sizeof(str), stdin);
    
    // Creating variables to hold the integers
    int a, b;
    
    // Reading the second line of input and parsing the integers
    scanf("%d %d", &a, &b);
    
    // Creating a buffer to read the third line of input
    char u[100];
    getchar(); // To consume the newline character left by scanf
    fgets(u, sizeof(u), stdin);
    
    // Removing the newline character from the string 'u'
    u[strcspn(u, "\n")] = 0;

    // Checking if the first string from the first line matches with the given string 'u'
    if (strcmp(u, strtok(str, " ")) == 0) {
        // If the condition is true, then print the result as (a-1) and b
        printf("%d %d\n", a - 1, b);
    } else {
        // If the condition is false, then print the result as a and (b-1)
        printf("%d %d\n", a, b - 1);
    }

    return 0;
}
// <END-OF-CODE>

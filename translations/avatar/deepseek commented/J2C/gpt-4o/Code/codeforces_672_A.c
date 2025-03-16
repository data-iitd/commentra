#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This method generates a string of numbers from 1 to 1000
char* generateString() {
    // Allocate enough memory for the string
    // The maximum length of the string can be calculated as follows:
    // 1 to 9: 9 characters, 10 to 99: 180 characters, 100 to 999: 2700 characters
    // Total: 9 + 180 + 2700 = 2889 characters + 1 for null terminator
    char *str = (char *)malloc(2889 * sizeof(char));
    if (str == NULL) {
        return NULL; // Memory allocation failed
    }
    
    int index = 0;
    for (int i = 1; i <= 1000; i++) {
        index += sprintf(str + index, "%d", i);
    }
    
    return str;
}

// The main method reads an integer n from the user, and prints the nth character of the generated string
int main() {
    int n;
    scanf("%d", &n);
    
    char *generatedString = generateString();
    if (generatedString != NULL) {
        printf("%c\n", generatedString[n - 1]);
        free(generatedString); // Free the allocated memory
    }
    
    return 0;
}

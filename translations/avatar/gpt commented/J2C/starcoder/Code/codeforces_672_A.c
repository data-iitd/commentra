#include <stdio.h>
#include <stdlib.h>

// Method to generate a character array from the concatenation of numbers 1 to 1000
char* generateString() {
    char* str = (char*) malloc(sizeof(char) * 1000); // Allocating memory for the string
    
    // Looping through numbers 1 to 1000 and appending them to the string
    for (int i = 0; i < 1000; i++) {
        str[i] = (char) (i + 1); // Appending the current number to the string
    }
    
    // Returning the string
    return str;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Printing the character at the (n-1)th index of the generated character array
    printf("%c", generateString()[n - 1]);
    
    return 0;
}


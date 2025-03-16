

#include <stdio.h>
#include <string.h>

int main() {
    // Create a character array to store the first line of input
    char str[100];
    
    // Read the first line of input and store in the character array
    fgets(str, sizeof(str), stdin);
    
    // Create a character array to store the second line of input
    char u[100];
    
    // Read the second line of input and store in the character array
    fgets(u, sizeof(u), stdin);
    
    // Create a character array to store the third line of input
    char v[100];
    
    // Read the third line of input and store in the character array
    fgets(v, sizeof(v), stdin);
    
    // Create a character array to store the fourth line of input
    char w[100];
    
    // Read the fourth line of input and store in the character array
    fgets(w, sizeof(w), stdin);
    
    // Check if the read string is equal to the first element of the array and print accordingly
    if (strcmp(u, str) == 0) {
        printf("%s", v);
    } else {
        printf("%s", w);
    }
    
    return 0;
}


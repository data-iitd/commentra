#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[1000]; // Declaring a character array to store input
    fgets(a, sizeof(a), stdin); // Reading a line of input from the user
    for (int i = 0; i < strlen(a); i++) { // Looping through the input string
        if (a[i] == ',') { // Checking if the current character is a comma
            a[i] = ' '; // Replacing the comma with a space
        }
    }
    printf("%s", a); // Printing the manipulated string
    return 0;
}

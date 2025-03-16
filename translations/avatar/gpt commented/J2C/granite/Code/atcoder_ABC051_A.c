
#include <stdio.h> // Including standard input/output library
#include <string.h> // Including string manipulation library

int main() {
    // Creating a character array to store the input string
    char a[100];
    
    // Reading a line of input from the user
    fgets(a, 100, stdin);
    
    // Replacing commas in the input string with spaces
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == ',') {
            a[i] ='';
        }
    }
    
    // Printing the modified string to the console
    printf("%s", a);
    
    // Ending the program
    return 0;
}


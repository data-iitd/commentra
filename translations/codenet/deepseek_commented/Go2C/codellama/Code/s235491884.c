#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Declaring a string variable to store user input
    scanf("%s", s); // Reading input from the user and storing it in the variable s

    int n = 0; // Declaring an integer variable to store the count of "o" characters
    for (int i = 0; i < strlen(s); i++) { // Iterating over the characters in the string s
        if (s[i] == 'o') { // Checking if the current character is "o"
            n++; // Incrementing the count of "o" characters
        }
    }

    printf("%d\n", 700 + n*100); // Printing the final score based on the count of "o" characters

    return 0;
}

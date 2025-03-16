#include <stdio.h> // Including the standard input/output library

int main() {
    // Declaring a variable 's' to store the input string
    char s[100]; // Assuming a maximum length of 99 characters + 1 for null terminator

    // Reading the string input using 'scanf' function
    scanf("%s", s);

    // Declaring a variable 'ans' to store the answer
    int ans = 0;

    // Looping through each character in the string 's'
    for (int i = 0; s[i] != '\0'; i++) {
        // Checking if the current character is equal to '1'
        if (s[i] == '1') {
            // Incrementing the answer if the character is '1'
            ans++;
        }
    }

    // Printing the answer using 'printf' function
    printf("%d\n", ans);

    // End of the code
    return 0;
}

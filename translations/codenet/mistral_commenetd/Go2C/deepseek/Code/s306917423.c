#include <stdio.h>
#include <string.h>

int main() {
    // Declaring a character array 's' to store the input string
    char s[100];

    // Reading the string input using 'scanf' function
    scanf("%s", s);

    // Declaring a variable 'ans' of type 'int' to store the answer
    int ans = 0;

    // Looping through each character 'c' in the string 's'
    for (int i = 0; i < strlen(s); i++) {
        // Checking if the current character 'c' is equal to '1'
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

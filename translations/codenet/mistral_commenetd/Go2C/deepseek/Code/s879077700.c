#include <stdio.h>
#include <string.h>

int main() {
    // Declare a character array 'a' to store user input
    char a[100];

    // Read user input using scanf() function and store it in array 'a'
    scanf("%s", a);

    // Initialize a string 'ans' with value "Good"
    char ans[] = "Good";

    // Loop through each character in the string 'a' for 3 times
    for (int i = 0; i < 3; i++) {
        // Check if the current character is same as next character
        if (a[i] == a[i + 1]) {
            // Update the value of 'ans' if current and next character are same
            strcpy(ans, "Bad");
        }
    }

    // Print the final value of 'ans'
    printf("%s\n", ans);

    return 0;
}

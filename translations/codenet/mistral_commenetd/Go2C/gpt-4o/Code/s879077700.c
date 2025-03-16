#include <stdio.h>
#include <string.h>

int main() {
    // Declare a string variable 'a' to store user input
    char a[100]; // Assuming a maximum length of 99 characters + null terminator

    // Read user input using scanf() function and store it in variable 'a'
    scanf("%s", a);

    // Initialize a string variable 'ans' with value "Good"
    char ans[] = "Good";

    // Loop through each character in the string 'a' for 3 times
    for (int i = 0; i < 3; i++) {
        // Check if the current character is same as next character
        if (a[i] == a[i + 1]) {
            // Update the value of 'ans' if current and next character are same
            strcpy(ans, "Bad");
            break; // Exit the loop early if we found a match
        }
    }

    // Print the final value of 'ans'
    printf("%s\n", ans);

    return 0;
}

// <END-OF-CODE>

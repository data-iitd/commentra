
#include <stdio.h>
#include <string.h>

int main() {
    // Declare a variable to hold the input string
    char a[100];
    
    // Read input from the user and store it in variable 'a'
    scanf("%s", a);
    
    // Initialize a variable 'ans' with the default value "Good"
    char ans[] = "Good";
    
    // Loop through the first three characters of the string 'a'
    for (int i = 0; i < 3; i++) {
        // Check if the current character is the same as the next character
        if (a[i] == a[i+1]) {
            // If they are the same, set 'ans' to "Bad"
            strcpy(ans, "Bad");
        }
    }
    
    // Print the final result stored in 'ans'
    printf("%s\n", ans);
    
    // End of code
    return 0;
}

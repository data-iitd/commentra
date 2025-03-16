
#include <stdio.h> // Include the standard input/output library

int main() {
    char str[10]; // Declare a character array variable to hold user input
    int i; // Declare an integer variable to iterate through the string

    // Read a string input from the user
    scanf("%s", str);

    // Check if the characters at positions 2 and 3 are the same,
    // and if the characters at positions 4 and 5 are the same
    if (str[2] == str[3] && str[4] == str[5]) 
        printf("Yes\n"); // If both conditions are true, output "Yes"
    else 
        printf("No\n"); // If either condition is false, output "No"

    return 0; // Return 0 to indicate successful execution
}

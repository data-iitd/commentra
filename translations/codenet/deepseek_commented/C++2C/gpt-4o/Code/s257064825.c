#include <stdio.h>      // Include standard input/output library
<<<<<<< HEAD

int main() {
    char str[100];     // Declare a character array to store input string
    scanf("%s", str);  // Read input string
    long long int sum = 0; // Initialize sum variable to store the sum of digits

    for (int i = 0; str[i] != '\0'; i++) { // Iterate over each character in the string
        sum += (str[i] - '0'); // Convert character to integer and add to sum
    }

    if (sum % 9 == 0) { // Check if sum is divisible by 9
        printf("Yes\n"); // Print "Yes" if sum is divisible by 9
    } else { // Otherwise
        printf("No\n"); // Print "No"
    }

    return 0; // Return 0 to indicate successful execution
=======
#include <string.h>     // Include string manipulation library

int main() {
    char str[100];     // Declare a character array to store input
    scanf("%s", str);  // Read input string

    long long int sum = 0;  // Initialize sum variable to store the sum of digits
    for (int i = 0; i < strlen(str); i++) {  // Iterate over each character in the string
        sum += (str[i] - '0');  // Convert character to integer and add to sum
    }

    if (sum % 9 == 0) {  // Check if sum is divisible by 9
        printf("Yes\n");  // Print "Yes" if sum is divisible by 9
    } else {  // Otherwise
        printf("No\n");   // Print "No"
    }

    return 0;  // Return 0 to indicate successful execution
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>

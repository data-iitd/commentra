#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Reading input from standard input
    char arr[100001]; // Assuming a maximum length of 100000 for the input string
    fgets(arr, sizeof(arr), stdin); // Read a line
    arr[strcspn(arr, "\n")] = 0; // Remove the newline character
    int N = strlen(arr); // Store the length of the character array

    // Read the number of test cases
    int K;
    scanf("%d\n", &K); // Read the number of test cases

    // Initialize the result variable to store the final count
    int res = 0;

    // Loop to process each test case
    for (int k = 0; k < K; k++) {
        char input[3]; // To store the input string (2 characters + null terminator)
        fgets(input, sizeof(input), stdin); // Read the input string for the current test case
        input[strcspn(input, "\n")] = 0; // Remove the newline character

        int a = 0; // Counter for the first character of the input
        int b = 0; // Counter for the second character of the input

        // Iterate over the characters of the input array
        for (int i = 0; i < N; i++) {
            if (arr[i] == input[0]) // If the character matches the first character of the input
                a++;
            else if (arr[i] == input[1]) // If the character matches the second character of the input
                b++;
            else { // If the character does not match either of the input characters
                res += (a < b) ? a : b; // Add the minimum of a and b to the result
                a = b = 0; // Reset the counters
            }
        }
        res += (a < b) ? a : b; // Add the minimum of a and b to the result after the loop
    }

    // Print the final result
    printf("%d\n", res);

    return 0;
}

// <END-OF-CODE>

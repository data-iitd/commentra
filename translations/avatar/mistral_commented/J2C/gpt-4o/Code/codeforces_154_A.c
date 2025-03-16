#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char arr[100001]; // Assuming a maximum length for the input string
    fgets(arr, sizeof(arr), stdin); // Read the first line of input
    arr[strcspn(arr, "\n")] = 0; // Remove the newline character

    int N = strlen(arr); // Get the length of the character array
    int K;
    scanf("%d\n", &K); // Read the second line of input as an integer

    int res = 0; // Initialize the result variable

    for (int k = 0; k < K; k++) {
        char input[3]; // To store the input string (2 characters + null terminator)
        fgets(input, sizeof(input), stdin); // Read the input string
        input[strcspn(input, "\n")] = 0; // Remove the newline character

        int a = 0; // Counter for the first character
        int b = 0; // Counter for the second character

        for (int i = 0; i < N; i++) {
            if (arr[i] == input[0]) {
                a++; // Increment a if the character matches the first character of the input string
            } else if (arr[i] == input[1]) {
                b++; // Increment b if the character matches the second character of the input string
            } else {
                res += (a < b) ? a : b; // Add the minimum of a and b to res
                a = b = 0; // Reset a and b
            }
        }

        res += (a < b) ? a : b; // Add the minimum of a and b after the loop
    }

    printf("%d\n", res); // Print the final result
    return 0; // Return success
}

// <END-OF-CODE>

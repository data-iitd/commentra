#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char arr[100000];
    int N, K, res = 0;
    int a = 0, b = 0;
    char input[3];

    // Read the first line of input and store it in the character array
    fgets(arr, sizeof(arr), stdin);

    // Get the length of the character array
    N = strlen(arr) - 1; // Subtract 1 to remove the newline character

    // Read the number of queries K
    scanf("%d", &K);
    getchar(); // Consume the newline character after reading K

    // Loop through each query
    for (int k = 0; k < K; k++) {
        // Read the input string for the current query
        fgets(input, sizeof(input), stdin);

        // Initialize counters for characters in the input string
        a = b = 0;

        // Iterate through the character array
        for (int i = 0; i < N; i++) {
            // Count occurrences of the first character of the input string
            if (arr[i] == input[0])
                a++;
            // Count occurrences of the second character of the input string
            else if (arr[i] == input[1])
                b++;
            // If neither character is found, update the result and reset counters
            else {
                res += (a < b) ? a : b;
                a = b = 0;
            }
        }
        // Add the minimum count of the two characters to the result
        res += (a < b) ? a : b;
    }

    // Output the final result
    printf("%d\n", res);

    return 0;
}

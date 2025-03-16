#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declaring necessary variables
    char arr[1000];
    int N, K, res = 0;
    int a = 0, b = 0;
    char input[3];

    // Reading the first line of input as a character array
    fgets(arr, sizeof(arr), stdin);
    N = strlen(arr) - 1; // Calculate the length of the character array

    // Reading the second line of input as an integer
    scanf("%d", &K);

    // Loop to read K strings
    for (int k = 0; k < K; k++) {
        // Reading a string as input
        scanf("%s", input);

        // Initialize counters for the two characters
        a = 0;
        b = 0;

        // Loop through the character array
        for (int i = 0; i < N; i++) {
            if (arr[i] == input[0])
                a++; // Increment 'a' if the character matches the first character of the input string
            else if (arr[i] == input[1])
                b++; // Increment 'b' if the character matches the second character of the input string
            else {
                res += (a < b) ? a : b; // Add the minimum of 'a' and 'b' to 'res'
                a = b = 0; // Reset 'a' and 'b'
            }
        }

        res += (a < b) ? a : b; // Add the minimum of 'a' and 'b' after the loop
    }

    // Print the final result
    printf("%d\n", res);

    return 0;
}

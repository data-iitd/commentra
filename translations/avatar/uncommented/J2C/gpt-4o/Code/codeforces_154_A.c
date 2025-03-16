#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char arr[100001]; // Assuming a maximum length of 100000 for the input string
    fgets(arr, sizeof(arr), stdin);
    int N = strlen(arr) - 1; // Subtract 1 to ignore the newline character
    arr[N] = '\0'; // Null-terminate the string

    int K;
    scanf("%d\n", &K); // Read the number of queries
    int res = 0;

    for (int k = 0; k < K; k++) {
        char input[3]; // To hold the two characters and the null terminator
        fgets(input, sizeof(input), stdin);

        int a = 0, b = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == input[0]) {
                a++;
            } else if (arr[i] == input[1]) {
                b++;
            } else {
                res += (a < b) ? a : b; // Add the minimum of a and b to res
                a = b = 0; // Reset a and b
            }
        }
        res += (a < b) ? a : b; // Add the last segment's minimum to res
    }

    printf("%d\n", res);
    return 0;
}

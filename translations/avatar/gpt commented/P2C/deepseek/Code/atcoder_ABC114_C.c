#include <stdio.h>
#include <string.h>

// Define a recursive function 'aaa' that takes a string 'n'
int aaa(char *n, int N) {
    // Check if the integer value of 'n' exceeds the limit N
    if (atoi(n) > N) {
        return 0;  // If it does, return 0 (base case)
    }

    // Check if the digits of 'n' are exactly '7', '5', and '3'
    int ans = 0;
    if (strchr(n, '7') && strchr(n, '5') && strchr(n, '3')) {
        ans = 1;
    }

    // Iterate over each character in the string '753'
    for (char *p = "753"; *p != '\0'; p++) {
        // Create a new string by appending the current character to 'n'
        char new_n[10];
        strcpy(new_n, n);
        strncat(new_n, p, 1);

        // Recursively call 'aaa' with the new number 'new_n'
        ans += aaa(new_n, N);
    }

    // Return the accumulated answer
    return ans;
}

int main() {
    // Read an integer input from the user
    int N;
    scanf("%d", &N);

    // Print the result of calling 'aaa' with the initial value '0'
    printf("%d\n", aaa("0", N));

    return 0;
}

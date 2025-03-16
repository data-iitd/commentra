#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the XOR operation on a given string with a specific character
int cal(char *s, char c) {
    int n = strlen(s);  // Getting the length of the given string
    int m = n - 1;      // Initializing a variable 'm' to keep track of the index of the previous character
    int ans = 0;        // Initializing a variable 'ans' to store the result of XOR operation

    for (int i = 0; i < n; i++) {  // Looping through each character in the given string
        if (s[i] == c && (m & i) == i) { // Checking if the current character is the given character and the difference between its index and the index of the previous character is a power of 2
            ans ^= 1;            // If yes, performing XOR operation on 'ans'
        }
    }

    return ans;             // Returning the result of XOR operation
}

// Function to read input and process it
void solve() {
    int n;  // Number of test cases
    scanf("%d", &n);  // Reading the number of test cases

    for (int testCase = 1; testCase <= n; testCase++) {  // Looping through each test case
        int num;  // Length of the given string
        scanf("%d", &num); // Reading the length of the given string
        char s[100001];    // Assuming the maximum length of the string is 100000
        scanf("%s", s);    // Reading the given string

        char sb[100000]; // String to store the differences between adjacent characters
        int sbIndex = 0; // Index for the StringBuilder equivalent

        for (int i = 1; i < num; i++) { // Looping through each character except the first one in the given string
            sb[sbIndex++] = abs(s[i] - s[i - 1]) + '0'; // Appending the absolute difference between adjacent characters
        }
        sb[sbIndex] = '\0'; // Null-terminating the string

        if (num == 2) { // Checking if the given string has only two characters
            printf("%c\n", sb[0]); // If yes, printing the first character of the string
            continue; // And moving to the next test case
        }

        if (strchr(sb, '1')) { // Checking if the given string contains the character '1'
            printf("%d\n", cal(sb, '1')); // If yes, printing the result of XOR operation on the given string with character '1'
        } else {
            printf("%d\n", cal(sb, '2') * 2); // If no, performing XOR operation on the given string with character '2' and multiplying the result by 2
        }
    }
}

// Main function to start the program
int main() {
    solve(); // Call the solve function
    return 0; // Return success
}

// <END-OF-CODE>

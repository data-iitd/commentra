#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

// Define a recursive function 'aaa' that takes a string 'n'
int aaa(char *n) {
    // Convert string 'n' to an integer
    int num = atoi(n);
    
    // Check if the integer value of 'n' exceeds the limit N
    if (num > N) {
        return 0;  // If it does, return 0 (base case)
    }

    // Check if the digits of 'n' are exactly '7', '5', and '3'
    int ans = (strcmp(n, "753") == 0 || strcmp(n, "735") == 0 || strcmp(n, "573") == 0 || 
               strcmp(n, "537") == 0 || strcmp(n, "375") == 0 || strcmp(n, "357") == 0) ? 1 : 0;

    // Iterate over each character in the string '753'
    for (char *i = "753"; *i != '\0'; i++) {
        // Create a new string for the next recursive call
        char new_n[10]; // Assuming the length of n won't exceed 10 characters
        snprintf(new_n, sizeof(new_n), "%s%c", n, *i);
        // Recursively call 'aaa' with the current number 'n' concatenated with 'i'
        ans += aaa(new_n);
    }

    // Return the accumulated answer
    return ans;
}

int main() {
    // Read an integer input from the user
    scanf("%d", &N);
    
    // Print the result of calling 'aaa' with the initial value '0'
    printf("%d\n", aaa("0"));
    
    return 0;
}

// <END-OF-CODE>

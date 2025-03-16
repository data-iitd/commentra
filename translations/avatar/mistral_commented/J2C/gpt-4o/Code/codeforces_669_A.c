#include <stdio.h> // Include standard input/output library

// Main function is the entry point of the C application
int main() {
    int n; // Declare an integer variable 'n' to store the input number

    // Read the input number from the console and store it in the 'n' variable
    printf("Enter a number: ");
    scanf("%d", &n);

    // Call the 'solve' function to calculate and print the result
    solve(n);

    return 0; // Return 0 to indicate successful execution
}

// 'solve' function to calculate and print the result
void solve(int n) {
    // Calculate the result and print it to the console
    printf("%d\n", (n / 3) * 2 + (n % 3 == 0 ? 0 : 1));
}

// <END-OF-CODE>

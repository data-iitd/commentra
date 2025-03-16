#include <stdio.h> // Including the standard input-output library

int maxLeft(int n) { // Defining the maxLeft function
    return n > 2 ? n - 2 : 0; // Returning n - 2 if n is greater than 2, otherwise returning 0
}

int main() { // The main function, the entry point of the program
    int t; // Variable to store the number of test cases
    scanf("%d", &t); // Reading the number of test cases
    for (int i = 0; i < t; i++) { // Looping through each test case
        int n; // Variable to store the value of n for each test case
        scanf("%d", &n); // Reading the value of n for each test case
        printf("%d\n", maxLeft(n)); // Calling the maxLeft function and printing the result
    }
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>

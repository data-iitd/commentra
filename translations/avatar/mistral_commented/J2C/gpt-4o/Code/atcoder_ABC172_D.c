#include <stdio.h> // We include the standard input-output library

int main() { // The main function is the entry point of the program
    int n; // We declare an integer variable n to store the number of terms
    long ans = 0; // We initialize a long variable ans to 0, which will be used to store the answer

    // We read an integer n from the standard input stream using scanf
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) { // We start a for loop that iterates from 1 to n
        ans += (long)i * (n / i) * ((n / i) + 1) / 2; // In each iteration of the loop, we calculate the contribution of i to the answer and add it to the ans variable
    }

    printf("%ld\n", ans); // After the loop finishes, we print the value of ans to the standard output stream using printf

    return 0; // We return 0 to indicate that the program finished successfully
}

// <END-OF-CODE>

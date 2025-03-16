#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Reads the size of the array p from standard input

    int p[n]; // Declares an array p of size n
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]); // Populates the array p with n integers from standard input
    }

    int ans = 0; // Initializes the variable ans to 0

    for (int i = 0; i < n - 2; i++) { // Loops through the array p
        if (p[i] > p[i+1] && p[i+1] > p[i+2]) ans++; // Checks for a peak and increments ans
        if (p[i] < p[i+1] && p[i+1] < p[i+2]) ans++; // Checks for a valley and increments ans
    }

    printf("%d\n", ans); // Prints the final value of ans to standard output
    return 0; // Ends the program by returning 0
} // <END-OF-CODE>

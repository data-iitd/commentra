
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // Comment 1: Reads the size of the array p from standard input

    int p[n];
    for (int i = 0; i < n; i++) scanf("%d", &p[i]); // Comment 2: Populates the array p with n integers from standard input

    int ans = 0; // Comment 3: Initializes the variable ans to 0

    for (int i = 0; i < n - 2; i++) { // Comment 4: Loops through the array p
        if (p[i] > p[i+1] && p[i+1] > p[i+2]) ans++; // Comment 5: Checks for a peak and increments ans
        if (p[i] < p[i+1] && p[i+1] < p[i+2]) ans++; // Comment 6: Checks for a valley and increments ans
    }

    printf("%d\n", ans); // Comment 7: Prints the final value of ans to standard output
    return 0; // Comment 8: Ends the program by returning 0
}


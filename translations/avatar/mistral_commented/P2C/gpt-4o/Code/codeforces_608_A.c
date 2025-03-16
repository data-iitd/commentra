#include <stdio.h>

int main() {
    // Reading the number of test cases and the target sum
    int n, s;
    scanf("%d %d", &n, &s);

    // Initializing a variable c to 0
    int c = 0;

    // Iterating through the test cases
    for (int i = 0; i < n; i++) {
        // Reading the start and end time of each activity
        int f, t;
        scanf("%d %d", &f, &t);
        
        // Calculating the difference
        int x = t - (s - f);
        
        // Updating the variable c with the maximum value of x
        if (x > c) {
            c = x;
        }
    }

    // Printing the final answer
    printf("%d\n", s + c);

    return 0;
}

// <END-OF-CODE>

// Include required libraries
#include <stdio.h>

// Constants declaration with initializing size of the memory array
#define SIZE 100001

// Function definition for main function
int main() {
    // Variable declaration for number of queries and time interval
    int n, t;

    // Initializing memory array with zero values
    int mem[SIZE] = {0};

    // Reading input values for number of queries and time interval
    scanf("%d", &n);
    scanf("%d", &t);

    // Variable declaration for start and end time intervals
    int l, r;

    // Iterating through each query in the input
    for (int i = 0; i < n; i++) {
        // Reading input values for start and end time intervals
        scanf("%d", &l);
        scanf("%d", &r);

        // Updating memory array values for start and end time intervals
        mem[l] += 1;
        mem[r] -= 1;
    }

    // Initializing variable for answer
    int ans = mem[0];

    // Iterating through each time interval in the memory array
    for (int i = 1; i <= t; i++) {
        // Updating memory array values by adding previous value
        mem[i] += mem[i - 1];

        // Updating answer if current memory array value is greater than previous answer
        if (ans < mem[i]) {
            ans = mem[i];
        }
    }

    // Printing the final answer
    printf("%d\n", ans);

    // End of code
    return 0;
}
// <END-OF-CODE>


// C code translation of the given Go code
#include <stdio.h>

// Constants declaration with initializing size of the memory slice
#define size 100001

int main() {
    // Variable declaration and initialization for number of queries and time interval
    int n, t;

    // Initializing memory slice with zero values
    int mem[size] = {0};

    // Reading input values for number of queries and time interval
    scanf("%d", &n);
    scanf("%d", &t);

    // Iterating through each query in the input
    for (int i = 0; i < n; i++) {
        // Reading input values for start and end time intervals
        int l, r;
        scanf("%d", &l);
        scanf("%d", &r);

        // Updating memory slice values for start and end time intervals
        mem[l] += 1;
        mem[r] -= 1;
    }

    // Initializing variable for answer
    int ans = mem[0];

    // Iterating through each time interval in the memory slice
    for (int i = 1; i < t + 1; i++) {
        // Updating memory slice values by adding previous value
        mem[i] += mem[i - 1];

        // Updating answer if current memory slice value is greater than previous answer
        if (ans < mem[i]) {
            ans = mem[i];
        }
    }

    // Printing the final answer
    printf("%d\n", ans);

    // End of code
    return 0;
}


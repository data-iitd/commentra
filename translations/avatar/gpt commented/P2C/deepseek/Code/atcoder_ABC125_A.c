#include <stdio.h>

int main() {
    int a, b, t;
    int cookie = 0;
    int time = 0;

    // Read input values for 'a', 'b', and 't' from the user
    scanf("%d %d %d", &a, &b, &t);

    // Set the initial time to 'a'
    time = a;

    // Loop until the time exceeds 't + 0.5'
    while (time <= t + 0.5) {
        // Add 'b' cookies for each time interval
        cookie += b;
        // Increment the time by 'a' for the next iteration
        time += a;
    }

    // Print the total number of cookies collected
    printf("%d\n", cookie);

    return 0;
}

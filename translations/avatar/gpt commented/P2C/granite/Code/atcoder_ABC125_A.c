
#include <stdio.h>

int main() {
    float a, b, t, time, cookie;
    int i;

    // Read input values for 'a', 'b', and 't' from the user
    scanf("%f %f %f", &a, &b, &t);

    // Initialize the cookie count to zero
    cookie = 0;

    // Set the initial time to 'a'
    time = a;

    // Loop until the time exceeds 't + 0.5'
    for (i = 0; time <= t + 0.5; i++) {
        // Add 'b' cookies for each time interval
        cookie += b;
        // Increment the time by 'a' for the next iteration
        time += a;
    }

    // Print the total number of cookies collected
    printf("%.0f\n", cookie);

    return 0;
}

#include <stdio.h>

int main() {
    int a, b, t;
    // Taking three inputs from the user: a, b, and t
    scanf("%d %d %d", &a, &b, &t);
    
    int cookie = 0;
    // Initializing the cookie count to 0
    double time = a;
    // Setting the initial time to the value of a
    
    while (time <= t + 0.5) {
        // The loop continues as long as time is less than or equal to t + 0.5
        cookie += b;
        // Incrementing the cookie count by b
        time += a;
        // Incrementing the time by a
    }
    
    printf("%d\n", cookie);
    // Printing the final cookie count after the loop finishes
    
    return 0;
}
// <END-OF-CODE>

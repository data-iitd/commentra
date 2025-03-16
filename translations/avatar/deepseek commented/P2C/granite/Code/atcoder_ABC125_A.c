

#include <stdio.h>

int main() {
    int a, b, t, cookie = 0, time = 0;
    scanf("%d %d %d", &a, &b, &t);
    // Taking three inputs from the user: a, b, and t
    while (time <= t) {
        // The loop continues as long as time is less than or equal to t
        cookie += b;
        // Incrementing the cookie count by b
        time += a;
        // Incrementing the time by a
    }
    printf("%d", cookie);
    // Printing the final cookie count after the loop finishes
    return 0;
}
// 
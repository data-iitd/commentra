#include <stdio.h>

typedef long long ll;

int main() {
    // Define variables to store input coordinates
    ll x1, x2, y1, y2;

    // Read input coordinates from standard input
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

    // Calculate differences between final and initial coordinates
    const ll dx = x2 - x1, dy = y2 - y1;

    // Calculate coordinates of points to the left and above, and right and below the final point
    ll x3 = x2 - dy, y3 = y2 + dx;
    ll x4 = x1 - dy, y4 = y1 + dx;

    // Print the calculated coordinates to the standard output
    printf("%lld %lld %lld %lld\n", x3, y3, x4, y4);

    // End the program with a return statement of 0
    return 0;
}

// <END-OF-CODE>

#include <stdio.h>

typedef long long ll;

// Define constants and variables
ll ans = 0, cnt = 1;

int main() {
    // Input the value of h
    ll h;
    scanf("%lld", &h);

    // Loop to calculate the answer
    while (h != 1) {
        if (h % 2 != 0) {
            h--; // Decrement h if it is odd
        }
        h /= 2; // Divide h by 2
        cnt *= 2; // Double the count
        ans += cnt; // Increment the sum by the current count
    }

    // Output the final result
    printf("%lld\n", ans + 1);
    return 0;
}

// <END-OF-CODE>

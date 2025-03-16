

#include <stdio.h>

int main() {
    int t, s, q;
    scanf("%d %d %d", &t, &s, &q);
    // Taking three integer inputs and assigning them to variables t, s, and q

    int ans = 0;
    // Initializing the variable ans to 0

    while (s < t) {
        // Starting a while loop that continues as long as s is less than t
        s *= q;
        // Multiplying s by q
        ans += 1;
        // Incrementing ans by 1
    }

    printf("%d", ans);
    // Printing the final value of ans after the loop completes

    return 0;
}
// End of C code
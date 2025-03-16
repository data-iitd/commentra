#include <stdio.h>

typedef long long ll;

<<<<<<< HEAD
int main() {
    // Initialize variables to store the answer, maximum value, sum, minimum value, and count
    ll ans = 0, cnt = 1;
    ll h;

    // Read the input value for h
=======
// Initialize variables to store the answer, maximum value, sum, minimum value, and count
ll ans = 0, mx = 0, sum = 0, mn = 1e8, cnt = 1;

int main() {
    // Read the input value for h
    ll h;
>>>>>>> 98c87cb78a (data updated)
    scanf("%lld", &h);

    // Loop until h becomes 1
    while (h != 1) {
        // If h is odd, decrement it by 1 to make it even
        if (h % 2 != 0) h--;
        
        // Divide h by 2
        h /= 2;

        // Double the count for each iteration
        cnt *= 2;

        // Accumulate the count into the answer
        ans += cnt;
    }

    // Output the final answer incremented by 1
    printf("%lld\n", ans + 1);
    
    return 0;
}

// <END-OF-CODE>

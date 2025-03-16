#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);  // Read the integer k
    long long t = 0;  // Initialize t to 0

    for (int i = 1; i <= k; i++) {  // Loop from 1 to k
        t = (t % k) * 10 + 7;  // Update t based on the current iteration
        if (t % k == 0) {  // Check if t is divisible by k
            printf("%d\n", i);  // Print the current index if t is divisible by k
            return 0;  // Exit the program as we found the solution
        }
    }

    printf("-1\n");  // Print -1 indicating no solution was found
    return 0;
}

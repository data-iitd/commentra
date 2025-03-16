#include <stdio.h>

int reverse(int n) {
    if (n < 10) return n * 10; // If the number is a single digit, return it multiplied by 10
    int t = n, r = 0;
    while (t > 0) {
        r = (r * 10) + (t % 10); // Reverse the number
        t = t / 10;
    }
    return r;
}

int main() {
    int n, m;
    scanf("%d", &n); // Read the first integer
    scanf("%d", &m); // Read the second integer
    int t = reverse(m); // Reverse the second integer
    printf("%d\n", t + n); // Print the sum of the reversed integer and the first integer
    return 0;
}

// <END-OF-CODE>

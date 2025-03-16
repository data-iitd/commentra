#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set recursion limit equivalent is not needed in C
    // Define constants
    const long long P = 1000000007;
    const long long INF = 10000000010;

    // Read input
    char sa[20], sb[20];
    scanf("%s %s", sa, sb);

    // Convert sa to integer
    long long a = atoll(sa);

    // Convert sb to float, multiply by 100 and round
    double b_float = atof(sb) * 100 + 0.1;
    long long b = (long long)b_float;

    // Calculate and print the result
    printf("%lld\n", (a * b) / 100);

    return 0;
}

// <END-OF-CODE>

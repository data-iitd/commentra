#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INF 1e9
#define MOD 1000000007

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int lcm_list(int* nums, int size) {
    int result = nums[0];
    for (int i = 1; i < size; i++) {
        result = lcm(result, nums[i]);
    }
    return result;
}

int main() {
    int q, h, s, d;
    int n;

    // Read input
    scanf("%d %d %d %d", &q, &h, &s, &d);
    scanf("%d", &n);

    // Calculate the length of the longest segment that can be formed
    // using the given resources
    int best1L = fmin(q * 4, fmin(h * 2, s));
    int best2L = fmin(d, best1L * 2);

    // Check if n is even
    if (n % 2 == 0) {
        // If it is, print the length of the longest segment that can be formed
        // by dividing n into pairs and using the best2L length for each pair
        printf("%d\n", best2L * (n / 2));
    } else {
        // If n is odd, print the length of the longest segment that can be formed
        // by dividing n-1 into pairs and using the best2L length for each pair,
        // and adding the best1L length at the end
        printf("%d\n", best2L * (n / 2) + best1L);
    }

    return 0;
}

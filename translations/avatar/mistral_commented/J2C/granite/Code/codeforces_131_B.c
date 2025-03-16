

#include <stdio.h>

int main() {
    int n, num;
    long long cnt[21] = {0}, res = 0;

    scanf("%d", &n); // Read the number of test cases from the console

    // Read the numbers one by one and update the count array accordingly
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        cnt[num + 10]++; // Increment the count of the number
    }

    // Calculate the result using the given formula
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i]; // Calculate the sum of products of pairs of numbers with absolute difference i
    }
    res += (cnt[10] * (cnt[10] - 1)) / 2; // Calculate the sum of squares of numbers equal to 10 and add half of it

    // Print the result to the console
    printf("%lld\n", res);

    return 0;
}

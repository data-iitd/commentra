#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    int maxn = 4010;

    // Reading the number of elements in the array from the console
    scanf("%d", &n);

    // Reading the three integers representing the array elements
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // Defining an array to store the array elements
    int arr[] = {a, b, c};

    // Defining an array to store the dynamic programming values
    int dp[maxn];

    // Initializing the dynamic programming array with minimum values
    for (int i = 0; i < maxn; i++) {
        dp[i] = INT_MIN;
    }

    dp[0] = 0;

    // Filling the dynamic programming array using two nested loops
    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j < maxn; j++) {
            if (dp[j - arr[i]] != INT_MIN) {
                dp[j] = (dp[j] > dp[j - arr[i]] + 1) ? dp[j] : dp[j - arr[i]] + 1;
            }
        }
    }

    // Printing the result, which is the maximum length ending at the nth index
    printf("%d\n", dp[n]);


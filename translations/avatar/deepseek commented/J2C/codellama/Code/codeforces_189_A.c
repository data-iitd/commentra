
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Initialize a Scanner object to read input from the user
    int n, maxn, a, b, c;
    scanf("%d", &n);
    scanf("%d", &maxn);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    // Store the coin values in an array
    int arr[3];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

    // Initialize a dp array with all elements set to Integer.MIN_VALUE
    int dp[maxn];
    for (int i = 0; i < n; i++)
    {
        dp[i] = INT_MIN;
    }

    // Set the base case where dp[0] is 0
    dp[0] = 0;

    // Iterate over the coin values and update the dp array
    for (int i = 0; i < 3; i++)
    {
        for (int j = arr[i]; j < maxn; j++)
        {
            dp[j] = max(dp[j], dp[j - arr[i]] + 1);
        }
    }

    // Print the value of dp[n]
    printf("%d\n", dp[n]);

    // 
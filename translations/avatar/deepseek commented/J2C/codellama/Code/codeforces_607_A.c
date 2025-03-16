
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, max = 0, i, j;
    int *beacon, *dp;
    scanf ("%d", &n);
    beacon = (int *) malloc (n * sizeof (int));
    dp = (int *) malloc (n * sizeof (int));
    for (i = 0; i < n; i++) {
        scanf ("%d", &beacon[i]);
    }
    if (beacon[0] != 0) dp[0] = 1;
    for (i = 1; i < n; i++) {
        if (beacon[i] != 0 && beacon[i] < i) {
            dp[i] = dp[i - beacon[i] - 1] + 1;
        } else if (beacon[i] != 0) {
            dp[i] = 1;
        } else {
            dp[i] = dp[i - 1];
        }
        max = max < dp[i] ? dp[i] : max;
    }
    printf ("%d", n - max);
    free (beacon);
    free (dp);
    return 0;
}


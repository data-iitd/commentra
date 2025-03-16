
#include <stdio.h>
#include <stdlib.h>

int main() {
    int max = 0;
    int n;
    scanf("%d", &n);
    int beacon[1000001] = {0};
    int dp[1000001] = {0};
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        beacon[a] = b;
    }
    if (beacon[0]!= 0) dp[0] = 1;
    for (int i = 1; i < 1000001; i++) {
        if (beacon[i]!= 0 && beacon[i] < i) {
            dp[i] = dp[i - beacon[i] - 1] + 1;
        } else if (beacon[i]!= 0) {
            dp[i] = 1;
        } else {
            dp[i] = dp[i - 1];
        }
        max = (max > dp[i])? max : dp[i];
    }
    printf("%d\n", n - max);
    return 0;
}
//END-OF-CODE
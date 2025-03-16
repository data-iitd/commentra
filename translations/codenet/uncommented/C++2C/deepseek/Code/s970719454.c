#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int here[100001];
int dp1[100001];
int dp2[100001];

int main() {
    int n, m;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;

        memset(here, 0, sizeof(here));
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));

        int dpflg = 0;

        for (int i = 0; i < m; i++) {
            int a;
            scanf("%d", &a);
            if (a == 0) dpflg = 1;

            here[a] = 1;
        }

        int maxi1 = 0;
        int maxi2 = 0;

        for (int i = 1; i <= n; i++) {
            if (here[i] == 1) dp1[i] = dp1[i - 1] + 1;
            if (dp1[i] > maxi1) maxi1 = dp1[i];
        }

        for (int i = 1; i <= n; i++) {
            if (here[i] == 1) dp2[i] = dp2[i - 1] + 1;
            else dp2[i] = dp1[i - 1] + 1;
            if (dp2[i] > maxi2) maxi2 = dp2[i];
        }

        if (!dpflg) {
            printf("%d\n", maxi1);
        } else {
            printf("%d\n", maxi2);
        }
    }

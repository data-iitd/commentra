#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100001

int here[MAX_SIZE];
int dp1[MAX_SIZE];
int dp2[MAX_SIZE];

int main() {
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n == 0) break;

        for (int i = 0; i < MAX_SIZE; i++) {
            here[i] = dp1[i] = dp2[i] = 0;
        }

        bool dpflg = false;

        for (int i = 0; i < m; i++) {
            int a;
            scanf("%d", &a);
            if (a == 0) dpflg = true;

            here[a] = 1;
        }

        int maxi1 = 0;
        int maxi2 = 0;

        for (int i = 1; i <= n; i++) {
            if (here[i] == 1) dp1[i] = dp1[i - 1] + 1;
            maxi1 = (dp1[i] > maxi1) ? dp1[i] : maxi1;
        }

        for (int i = 1; i <= n; i++) {
            if (here[i] == 1) dp2[i] = dp2[i - 1] + 1;
            else dp2[i] = dp1[i - 1] + 1;
            maxi2 = (dp2[i] > maxi2) ? dp2[i] : maxi2;
        }

        if (!dpflg) {
            printf("%d\n", maxi1);
        } else {
            printf("%d\n", maxi2);
        }
    }
    return 0;
}

// <END-OF-CODE>

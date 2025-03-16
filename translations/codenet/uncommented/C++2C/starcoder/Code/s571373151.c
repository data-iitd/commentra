#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int foods[m];

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        for (int j = 0; j < k; j++) {
            int temp;
            scanf("%d", &temp);
            temp--;

            foods[temp]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (foods[i] == n) {
            ans++;
        }
    }

    printf("%d\n", ans);
}


#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int foods[m];
    for (int i = 0; i < m; i++) {
        foods[i] = 0; // Initialize the array
    }

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        for (int j = 0; j < k; j++) {
            int temp;
            scanf("%d", &temp);
            temp--; // Convert to zero-based index

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
    return 0;
}

// <END-OF-CODE>


#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int lst[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lst[i]);
    }

    int lst_p[N];
    int lst_m[N];
    int lst_p_count = 0;
    int lst_m_count = 0;
    for (int i = 0; i < N; i++) {
        if (lst[i] == 0) {
            K--;
        } else if (lst[i] > 0) {
            lst_p[lst_p_count++] = lst[i];
        } else {
            lst_m[lst_m_count++] = lst[i];
        }
    }

    int p = 0;
    int m = 0;
    int x = lst_p_count;
    int y = lst_m_count - 1;
    int lastx = lst_p_count;
    int lasty = lst_m_count;

    int check(int k) {
        int ans = 100000000;  // Initialize answer with a large number
        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) {
                continue;  // Skip invalid combinations
            }
            if (j == 0) {
                p = 0;  // No positive numbers used
            } else {
                p = lst_p[j - 1];  // Get the largest positive number used
            }
            if (k - j == 0) {
                m = 0;  // No negative numbers used
            } else {
                m = lst_m[lasty - (k - j)];  // Get the largest negative number used
            }
            ans = ans < 2 * p + abs(m)? ans : 2 * p + abs(m);
            ans = ans < p + 2 * abs(m)? ans : p + 2 * abs(m);
        }
        return ans;  // Return the minimum value found
    }

    printf("%d\n", check(K));

    return 0;
}

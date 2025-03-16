#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int lst[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lst[i]);
    }

    int lst_p[N], lst_m[N];
    int p_size = 0, m_size = 0;

    for (int i = 0; i < N; i++) {
        if (lst[i] == 0) {
            K--;
        } else if (lst[i] > 0) {
            lst_p[p_size++] = lst[i];
        } else if (lst[i] < 0) {
            lst_m[m_size++] = lst[i];
        }
    }

    int p = 0, m = 0;
    int lastx = p_size;
    int lasty = m_size;

    int check(int k) {
        int ans = 1000000000;

        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) {
                continue;
            }

            if (j == 0) {
                p = 0;
            } else {
                p = lst_p[j - 1];
            }

            if (k - j == 0) {
                m = 0;
            } else {
                m = lst_m[m_size - (k - j)];
            }

            int temp_ans = 2 * p + abs(m);
            if (2 * p + abs(m) < ans) {
                ans = 2 * p + abs(m);
            }
            if (p + 2 * abs(m) < ans) {
                ans = p + 2 * abs(m);
            }
        }

        return ans;
    }

    printf("%d\n", check(K));

    return 0;
}

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
    int p_count = 0, m_count = 0;

    for (int i = 0; i < N; i++) {
        if (lst[i] == 0) {
            K--;
        } else if (lst[i] > 0) {
            lst_p[p_count++] = lst[i];
        } else if (lst[i] < 0) {
            lst_m[m_count++] = lst[i];
        }
    }

    int p = 0, m = 0;
    int x = 0, y = m_count - 1;
    int lastx = p_count;
    int lasty = m_count;

    int check(int k) {
        int ans = 1000000000;
        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) {
                continue;
            } else {
                if (j == 0) {
                    p = 0;
                } else {
                    p = lst_p[j - 1];
                }
                if (k - j == 0) {
                    m = 0;
                } else {
                    m = lst_m[lasty - (k - j)];
                }
                int temp_ans = (2 * p < abs(m)) ? 2 * p : abs(m);
                temp_ans = (temp_ans < p + 2 * abs(m)) ? temp_ans : p + 2 * abs(m);
                ans = (ans < temp_ans) ? ans : temp_ans;
            }
        }
        return ans;
    }

    printf("%d\n", check(K));

    return 0;
}

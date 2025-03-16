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

    // Separating positive and negative numbers
    for (int i = 0; i < N; i++) {
        if (lst[i] == 0) {
            K--;
        }
        if (lst[i] > 0) {
            lst_p[p_size++] = lst[i];
        } else if (lst[i] < 0) {
            lst_m[m_size++] = lst[i];
        }
    }

    // Initialization of pointers and variables
    int p = 0, m = 0;
    int x = 0, y = m_size - 1;
    int lastx = p_size;
    int lasty = m_size;

    // Function to check the minimum possible value
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
                int temp1 = 2 * p + abs(m);
                int temp2 = p + 2 * abs(m);
                if (temp1 < ans) ans = temp1;
                if (temp2 < ans) ans = temp2;
            }
        }
        return ans;
    }

    // Output the result of the check function with K as the argument
    printf("%d\n", check(K));

    return 0;
}

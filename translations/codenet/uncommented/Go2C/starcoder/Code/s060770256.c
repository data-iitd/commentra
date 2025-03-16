#include <stdio.h>

int solution(int n, int m) {
        n = n - 2;
        m = m - 2;
        if (n < 0) {
                n = 1;
        }
        if (m < 0) {
                m = 1;
        }
        return n * m;
}

int main(void) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%d", solution(n, m));
        return 0;
}


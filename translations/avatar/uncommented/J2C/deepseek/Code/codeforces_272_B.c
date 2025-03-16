#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rec(long x) {
    int answer = 0;
    for (int k = 31; k >= 0; k--) {
        if (x & (1 << k)) answer++;
    }
    return answer;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[33] = {0};
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        a[rec(num)]++;
    }
    double answer = 0;
    for (int i = 0; i < 33; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }
    printf("%ld\n", (long)answer);
    return 0;
}

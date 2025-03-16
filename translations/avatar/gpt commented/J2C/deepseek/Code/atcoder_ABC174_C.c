#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int solve() {
    int K = readInt();

    if (K % 2 == 0 || K % 5 == 0)
        return -1;

    if (K % 7 == 0)
        K /= 7;

    K *= 9;

    int ans = 1;
    int remainder = 10 % K;

    while (remainder != 1) {
        ans++;
        remainder = (remainder * 10) % K;
    }

    return ans;
}

int main() {
    int result = solve();
    printf("%d\n", result);
    return 0;
}

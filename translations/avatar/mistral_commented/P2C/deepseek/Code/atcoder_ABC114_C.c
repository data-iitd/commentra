#include <stdio.h>
#include <string.h>

int N;

int aaa(int n) {
    if (n > N) {
        return 0;
    }

    int ans = 0;
    char str[20];
    sprintf(str, "%d", n);

    if (strspn(str, "753") == strlen(str)) {
        ans = 1;
    }

    for (char c = '7'; c >= '3'; c--) {
        ans += aaa(n * 10 + (c - '0'));
    }

    return ans;
}

int main() {
    scanf("%d", &N);
    printf("%d\n", aaa(0));
    return 0;
}


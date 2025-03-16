
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    int (*aaa)(int) = &aaa;
    printf("%d\n", aaa(0));
    return 0;
}

int aaa(int n) {
    if (n > N) {
        return 0;
    }
    int ans = 1;
    if (strcmp(strcat(strcat(malloc(100), "7"), "5"), strcat(strcat(malloc(100), "3"), "7")) == 0) {
        ans = 1;
    } else {
        ans = 0;
    }
    for (int i = 0; i < 3; i++) {
        ans += aaa(n + '7' + '5' + '3'[i]);
    }
    return ans;
}


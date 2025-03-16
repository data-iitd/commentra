
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    int aaa(int n) {
        if (n > N) {
            return 0;
        }
        int ans = 1;
        if (strchr("753", n % 10)!= NULL) {
            ans += aaa(n + 7);
        }
        if (strchr("753", n % 100 / 10)!= NULL) {
            ans += aaa(n + 5);
        }
        if (strchr("753", n % 1000 / 100)!= NULL) {
            ans += aaa(n + 3);
        }
        return ans;
    }
    printf("%d", aaa(0));
    return 0;
}


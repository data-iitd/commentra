#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aaa(char *n) {
    int ans = 1;
    int i;
    for (i = 0; i < strlen(n); i++) {
        if (n[i]!= '7' && n[i]!= '5' && n[i]!= '3') {
            ans = 0;
            break;
        }
    }
    if (ans) {
        for (i = 0; i < strlen(n); i++) {
            ans += aaa(strcat(n, "7"));
            ans += aaa(strcat(n, "5"));
            ans += aaa(strcat(n, "3"));
        }
    }
    return ans;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", aaa("0"));
    return 0;
}


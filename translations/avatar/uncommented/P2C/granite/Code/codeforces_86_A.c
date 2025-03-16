
#include <stdio.h>
#include <stdlib.h>

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    int curr = r;
    int s = 0;
    while (curr) {
        s += 1;
        curr /= 10;
    }
    int first = 1;
    for (int i = 0; i < s; i++) {
        first *= 10;
    }
    int second = first / 2;
    int ans = -1;
    for (int i = l; i <= r; i++) {
        curr = i;
        char rev[100];
        int k = 0;
        while (curr) {
            rev[k++] = '0' + (9 - (curr % 10));
            curr /= 10;
        }
        rev[k] = '\0';
        int num = 0;
        for (int j = 0; j < k; j++) {
            num *= 10;
            num += rev[j] - '0';
        }
        ans = ans > num * i? ans : num * i;
    }
    printf("%d\n", ans);
    return 0;
}
//END-OF-CODE
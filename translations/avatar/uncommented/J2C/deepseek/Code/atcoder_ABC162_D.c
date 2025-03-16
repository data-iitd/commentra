#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100001];
    long long rc = 0, gc = 0, bc = 0;

    scanf("%d", &n);
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'R') {
            rc++;
        } else if (s[i] == 'G') {
            gc++;
        } else {
            bc++;
        }
    }

    long long result = rc * gc * bc;

    for (int i = 1; i <= n; i++) {
        for (int k = i + 1; k <= n; k++) {
            if ((i + k) % 2 == 0) {
                int mid = (i + k) / 2;
                if (s[i - 1] != s[k - 1] && s[k - 1] != s[mid - 1] && s[mid - 1] != s[i - 1]) {
                    result--;
                }
            }
        }
    }

    printf("%lld\n", result);

    return 0;
}

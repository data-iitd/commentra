#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    long rc = 0, gc = 0, bc = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'R') {
            rc++;
        } else if (s[i] == 'G') {
            gc++;
        } else {
            bc++;
        }
    }

    long result = rc * gc * bc;

    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if ((i + k) % 2 == 0) {
                int mid = (i + k) / 2;
                if (s[i] != s[k] && s[k] != s[mid] && s[mid] != s[i]) {
                    result--;
                }
            }
        }
    }

    printf("%ld\n", result);
    return 0;
}

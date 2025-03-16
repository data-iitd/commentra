#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    int rc = 0, gc = 0, bc = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') rc++;
        else if (s[i] == 'G') gc++;
        else bc++;
    }
    long result = rc * gc * bc;
    for (int i = 1; i <= n; i++) {
        for (int k = i + 1; k <= n; k++) {
            if ((i + k) % 2 == 0) {
                char is = s[i - 1];
                char ks = s[k - 1];
                char js = s[((i + k) / 2) - 1];
                if (is!= ks && ks!= js && js!= is) {
                    result--;
                }
            }
        }
    }
    printf("%ld\n", result);
    return 0;
}

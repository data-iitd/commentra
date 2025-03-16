#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int h, w, n, sr, sc;
    char s[100001], t[100001];
    scanf("%d %d %d", &h, &w, &n);
    scanf("%d %d", &sr, &sc);
    scanf("%s", s);
    scanf("%s", t);

    int usafe = 1, dsafe = h;
    int lsafe = 1, rsafe = w;
    int i;

    // Check vertical boundaries based on sequence 's'
    for (i = n - 1; i >= 0; i--) {
        if (s[i] == 'U') {
            usafe++;
        } else if (s[i] == 'D') {
            dsafe--;
        }
        if (usafe > dsafe) {
            printf("NO\n");
            return 0;
        }
        if (i > 0) {
            if (t[i - 1] == 'U') {
                dsafe = dsafe < h ? dsafe + 1 : dsafe;
            } else if (t[i - 1] == 'D') {
                usafe = usafe > 1 ? usafe - 1 : usafe;
            }
        }
    }

    // Check horizontal boundaries based on sequence 't'
    for (i = n - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            lsafe++;
        } else if (s[i] == 'R') {
            rsafe--;
        }
        if (lsafe > rsafe) {
            printf("NO\n");
            return 0;
        }
        if (i > 0) {
            if (t[i - 1] == 'L') {
                rsafe = rsafe < w ? rsafe + 1 : rsafe;
            } else if (t[i - 1] == 'R') {
                lsafe = lsafe > 1 ? lsafe - 1 : lsafe;
            }
        }
    }

    if (sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    int h, w, n, sr, sc;
    char s[100001], t[100001];
    scanf("%d %d %d %d %d", &h, &w, &n, &sr, &sc);
    scanf("%s %s", s, t);

    int usafe = 1, dsafe = h;
    int lsafe = 1, rsafe = w;
    int end = 0;

    // Process moves in reverse order for rows
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'U') {
            usafe++;
        } else if (s[i] == 'D') {
            dsafe--;
        }
        if (usafe > dsafe) {
            end = 1;
            break;
        }
        if (i > 0) {
            if (t[i - 1] == 'U') {
                dsafe = dsafe < h ? dsafe + 1 : h;
            } else if (t[i - 1] == 'D') {
                usafe = usafe > 1 ? usafe - 1 : 1;
            }
        }
    }

    // Process moves in reverse order for columns
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            lsafe++;
        } else if (s[i] == 'R') {
            rsafe--;
        }
        if (lsafe > rsafe) {
            end = 1;
            break;
        }
        if (i > 0) {
            if (t[i - 1] == 'L') {
                rsafe = rsafe < w ? rsafe + 1 : w;
            } else if (t[i - 1] == 'R') {
                lsafe = lsafe > 1 ? lsafe - 1 : 1;
            }
        }
    }

    // Check if the final position is safe
    if (sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

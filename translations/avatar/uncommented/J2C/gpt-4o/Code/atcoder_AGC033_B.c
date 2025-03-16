#include <stdio.h>
#include <string.h>

int main() {
    int h, w, n, sr, sc;
    scanf("%d %d %d %d %d", &h, &w, &n, &sr, &sc);
    
    char s[n + 1], t[n + 1];
    scanf("%s %s", s, t);
    
    int end = 0;
    int usafe = 1, dsafe = h;
    
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
                dsafe = (dsafe + 1 < h) ? dsafe + 1 : h;
            } else if (t[i - 1] == 'D') {
                usafe = (usafe - 1 > 1) ? usafe - 1 : 1;
            }
        }
    }
    
    int lsafe = 1, rsafe = w;
    
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
                rsafe = (rsafe + 1 < w) ? rsafe + 1 : w;
            } else if (t[i - 1] == 'R') {
                lsafe = (lsafe - 1 > 1) ? lsafe - 1 : 1;
            }
        }
    }
    
    if (sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}

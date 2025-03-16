

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, f, t, max = 0, s = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &f, &t);
        if (max < f + t) {
            max = f + t;
        }
        s += f + t;
    }
    printf("%d\n", max > s? max : s);
    return 0;
}


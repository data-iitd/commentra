
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int f, t;
        scanf("%d %d", &f, &t);
        int max = 0;
        if (max < f + t) {
            max = f + t;
        }
        printf("%d\n", max);
    }
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define MAX_N 1000000

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int w[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (w[i] == 0) {
            c += w[i] * (w[i] - 1);
        } else {
            if (-w[i] == w[i]) {
                c += w[i] * (w[i] - 1) / 2;
            } else {
                if (-w[i] < w[i]) {
                    c += w[i] * (w[i] - 1) / 2;
                } else {
                    c += w[i] * (w[i] - 1) / 2;
                }
            }
        }
    }
    printf("%d\n", c / 2);
    return 0;
}


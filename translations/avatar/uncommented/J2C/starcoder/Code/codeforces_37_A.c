#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

#define MAX_N 100000

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    int a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int max = INT_MIN;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            count = 1;
        } else if (a[i] == max) {
            count++;
        }
    }
    printf("%d %d\n", max, count);
    return 0;
}


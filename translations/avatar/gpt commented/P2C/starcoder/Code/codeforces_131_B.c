#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    int w[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (w[i] + w[j] == 0) {
                c++;
            }
        }
    }
    printf("%d", c / 2);
    return 0;
}


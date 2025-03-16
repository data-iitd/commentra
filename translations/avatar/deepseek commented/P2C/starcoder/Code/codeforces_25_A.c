
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int list[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += list[i];
    }
    if (sum == 1) {
        for (int i = 0; i < n; i++) {
            if (list[i] == 1) {
                printf("%d", i + 1);
                break;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (list[i] == 0) {
                printf("%d", i + 1);
                break;
            }
        }
    }
    printf("\n
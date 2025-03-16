#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int list1[a], list2[b];
    for (int i = 0; i < a; i++) {
        scanf("%d", &list1[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &list2[i]);
    }

    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < a; j++) {
            if (list1[j] == i) {
                found = true;
                break;
            }
        }
        if (found) {
            printf("1 ");
        } else {
            printf("2 ");
        }
    }

    return 0;
}


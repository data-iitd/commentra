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

    for (int i = 0; i < n; i++) {
        if (contains(list1, a, i + 1)) {
            printf("1 ");
        } else {
            printf("2 ");
        }
    }

    return 0;
}

bool contains(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

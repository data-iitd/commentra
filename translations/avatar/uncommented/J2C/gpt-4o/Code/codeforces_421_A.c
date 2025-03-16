#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int *list1 = (int *)malloc(a * sizeof(int));
    int *list2 = (int *)malloc(b * sizeof(int));

    for (int i = 0; i < a; i++) {
        scanf("%d", &list1[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &list2[i]);
    }

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < a; j++) {
            if (list1[j] == i + 1) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("1 ");
        } else {
            printf("2 ");
        }
    }

    free(list1);
    free(list2);
    return 0;
}

// <END-OF-CODE>

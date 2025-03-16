#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, i, j, max, min;
    printf("Enter the size of the array: ");
    scanf("%d", &a);
    int ar[a];
    printf("Enter the elements of the array: ");
    for (i = 0; i < a; i++) {
        scanf("%d", &ar[i]);
    }
    max = 0;
    min = 0;
    for (i = 0; i < a; i++) {
        if (i == 0) {
            max = ar[i + 1] - ar[i];
            min = ar[i + 1] - ar[i];
        } else if (i == a - 1) {
            max = ar[i] - ar[i - 1];
            min = ar[i] - ar[i - 1];
        } else {
            max = (ar[i + 1] - ar[i]) > (ar[i] - ar[i - 1]) ? (ar[i + 1] - ar[i]) : (ar[i] - ar[i - 1]);
            min = (ar[i + 1] - ar[i]) < (ar[i] - ar[i - 1]) ? (ar[i + 1] - ar[i]) : (ar[i] - ar[i - 1]);
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}


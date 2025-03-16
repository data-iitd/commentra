
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *a, i, max = 0;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max) {
            max = a[i];
        }
    }
    for (i = 0; i < n; i++) {
        if (a[i] % max!= 0) {
            printf("%d", max);
            break;
        }
    }
    if (i == n) {
        printf("-1");
    }
    free(a);
    return 0;
}
// This block reads the input from the user, converts each line to a list of integers,
// and sorts the list of integers

// Find the largest number that leaves a remainder when divided by any number in the list
printf("%d", max);
// This block calculates the answer and prints it


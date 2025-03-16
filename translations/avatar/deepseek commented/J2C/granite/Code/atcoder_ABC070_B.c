

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (c > b) {
        printf("0\n");
    } else if (a > d) {
        printf("0\n");
    } else if (a < c) {
        printf("%d\n", (b < d)? b : d - c);
    } else {
        int arr[4] = {a, b, c, d};
        qsort(arr, 4, sizeof(int), cmpfunc);
        printf("%d\n", arr[2] - arr[1]);
    }

    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

// Translate the given Java code to C and end with comment "
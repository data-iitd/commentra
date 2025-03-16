#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_inp() {
        int input;
        scanf("%d", &input);
        return input;
    }

    int* arr_inp() {
        int n;
        scanf("%d", &n);
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        return arr;
    }

    int* sp_inp() {
        int n;
        scanf("%d", &n);
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        return arr;
    }

    int* a;
    int n;

    // Read the entire input, split the second line into a list of integers, and sort them.
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), (int (*)(const void*, const void*))compare);

    // Print the first element of the sorted list if it is divisible by any other element in the list, otherwise print -1.
    int divisible = 0;
    for (int i = 0; i < n; i++) {
        if (a[0] % a[i] == 0) {
            divisible = 1;
            break;
        }
    }
    if (divisible) {
        printf("%d\n", a[0]);
    } else {
        printf("-1\n");
    }

    free(a);
    return 0;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

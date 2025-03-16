#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int size = 3 * n;
    int array[size];

    // Initializing the array with input values
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Sorting the array in ascending order
    qsort(array, size, sizeof(int), compare);

    int head = size - 2;
    long long res = 0;

    // Calculating the sum of the last two elements in each subarray of size n and adding it to the result
    for (int i = 0; i < n; i++) {
        res += array[head];
        head -= 2;
    }

    // Printing the result
    printf("%lld\n", res);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find the index where an element greater than 'a+b' is present
int find_right(int *arr, int n, int value) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// Function to find the index where the smallest element greater than 'max(a-b, b-a)' is present
int find_left(int *arr, int n, int value) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int n;
    scanf("%d", &n);
    int *l = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Sort the list 'l' in ascending order
    qsort(l, n, sizeof(int), compare);

    int ans = 0;

    // Iterate through each pair of indices 'i' and 'j' in the list 'l'
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = l[i];
            int b = l[j];

            // Use find_right to find the index 'right' where an element greater than 'a+b' is present
            int right = find_right(l, n, a + b);

            // Use find_left to find the index 'left' where the smallest element greater than 'max(a-b, b-a)' is present
            int left = find_left(l, n, (a > b) ? a - b : b - a);

            // Calculate the temporary answer 'tmp' based on the indices 'left' and 'right'
            int tmp = right - left;

            // Subtract one from the temporary answer 'tmp' if both 'i' and 'j' lie between 'left' and 'right'
            if (left <= i && i < right) tmp--;
            if (left <= j && j < right) tmp--;

            // Add the temporary answer 'tmp' to the final answer 'ans'
            ans += tmp;
        }
    }

    // Print the final answer 'ans' divided by three
    printf("%d\n", ans / 3);

    // Free the allocated memory
    free(l);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, *l, i, j, a, b, right, left, tmp, ans;

    // Read input values: first value is n, followed by n integers
    scanf("%d", &n);
    l = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Sort the list of integers
    qsort(l, n, sizeof(int), compare);

    // Initialize the answer variable to count valid triplets
    ans = 0;

    // Iterate through each pair of elements in the sorted list
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            a = l[i];  // First element of the pair
            b = l[j];  // Second element of the pair

            // Find the index where a + b would fit in the sorted list
            right = bisect_left(l, n, a + b);

            // Find the index where max(a - b, b - a) would fit in the sorted list
            left = bisect_right(l, n, max(a - b, b - a));

            // Calculate the number of valid third elements that can form a triplet
            tmp = max(0, right - left);

            // Adjust the count if the indices i or j are within the range of valid third elements
            if (left <= i < right) {
                tmp -= 1;  // Exclude the first element if it's counted
            }
            if (left <= j < right) {
                tmp -= 1;  // Exclude the second element if it's counted
            }

            // Add the number of valid triplets formed with the current pair (i, j)
            ans += tmp;
        }
    }

    // Since each triplet is counted three times, divide the final answer by 3
    printf("%d\n", ans / 3);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int bisect_left(int *l, int n, int x) {
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (l[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int bisect_right(int *l, int n, int x) {
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (x < l[mid]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}


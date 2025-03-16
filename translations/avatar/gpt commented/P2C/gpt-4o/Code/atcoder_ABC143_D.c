#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int bisect_left(int *arr, int size, int value) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int bisect_right(int *arr, int size, int value) {
    int left = 0, right = size;
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
    int *l = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Sort the list of integers
    qsort(l, n, sizeof(int), compare);

    // Initialize the answer variable to count valid triplets
    long long ans = 0;

    // Iterate through each pair of elements in the sorted list
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = l[i];  // First element of the pair
            int b = l[j];  // Second element of the pair
            
            // Find the index where a + b would fit in the sorted list
            int right = bisect_left(l, n, a + b);
            
            // Find the index where max(a - b, b - a) would fit in the sorted list
            int left = bisect_right(l, n, (a > b) ? (a - b) : (b - a));
            
            // Calculate the number of valid third elements that can form a triplet
            int tmp = right - left;
            if (left <= i && i < right) {
                tmp--;  // Exclude the first element if it's counted
            }
            if (left <= j && j < right) {
                tmp--;  // Exclude the second element if it's counted
            }
            
            // Add the number of valid triplets formed with the current pair (i, j)
            ans += (tmp > 0) ? tmp : 0;
        }
    }

    // Since each triplet is counted three times, divide the final answer by 3
    printf("%lld\n", ans / 3);

    free(l);
    return 0;
}

// <END-OF-CODE>

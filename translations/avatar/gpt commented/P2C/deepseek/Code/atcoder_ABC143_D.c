#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int l[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Sort the array
    qsort(l, n, sizeof(int), compare);

    int ans = 0;

    // Iterate through each pair of elements in the sorted array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = l[i];  // First element of the pair
            int b = l[j];  // Second element of the pair

            // Find the index where a + b would fit in the sorted array
            int left = 0;
            int right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (l[mid] < a + b) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            // Find the index where max(a - b, b - a) would fit in the sorted array
            int min_diff = (a > b) ? a - b : b - a;
            left = 0;
            right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (l[mid] <= min_diff) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            // Calculate the number of valid third elements that can form a triplet
            int tmp = left - right;

            // Adjust the count if the indices i or j are within the range of valid third elements
            if (right <= i && i < left) {
                tmp--;  // Exclude the first element if it's counted
            }
            if (right <= j && j < left) {
                tmp--;  // Exclude the second element if it's counted
            }

            // Add the number of valid triplets formed with the current pair (i, j)
            ans += tmp;
        }
    }

    // Since each triplet is counted three times, divide the final answer by 3
    printf("%d\n", ans / 3);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100002

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Read the elements into an array
    int *x = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    // Initialize two arrays to hold elements at even and odd indices
    int *a = (int *)malloc((n / 2 + 1) * sizeof(int));
    int *b = (int *)malloc((n / 2 + 1) * sizeof(int));
    int a_size = 0, b_size = 0;

    // Distribute elements into arrays based on their index (even or odd)
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[a_size++] = x[i];  // Append to array 'a' if index is even
        } else {
            b[b_size++] = x[i];  // Append to array 'b' if index is odd
        }
    }

    // Initialize counters for occurrences of elements in arrays 'a' and 'b'
    int cnta[MAX_SIZE] = {0};
    int cntb[MAX_SIZE] = {0};

    // Variables to track the most frequent elements in array 'a'
    int vala = 0, vala1 = 0, maxCnta = 0, maxCnta1 = 0;

    // Count occurrences of each element in array 'a'
    for (int i = 0; i < a_size; i++) {
        cnta[a[i]]++;
    }

    // Find the most frequent element in array 'a'
    for (int i = 0; i < a_size; i++) {
        if (maxCnta < cnta[a[i]]) {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
    }

    // Find the second most frequent element in array 'a'
    for (int i = 0; i < a_size; i++) {
        if (maxCnta1 < cnta[a[i]] && vala != a[i]) {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }

    // Variables to track the most frequent elements in array 'b'
    int valb = 0, valb1 = 0, maxCntb = 0, maxCntb1 = 0;

    // Count occurrences of each element in array 'b'
    for (int i = 0; i < b_size; i++) {
        cntb[b[i]]++;
    }

    // Find the most frequent element in array 'b'
    for (int i = 0; i < b_size; i++) {
        if (maxCntb < cntb[b[i]]) {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }

    // Find the second most frequent element in array 'b'
    for (int i = 0; i < b_size; i++) {
        if (maxCntb1 < cntb[b[i]] && valb != b[i]) {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }

    // Check if the most frequent elements from both arrays are different
    if (valb != vala) {
        int res = 0;
        // Count elements in 'a' that are not the most frequent element
        for (int i = 0; i < a_size; i++) {
            if (a[i] != vala) {
                res++;
            }
        }
        // Count elements in 'b' that are not the most frequent element
        for (int i = 0; i < b_size; i++) {
            if (b[i] != valb) {
                res++;
            }
        }
        // Print the total count of elements that are not the most frequent
        printf("%d\n", res);
    } else {
        // Initialize counters for elements not equal to the most frequent elements
        int resa = 0, resb = 0, resa1 = 0, resb1 = 0;

        // Count elements in 'a' that are not the most frequent and second most frequent
        for (int i = 0; i < a_size; i++) {
            if (a[i] != vala) {
                resa++;
            }
            if (a[i] != vala1) {
                resa1++;
            }
        }

        // Count elements in 'b' that are not the most frequent and second most frequent
        for (int i = 0; i < b_size; i++) {
            if (b[i] != valb) {
                resb++;
            }
            if (b[i] != valb1) {
                resb1++;
            }
        }

        // Print the minimum of the two possible results
        printf("%d\n", (resa + resb1 < resa1 + resb) ? (resa + resb1) : (resa1 + resb));
    }

    // Free allocated memory
    free(x);
    free(a);
    free(b);

    return 0;
}

// <END-OF-CODE>

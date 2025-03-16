#include <stdio.h>
#include <stdlib.h>

// Function to compare two arrays and return 1 if they are equal, otherwise 0
int are_equal(int* arr1, int* arr2, int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to generate all permutations of numbers from 1 to n
void generate_permutations(int n, int** orig, int* count) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    int index = 0;
    do {
        for (int i = 0; i < n; i++) {
            orig[index][i] = arr[i];
        }
        index++;
    } while (next_permutation(arr, arr + n));
    *count = index;
    free(arr);
}

// Function to generate the next permutation
int next_permutation(int* start, int* end) {
    if (start == end) return 0;
    int* i = end - 1;
    while (i != start && !(*i < *(i - 1))) i--;
    if (i == start) return 0;
    i--;
    int* j = end - 1;
    while (*j <= *i) j--;
    int temp = *i;
    *i = *j;
    *j = temp;
    i++;
    j = end - 1;
    while (i < j) {
        temp = *i;
        *i = *j;
        *j = temp;
        i++;
        j--;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate memory for all permutations
    int count = 1;
    int** orig = (int**)malloc(count * sizeof(int*));
    for (int i = 0; i < count; i++) {
        orig[i] = (int*)malloc(n * sizeof(int));
    }

    // Generate all permutations
    generate_permutations(n, orig, &count);

    // Read the two permutations
    int* p = (int*)malloc(n * sizeof(int));
    int* q = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    // Find the indices of p and q in the orig list
    int pn = -1, qn = -1;
    for (int i = 0; i < count; i++) {
        if (pn == -1 && are_equal(orig[i], p, n)) {
            pn = i;
        }
        if (qn == -1 && are_equal(orig[i], q, n)) {
            qn = i;
        }
    }

    // Print the absolute difference between the indices of p and q
    printf("%d\n", abs(pn - qn));

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(orig[i]);
    }
    free(orig);
    free(p);
    free(q);

    return 0;
}

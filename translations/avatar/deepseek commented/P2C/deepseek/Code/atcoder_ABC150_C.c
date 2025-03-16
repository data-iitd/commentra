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

// Function to generate all permutations of numbers from 1 to `n`
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

// Function to generate the next lexicographical permutation of an array
int next_permutation(int* start, int* end) {
    if (start == end) return 0;
    int* i = end - 1;
    while (i != start && !(i[-1] < i[0])) {
        i--;
    }
    if (i == start) return 0;
    int* j = end - 1;
    while (!(i[-1] < j[0])) {
        j--;
    }
    int temp = i[0];
    i[0] = j[0];
    j[0] = temp;
    i++;
    j = end - 1;
    while (i < j) {
        temp = i[0];
        i[0] = j[0];
        j[0] = temp;
        i++;
        j--;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);  // Take an integer input `n`

    // Allocate memory for all permutations
    int count = 1;
    int** orig = (int**)malloc(count * sizeof(int*));
    for (int i = 0; i < count; i++) {
        orig[i] = (int*)malloc(n * sizeof(int));
    }

    // Generate all permutations
    generate_permutations(n, orig, &count);

    // Take the first permutation `p`
    int* p = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // Take the second permutation `q`
    int* q = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    // Find the indices of permutations `p` and `q`
    int pn = -1, qn = -1;
    for (int i = 0; i < count; i++) {
        if (are_equal(orig[i], p, n)) {
            pn = i;
        }
        if (are_equal(orig[i], q, n)) {
            qn = i;
        }
    }

    // Calculate the absolute difference between the indices and print the result
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

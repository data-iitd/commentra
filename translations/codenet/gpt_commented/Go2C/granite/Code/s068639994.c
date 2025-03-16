
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// mainFn contains the core logic of the program
void mainFn() {
    // Read the number of elements
    int n = getInt();
    // Read the integer slice from input
    int *ls = getIntSlice(n);
    // Create a reversed copy of the original slice
    int *lsRev = (int *)malloc(n * sizeof(int));
    memcpy(lsRev, ls, n * sizeof(int));
    // Sort the original slice in ascending order
    qsort(ls, n, sizeof(int), compare);
    // Sort the reversed slice in descending order
    qsort(lsRev, n, sizeof(int), compare);

    // Initialize the answer variable
    int ans = 0;
    // Iterate through all pairs of elements in the sorted slice
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Determine the minimum and maximum of the two selected elements
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate the differences and sums needed for searching
            int x = q - p;
            int y = q + p;

            // Find the left boundary for elements greater than x
            int l = binarySearch(ls, n, x + 1);
            // Find the right boundary for elements less than y
            int r = n - binarySearch(lsRev, n, y) - 1;

            // Calculate the number of valid elements in the range
            int sum = r - l;
            // Adjust the count if the current indices are within the range
            if ((i >= l) && (i <= r)) {
                sum--;
            }
            if ((j >= l) && (j <= r)) {
                sum--;
            }
            // Ensure the sum is non-negative
            sum = max(0, sum);
            // Accumulate the result
            ans += sum;
        }
    }

    // Divide the final answer by 3 as per the problem requirements
    ans /= 3;
    // Output the result
    printf("%d\n", ans);
}

// min returns the smaller of two integers
int min(int a, int b) {
    return a < b? a : b;
}

// max returns the larger of two integers
int max(int a, int b) {
    return a > b? a : b;
}

// compare is a custom comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// binarySearch performs a binary search on the given array
int binarySearch(int *arr, int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

// getInt reads an integer from input
int getInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// getIntSlice reads a slice of integers from input
int *getIntSlice(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = getInt();
    }
    return arr;
}

// getString reads a string from input
char *getString() {
    int size = 100;
    char *str = (char *)malloc(size * sizeof(char));
    if (str == NULL) {
        return NULL;
    }

    int i = 0;
    char c = getchar();
    while (c!= '\n' && c!= EOF) {
        str[i++] = c;
        if (i >= size - 1) {
            size *= 2;
            char *newStr = (char *)realloc(str, size * sizeof(char));
            if (newStr == NULL) {
                free(str);
                return NULL;
            }
            str = newStr;
        }
        c = getchar();
    }
    str[i] = '\0';
    return str;
}

// puts writes the given arguments to the output
void puts(int a) {
    printf("%d\n", a);
}

// puts writes the given arguments to the output
void puts(char *a) {
    printf("%s\n", a);
}

// puts writes the given arguments to the output
void puts(char *a, char *b) {
    printf("%s %s\n", a, b);
}

// puts writes the given arguments to the output
void puts(int a, int b) {
    printf("%d %d\n", a, b);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c) {
    printf("%d %d %d\n", a, b, c);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d) {
    printf("%d %d %d %d\n", a, b, c, d);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e) {
    printf("%d %d %d %d %d\n", a, b, c, d, e);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f) {
    printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g) {
    printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, f, g);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h) {
    printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    printf("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    printf("%d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
    printf("%d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w, int x) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x);
}

// puts writes the given arguments to the output
void puts(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w, int x, int y) {
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d
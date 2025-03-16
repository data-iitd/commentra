#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

int main() {
    int a = readInt();
    int b = readInt();
    int c = readInt();
    int d = readInt();

    // Check the values of a, b, c, and d and print the result based on the conditions
    if (c > b) {
        printf("0\n");
    } else if (a > d) {
        printf("0\n");
    } else if (a < c) {
        printf("%d\n", (b < d ? b : d) - c);
    } else {
        int values[4] = {a, b, c, d};
        // Sort the array
        qsort(values, 4, sizeof(int), (int (*)(const void *, const void *))compare);
        printf("%d\n", values[2] - values[1]);
    }

    return 0;
}

// Comparison function for qsort
int compare(const int *a, const int *b) {
    return (*a - *b);
}

// <END-OF-CODE>

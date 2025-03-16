#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);  // Read an integer input N (not used in further calculations)

    // Read a list of integers from input and convert them to a list of integers
    int a[1000];  // Assuming the list size won't exceed 1000
    int len = 0;
    int num;
    while (scanf("%d", &num) != EOF) {
        a[len++] = num;
    }

    // Calculate the total using the XOR operation across all elements in the list 'a'
    int total = 0;
    for (int i = 0; i < len; i++) {
        total ^= a[i];
    }

    // For each element in the list 'a', compute the XOR with 'total' and print the results
    // The results are converted to strings and joined with a space for output
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i] ^ total);
    }
    printf("\n");

    return 0;
}

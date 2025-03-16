#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Read three integers from the standard input
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // Create an array to hold the integers
    int arr[] = {a, b, c};

    // Sort the array using qsort and the compare function
    qsort(arr, 3, sizeof(int), compare);

    // Print the sorted integers
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n; // Declaring an integer variable 'n' to store the number of elements in the input array

    // Reading the number of elements 'n' from the standard input stream
    scanf("%d", &n);

    int* v; // Declaring an integer array 'v' of size 100010 to store the input elements

    // Allocating memory for the integer array 'v' of size 100010
    v = (int*)malloc(100010 * sizeof(int));

    // Reading the elements of the array 'v' from the standard input stream
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int* vo = (int*)malloc(100010 * sizeof(int)); // Declaring an integer array 'vo' of size 100010 to store the count of occurrences of each unique value in the odd indexed elements of the array 'v'
    int* ve = (int*)malloc(100010 * sizeof(int)); // Declaring an integer array 've' of size 100010 to store the count of occurrences of each unique value in the even indexed elements of the array 'v'
    int* vt = (int*)malloc(100010 * sizeof(int)); // Declaring an integer array 'vt' of size 100010 to store the total count of occurrences of each unique value in the array 'v'

    // Initializing all the elements of the arrays 'vo', 've', and 'vt' to zero
    memset(vo, 0, 100010 * sizeof(int));
    memset(ve, 0, 100010 * sizeof(int));
    memset(vt, 0, 100010 * sizeof(int));

    // Counting the occurrences of each unique value in the odd indexed elements of the array 'v' and updating the 'vo' array accordingly
    for (int i = 0; i < n; i += 2) {
        int currentElement = v[i];
        vo[currentElement]++;
    }

    // Counting the occurrences of each unique value in the even indexed elements of the array 'v' and updating the 've' array accordingly
    for (int i = 1; i < n; i += 2) {
        int currentElement = v[i];
        ve[currentElement]++;
    }

    // Sorting the arrays 'vo', 've', and 'vt' in descending order
    qsort(vo, 100010, sizeof(int), compare);
    qsort(ve, 100010, sizeof(int), compare);
    qsort(vt, 100010, sizeof(int), compare);

    int ans = 0; // Declaring an integer variable 'ans' to store the answer

    // Checking if the sum of the first elements of the arrays 'vo' and 've' is equal to the first element of the array 'vt'
    if (vo[0] + ve[0] == vt[0]) {
        // Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts of the first elements of the arrays 'vo' and 've'
        ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0]);
    } else {
        // Calculating the answer as the difference between the count of the first element of the array 'vo' and the count of the first element of the array 've'
        ans = n - vo[0] - ve[0];
    }

    // Printing the answer to the standard output stream
    printf("%d\n", ans);

    free(v); // Freeing the memory allocated for the integer array 'v'
    free(vo); // Freeing the memory allocated for the integer array 'vo'
    free(ve); // Freeing the memory allocated for the integer array 've'
    free(vt); // Freeing the memory allocated for the integer array 'vt'

    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int min(int a, int b) {
    return a < b ? a : b;
}


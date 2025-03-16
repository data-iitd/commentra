#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation and other utilities
#include <string.h> // Including string library for memset function

#define MAX_SIZE 100010 // Defining a constant for the maximum size of the arrays

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Comparison function for qsort to sort in descending order
}

int main() {
    int n; // Declaring an integer variable 'n' to store the number of elements in the input array
    scanf("%d", &n); // Reading the number of elements 'n' from the standard input stream

    int v[MAX_SIZE]; // Declaring an integer array 'v' to store the input elements

    // Reading the elements of the array 'v' from the standard input stream
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int vo[MAX_SIZE] = {0}; // Declaring an integer array 'vo' to store the count of occurrences of each unique value in the odd indexed elements of the array 'v'
    int ve[MAX_SIZE] = {0}; // Declaring an integer array 've' to store the count of occurrences of each unique value in the even indexed elements of the array 'v'
    int vt[MAX_SIZE] = {0}; // Declaring an integer array 'vt' to store the total count of occurrences of each unique value in the array 'v'

    // Counting the occurrences of each unique value in the odd indexed elements of the array 'v'
    for (int i = 0; i < n; i += 2) {
        int currentElement = v[i];
        vo[currentElement]++;
    }

    // Counting the occurrences of each unique value in the even indexed elements of the array 'v'
    for (int i = 1; i < n; i += 2) {
        int currentElement = v[i];
        ve[currentElement]++;
    }

    // Sorting the arrays 'vo', 've', and 'vt' in descending order
    qsort(vo, MAX_SIZE, sizeof(int), compare);
    qsort(ve, MAX_SIZE, sizeof(int), compare);
    qsort(vt, MAX_SIZE, sizeof(int), compare);

    int ans = 0; // Declaring an integer variable 'ans' to store the answer

    // Checking if the sum of the first elements of the arrays 'vo' and 've' is equal to the first element of the array 'vt'
    if (vo[0] + ve[0] == vt[0]) {
        // Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts of the first elements of the arrays 'vo' and 've'
        ans = (n - vo[0] - ve[1] < n - vo[1] - ve[0]) ? (n - vo[0] - ve[1]) : (n - vo[1] - ve[0]);
    } else {
        // Calculating the answer as the difference between the count of the first element of the array 'vo' and the count of the first element of the array 've'
        ans = n - vo[0] - ve[0];
    }

    // Printing the answer to the standard output stream
    printf("%d\n", ans);

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>

#include <stdio.h> // Including standard input-output library
#include <limits.h> // Including limits.h for INT_MIN

int checkNo(int brr[], int n); // Function prototype for counting 1s

int main() {
    int n;
    scanf("%d", &n); // Reading the size of the array
    int arr[n]; // Declaring the array

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Reading the elements of the array
    }

    int max = INT_MIN; // Initializing max to the minimum possible integer value

    for (int i = 0; i < n; i++) { // Iterating over all possible starting points of subarrays
        for (int j = i; j < n; j++) { // Iterating over all possible ending points of subarrays
            int x = 0;
            int brr[n]; // Declaring a copy of the array

            for (int k = 0; k < n; k++) {
                brr[k] = arr[k]; // Copying the elements of arr to brr
            }

            for (int k = i; k <= j; k++) { // Flipping the elements in the current subarray
                if (brr[k] == 0) {
                    brr[k] = 1;
                } else {
                    brr[k] = 0;
                }
            }

            int count = checkNo(brr, n); // Counting the number of 1s in the modified subarray

            if (count > max) {
                max = count; // Updating max if the current count is greater
            }
        }
    }

    if (n == 1) { // Handling the special case of a single element array
        if (arr[0] == 1) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    } else {
        printf("%d\n", max); // Printing the maximum count of 1s found
    }

    return 0; // Returning 0 to indicate successful execution
}

int checkNo(int brr[], int n) { // Helper method to count the number of 1s in an array
    int val = 0;
    for (int i = 0; i < n; i++) {
        if (brr[i] == 1) {
            ++val;
        }
    }
    return val;
}

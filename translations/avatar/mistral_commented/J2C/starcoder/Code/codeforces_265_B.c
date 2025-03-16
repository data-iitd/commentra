#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Read the first integer n representing the size of the array
    int n;
    scanf("%d", &n);

    // Create an integer array arr of size n
    int *arr = (int *)malloc(n * sizeof(int));

    // Use a for loop to read n integers from the standard input and store them in the array arr
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read the next integer and store it in the current index of the array
    }

    // Initialize a variable ans with the first element of the array and add 1 to it
    int ans = arr[0] + 1;

    // Use another for loop to iterate through the remaining elements of the array arr
    for (int i = 1; i < n; i++) {
        // Calculate the absolute difference between the current and previous elements and add it to the variable ans along with 2
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }

    // Finally, print the value of ans to the standard output
    printf("%d", ans);

    return 0;
}


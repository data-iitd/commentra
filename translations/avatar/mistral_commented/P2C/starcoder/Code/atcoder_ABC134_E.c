#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search on a sorted list
int binary_search(int *arr, int key, int low, int high)
{
    // Continue searching until the subarray is not divided anymore
    while (high - low > 1)
    {
        // Calculate the middle index of the subarray
        int mid = (low + high) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key)
        {
            // If yes, update 'high' to be the new left index
            high = mid;
        }
        else
        {
            // If no, update 'low' to be the new right index
            low = mid;
        }
    }

    // Return the index where the key is located
    return high;
}

// Function to count the number of unique elements in a sorted list
int count_unique(int *arr, int N)
{
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = N;

    // Initialize a variable to store the number of unique elements
    int count = 0;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1)
    {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < arr[good - 1])
        {
            // If yes, update 'good' to be the new left index
            good = mid;
        }
        else
        {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the number of unique elements
    return good;
}

// Driver code
int main()
{
    // Read the number of elements in the list
    int N;
    scanf("%d", &N);

    // Initialize an empty list to store the elements
    int *arr = (int *)malloc(N * sizeof(int));

    // Read each element and perform binary search to find its position in the list
    for (int i = 0; i < N; i++)
    {
        // Read an element
        scanf("%d", &arr[i]);
    }

    // Print the number of unique elements in the list
    printf("%d", count_unique(arr, N));

    // Free the memory
    free(arr);

    return 0;
}


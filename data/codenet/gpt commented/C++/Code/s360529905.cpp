#include <cstdio>
#include <algorithm>
using std::sort;

int main(void)
{
    // Declare pointers for the arrays and variables for loop index and size
    int *a, *b, i, N;
    int frontHalf, backHalf;

    // Read the number of elements
    scanf("%d", &N);

    // Dynamically allocate memory for two arrays of size N
    a = new int[N];
    b = new int[N];

    // Read elements into array 'a' and copy them to array 'b'
    for(i = 0; i < N; i++)
    {
        scanf("%d", a + i); // Read element into array 'a'
        b[i] = a[i];        // Copy element from 'a' to 'b'
    }

    // Sort the array 'b' to find the median values
    sort(b, b + N);

    // Determine the two middle values (for even-sized arrays)
    frontHalf = b[N / 2 - 1]; // Value just before the median
    backHalf = b[N / 2];      // Median value

    // Free the memory allocated for array 'b'
    delete[] b;

    // Output the appropriate value based on the original array 'a'
    for(i = 0; i < N; i++)
    {
        // If the current element is less than the backHalf (median), print backHalf
        if(a[i] < backHalf)
            printf("%d\n", backHalf);
        // Otherwise, print frontHalf
        else
            printf("%d\n", frontHalf);
    }

    // Free the memory allocated for array 'a'
    delete[] a;

    return 0; // Indicate successful completion of the program
}

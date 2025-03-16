#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Read the number of elements from user input
    int N;
    scanf("%d", &N);
    
    // Read N integers from user input and store them in a list P
    int *P = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &P[i]);
    }
    
    // Call the editorial function to process the input
    editorial(N, P);
    
    // Free the memory allocated to the list P
    free(P);
    
    return 0;
}

// Function to find the length of the longest increasing subsequence
int editorial(int N, int *P)
{
    // If there is only one element, the answer is 0 (no removals needed)
    if (N == 1)
    {
        printf("0\n");
        return 0;
    }
    
    // Create an array to store the positions of elements in P
    int *a = (int *)malloc((N + 1) * sizeof(int));
    
    // Fill the array 'a' with the indices of the elements in P
    for (int i = 0; i < N; i++)
    {
        a[P[i]] = i;
    }
    
    // Initialize temporary length and maximum length variables
    int tmp = 1;
    int max_len = 1;
    
    // Iterate through the array to find the longest increasing subsequence
    for (int i = 0; i < N; i++)
    {
        if (a[i] < a[i + 1])
        {
            tmp += 1;  // Increase the temporary length if the sequence is increasing
            max_len = max(max_len, tmp);  // Update the maximum length found
        }
        else
        {
            tmp = 1;  // Reset temporary length if the sequence is not increasing
        }
    }
    
    // Calculate the answer as the total elements minus the length of the longest subsequence
    int ans = N - max_len;
    printf("%d\n", ans);
    
    // Free the memory allocated to the array a
    free(a);
    
    return 0;
}


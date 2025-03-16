
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Function to find the element at a given index in the path
int find(int *path, int n, int k)
{
    // If the index is within the bounds of the path, return the element
    if (k < n)
    {
        return path[k];
    }
    else
    {
        // Adjust the index for the loop length
        k = k - n;
        // Return the element at the adjusted index
        return path[k % n];
    }
}

// Function to detect a loop in the path
bool loop(int *path, int n)
{
    // Initialize a Hash to keep track of indices of elements in path
    int *Hash = (int *)malloc(sizeof(int) * n);
    memset(Hash, 0, sizeof(int) * n);
    
    // Initialize the index tracker to 0
    int ind = 0;
    
    // Initialize the count to 0
    int count = 0;
    
    // Initialize the current position to 1
    int x = 1;
    
    // Initialize the loop start index to -1
    int t = -1;
    
    // Initialize the flag to indicate loop detection
    bool flag = false;
    
    // Traverse the path
    for (int i = 0; i < n + 1; i++)
    {
        // Get the next element in the path
        int ne = path[x];
        
        // Check if the next element is already in the Hash
        if (Hash[ne])
        {
            // Loop detected, set flag and record the start index
            flag = true;
            t = Hash[ne];
            break;
        }
        
        // Update the Hash with the current index
        Hash[ne] = ind;
        
        // Move to the next element
        x = ne;
        
        // Increment the index tracker
        ind++;
    }
    
    // Free the Hash
    free(Hash);
    
    // Return the flag
    return flag;
}

// Main function
int main()
{
    // Read the values of N and K from input
    int N, K;
    scanf("%d %d", &N, &K);
    
    // Read the list L of integers from input
    int *L = (int *)malloc(sizeof(int) * (N + 1));
    for (int i = 0; i < N + 1; i++)
    {
        scanf("%d", &L[i]);
    }
    
    // Insert -1 at the beginning of the list L
    L[0] = -1;
    
    // Initialize the path list with the first element 1
    int *path = (int *)malloc(sizeof(int) * (N + 1));
    path[0] = 1;
    
    // Initialize the index tracker to 0
    int ind = 0;
    
    // Initialize the count to 0
    int count = 0;
    
    // Initialize the current position to 1
    int x = 1;
    
    // Initialize the loop start index to -1
    int t = -1;
    
    // Initialize the flag to indicate loop detection
    bool flag = false;
    
    // Traverse the path
    for (int i = 0; i < N + 1; i++)
    {
        // Get the next element in the path
        int ne = L[x];
        
        // Check if the next element is already in the Hash
        if (path[ne])
        {
            // Loop detected, set flag and record the start index
            flag = true;
            t = path[ne];
            break;
        }
        
        // Append the next element to the path and update index
        path[ind] = ne;
        ind++;
        
        // Move to the next element
        x = ne;
    }
    
    // Check if a loop is detected
    if (flag)
    {
        // Create a loop slice from the detected start index to the end
        int *loop = (int *)malloc(sizeof(int) * (ind - t));
        for (int i = t; i < ind; i++)
        {
            loop[i - t] = path[i];
        }
        
        // If K is within the bounds of the path length, print the K-th element
        if (K < ind)
        {
            printf("%d\n", path[K]);
        }
        else
        {
            // Adjust K for the loop length
            K = K - ind;
            K = K % (ind - t);
            // Print the K-th element of the loop
            printf("%d\n", loop[K]);
        }
        
        // Free the loop
        free(loop);
    }
    else
    {
        // If no loop, print the (K-1)-th element of the path
        printf("%d\n", path[K - 1]);
    }
    
    // Free the path
    free(path);
    free(L);
    
    // Return from main
    return 0;
}


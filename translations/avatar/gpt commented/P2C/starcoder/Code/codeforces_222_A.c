#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Read two integers n and k from input
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Read a list of n integers from input
    int* elems = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elems[i]);
    }
    
    // Define a lambda function to check if all elements in an array are the same
    int all_same(int* arr)
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i]!= arr[0])
            {
                return 0;
            }
        }
        return 1;
    }
    
    // If all elements in elems are the same, print 0 and exit
    if (all_same(elems))
    {
        printf("0\n");
        return 0;
    }
    
    // If k is 1, it's impossible to satisfy the conditions, print -1 and exit
    if (k == 1)
    {
        printf("-1\n");
        return 0;
    }
    
    // If the last k-1 elements are not the same, print -1 and exit
    if (!all_same(elems + n - k))
    {
        printf("-1\n");
        return 0;
    }
    
    // Set the target value to the last element of elems
    int target = elems[n - 1];
    
    // Create a list of elements to delete, which are the first k-1 elements
    int* to_delete = (int*)malloc(sizeof(int) * (k - 1));
    for (int i = 0; i < k - 1; i++)
    {
        to_delete[i] = elems[i];
    }
    
    // Remove elements from to_delete that are equal to the target from the end
    while (to_delete[k - 2] == target)
    {
        to_delete[k - 2] = 0;
        k--;
    }
    
    // Print the number of elements that need to be deleted
    printf("%d\n", k - 1);
    
    // Free memory
    free(elems);
    free(to_delete);
    
    return 0;
}

